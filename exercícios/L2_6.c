#include <stdio.h>
#include <math.h>

int main() {
int escolha; 
float i;
double soma = 0;
int d2=50.0;
scanf("%d",&escolha);
    if (escolha==1){
        for(i=1.0; i<=50; i++){
            soma = soma+(((2.0*i)-1.0)/i);
        }
        printf("%.6f", soma);
    }
    if (escolha==2){
        for(i=1; i<=50; i++){
            soma= soma+(pow(2.0,i)/d2);
            d2=d2-1.0;
        }
        printf("%.6f",soma);
    }
    if (escolha==3){
        for(i=1;i<=10;i++){
        soma += i/(i*i);
        }
        printf("%.6f",soma);
    }
    return 0;
}