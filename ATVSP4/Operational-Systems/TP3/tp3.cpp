#include <iostream>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <deque>
#include <unistd.h>

using namespace std;

// Classe Buffer
class Buffer{
public:
  // Construtor
  Buffer() : maxSize(100), itemCount(0) {}
  // Produzir itens
  void produzir(int item){
    unique_lock<mutex> lock(mutex_);

    // Verifica se o buffer está cheio
    cond_producao.wait(lock, [this](){ return itemCount < maxSize; });
    buffer_.push_back(item);
    itemCount++;

    cond_consumo.notify_one();
  }

  // Consumir itens
  int consumir(){
    unique_lock<mutex> lock(mutex_);
    // Verifica se o buffer está vazio
    cond_consumo.wait(lock, [this]()
                      { return itemCount > 0; });


    int item = buffer_.front();
    buffer_.pop_front();
    itemCount--;

    cond_producao.notify_one();

    return item;
  }

private:
  mutex mutex_;
  condition_variable cond_producao;
  condition_variable cond_consumo;

  deque<int> buffer_;
  const int maxSize;
  int itemCount;
};

// Classe produtor
class Produtor{
public:
  Produtor(Buffer &buffer, int taxaProducao) : buffer_(buffer), taxaProducaoProd(taxaProducao) {}

  void run(){
    while (true){
      int item = produzirItem();
      buffer_.produzir(item);
      itensProduzidos++;
      usleep(1000000 / taxaProducaoProd);
    }
  }
  int getItensProduzidos() { return itensProduzidos; };

private:
  Buffer &buffer_;
  int taxaProducaoProd;
  int itensProduzidos=0;

  int produzirItem(){
    static int itemCounter = 0;
    return itemCounter++;
  }
};
// Classe consumidor
class Consumidor{
public:
  Consumidor(Buffer &buffer) : buffer_(buffer), itensConsumidos(0) {}

  void run(){
    while (true){
      int item = buffer_.consumir();
      consumirItem(item);
    }
  }

  int getItensConsumidos() const{
    return itensConsumidos;
  }

private:
  Buffer &buffer_;
  int itensConsumidos;

  void consumirItem(int item){
    itensConsumidos++;
  }
};

void *produtorThread(void *arg){
  Produtor *produtor = static_cast<Produtor*>(arg);
  produtor->run();
  return nullptr;
}

void *consumidorThread(void *arg){
  Consumidor *consumidor = static_cast<Consumidor*>(arg);
  consumidor->run();
  return nullptr;
}

int main(){
  int taxaProducao = 3, tempExecucao = 10;

  Buffer buffer;
  Produtor produtor(buffer, taxaProducao);
  Consumidor consumidor(buffer);

  pthread_t Tprodutor, Tconsumidor;

  pthread_create(&Tprodutor, nullptr, produtorThread, &produtor);
  pthread_create(&Tconsumidor, nullptr, consumidorThread, &consumidor);

  int qntdeconsumo = 0, qntdeproducao = 0;

  for (int i = 0; i < tempExecucao; ++i){
    sleep(1);
    cout << "Itens produzidos" << i + 1 << ": " << produtor.getItensProduzidos() - qntdeproducao << endl;
    cout << "Itens consumidos" << i + 1 << ": " << consumidor.getItensConsumidos() - qntdeconsumo << endl;
    
    qntdeproducao = produtor.getItensProduzidos();
    qntdeconsumo = consumidor.getItensConsumidos();
  }

  pthread_cancel(Tprodutor);
  pthread_cancel(Tconsumidor);

  pthread_join(Tprodutor, nullptr);
  pthread_join(Tconsumidor, nullptr);

  return 0;
}