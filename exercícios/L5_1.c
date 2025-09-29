#include<stdio.h>
#include <math.h>

double Desvio(int notas, double media );

double Desvio(int notas, double media ){

    double desvio = (notas-media)*(notas-media);

    return desvio;
}

int main(){
    
    int N;
    int umavez=1;
    int maior, menor;
    float soma=0;
    float desvio = 0;
    int acima=0;
    int reprovado=0;

    scanf("%d",&N);

    int notas[N];

    for (int i=0;i<N;i++){

        scanf("%d",&notas[i]);

        if(umavez){

            maior=notas[i];
            menor=notas[i];
            umavez=0;
        }

        if(maior<notas[i]){
            maior=notas[i];
        }
        if(menor>notas[i]){
            menor=notas[i];
        }

        soma= soma + notas[i];

        



    }

    double media = soma/N;
    desvio= sqrt(desvio/N);

    for(int p=0;p<N;p++){
        if(notas[p]>media){
            acima++;
        }

         if(notas[p]<70){

            reprovado++;
        }

            desvio= desvio + Desvio(notas[p],media);

    }

    desvio = sqrt(desvio/N);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d\n", menor,maior,media,desvio,acima,reprovado);

}