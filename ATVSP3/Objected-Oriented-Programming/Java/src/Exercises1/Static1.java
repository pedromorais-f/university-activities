package Exercises1;

public class Static1 {
    public static int max3(int a, int b, int c){
        int[] arr = new int[]{a, b, c};
        int maior = a;

        for(int n : arr){
            if(n > maior)
                maior = n;
        }
        return maior;
    }

    public static double max3(double a, double b, double c){
        double[] arr = new double[]{a, b, c};
        double maior = a;

        for(double n : arr){
            if(n > maior)
                maior = n;
        }
        return maior;
    }
}
