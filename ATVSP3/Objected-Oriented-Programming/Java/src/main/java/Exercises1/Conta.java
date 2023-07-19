package Exercises1;

public class Conta {
        public int saldo;

        public Conta(int saldo){
            setSaldo(saldo);
        }

        public final void setSaldo(int saldo){
            if(saldo < 0){
                this.saldo = 0;
                System.out.println("Erro no valor do saldo");
            }else{
                this.saldo = saldo;
            }
        }

        public int getSaldo(){
            return this.saldo;
        }

        public void credito(int valor){
            if(valor < 0)
                System.out.println("Valor invalido");
            else{
                this.saldo += valor;
            }
        }

        public void debito(int valor){
            if(valor < 0 || this.saldo < valor)
                System.out.println("Valor invalido");
            else{
                this.saldo -= valor;
            }
        }

        @Override
        public String toString(){
            return String.format("Saldo da conta: %d", getSaldo());
        }
}
