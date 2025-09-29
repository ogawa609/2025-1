#include <stdio.h>

void TrocarParEImpar(int vet[], int qtd);
void ImprimirDadosDoVetor(int vet[], int qtd);

void TrocarParEImpar(int vet[], int qtd){


    int temp=0;
    for(int i=1; i<qtd;i=i+2){
        temp=vet[i-1];
        vet[i-1]=vet[i];
        vet[i]=temp;
    }
}

void ImprimirDadosDoVetor(int vet[], int qtd){

    if(qtd==1){

        printf("{%d}",vet[0]);
    }

    else{

        printf("{");

        for(int j=0;j<qtd;j++){

            if(j==qtd-1){
                printf("%d",vet[j]);
            }
            else{
            printf("%d, ",vet[j]);
            }
        }
        printf("}");

    }
}

int main(){

    int n;
    scanf("%d",&n);

    if(n<1){
        printf("{}");
        return 0;
    }

    int entradas[n];

    for(int i=0; i<n; i++){

        scanf("%d",&entradas[i]);
    }

    TrocarParEImpar(entradas, n);
    ImprimirDadosDoVetor(entradas,n);

    return 0;
}