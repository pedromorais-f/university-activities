package Exercises1;

public class Data {
    int dia, mes, ano;

    public Data(int dia, int mes, int ano) {
        setDia(dia);
        setMes(mes);
        setAno(ano);
    }

    public int getDia() {
        return dia;
    }

    public void setDia(int dia) {
        if(dia > 0 && dia < 32)
            this.dia = dia;
        else
            System.out.println("Error");
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        if(mes > 0 && mes < 13)
            this.mes = mes;
        else
            System.out.println("Error");
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        if(ano > 0)
            this.ano = ano;
        else
            System.out.println("Error");
    }

    @Override
    public String toString() {
        return "Data: " + dia + "/" + mes + "/" + ano;
    }

    public int calcDias(int mes){
        int dias = 0;

        for(int i = 1; i <= mes; i++){
            if(i % 2 == 0)
                dias += 30;
            else if(i == 2)
                dias += 28;
            else
                dias += 31;
        }

        return dias;
    }
}
