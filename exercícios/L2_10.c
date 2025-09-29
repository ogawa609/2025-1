#include <stdio.h>

int main() {
   int inicio;
   int fim;
    int multiplicando;
    int tabuada;
    int resultado;
      
    scanf("%d %d",&inicio,&fim);
    for(tabuada=inicio;tabuada<=fim;tabuada++){
        multiplicando=1;
        do{
            resultado=tabuada*multiplicando;
            printf("%d x %d = %d\n",tabuada, multiplicando, resultado);
            multiplicando++;
        }
            while(multiplicando<=10);
        printf("\n");
    }
    
    
    
    return 0;
}