#include <stdio.h>

int main() {
   int inicio;
   int fim;
    double teste, cd;
    int ab,ef;
    int contador;
    scanf("%d %d",&inicio,&fim);
    for(contador=inicio+1;contador<fim;contador++){
        if(inicio>fim){
             
            break;
        }
         if (inicio>=1000&&fim<=9999){
        teste=contador/100.0;
        ab=(int)teste;
             cd=teste-ab;
             cd=cd*100;
             ef=cd+ab;
             if(ef*ef==contador){
              printf("%d\n",contador);
             }
        }
    }
    
    return 0;
}