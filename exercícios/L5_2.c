#include <stdio.h>

int main(){

    int N;
    int crescente=1;
    int decrescente=1;
    int igual=1;
    int comparar;

    scanf("%d",&N);

    int notas[N];
    for(int i=0;i<N;i++){

        scanf("%d",&notas[i]);
    }

    if(N==1){

        printf("CRESCENTE&DECRESCENTE\n");
        return 0;
    }

    for(int p=0;p<N;p++){

        if(p==0){
            comparar=notas[p];
        }

        else{

            if(comparar<notas[p]){

                comparar=notas[p];
                crescente++;
            }

            else if(comparar>notas[p]){

                comparar=notas[p];
                decrescente++;
            }

            else if(comparar==notas[p]){

                comparar=notas[p];
                igual++;
            }

        }
    }

    if(crescente==N){
        printf("CRESCENTE");
    }

    else if(decrescente==N){
        printf("DECRESCENTE");
    }

    else if(igual==N){
        printf("CRESCENTE&DECRESCENTE");
    }

    else{
        printf("DESORDENADO");
    }

    return 0;
}