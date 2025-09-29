#include <stdio.h>
#define TRUE 1
#define FALSE 0

int EhFinalDaLista(int buraco);
int EcontraMaiorBuraco(int* buracos);
int ContaEsferasGrandes(int maiorBuraco, int *bolas);


int  EcontraMaiorBuraco(int* buracos){

    int maior= buracos[0];
    int i=0;
    while(buracos[i]!=-1){

        if(buracos[i]>maior){

            maior=buracos[i];
        }
        i++;
    }

    return maior;
}

int  ContaEsferasGrandes(int maiorBuraco, int* bolas){

    int contagem=0;
    int i=0;

   while(bolas[i]!=-1){

        if(bolas[i]>=maiorBuraco){

            contagem++;
        }

        i++;
    }

    return contagem;
    
}


int EhFinalDaLista(int buraco){

    if(buraco!=-1){

        return TRUE;
    }

    return FALSE;
}



int main(){

    int bolas[1000];
    int buracos[1000];
    int i=0;
    int j=0;

    while(1){
        scanf("%d",&buracos[i]);
        if(buracos[i]==-1){
            break;
        }
        i++;

    }

    while(1){
        scanf("%d",&bolas[j]);
        if(bolas[j]==-1){
            break;
        }
        j++;

    }

    
    int maiorburaco=EcontraMaiorBuraco(buracos);
    int bolasgrandes=ContaEsferasGrandes(maiorburaco,bolas);





    printf("QTD:%d",bolasgrandes);



return 0;
}

