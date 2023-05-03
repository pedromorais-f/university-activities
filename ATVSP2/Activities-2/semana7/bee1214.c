#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
    int c;
    scanf("%d", &c);

    for(int i = 0; i < c; i++) {
        int n;
        scanf("%d", &n);

        double sum = 0;
        double average;
        double *grades = malloc(n * sizeof(double));
        for(int j = 0; j < n; j++) {
            scanf("%lf",&grades[j]);
            sum += grades[j];
        }
        
        average = sum / n;

        int counter = 0;
        for(int l = 0; l < n; l++){
            if(grades[l] > average)
                counter++;
        }

        printf("%.3lf%\n",(((double) counter) / n) * 100);

        free(grades);     
    }
 
    return 0;
}