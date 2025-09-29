#include <stdio.h>

int main() {
   int inicio;
   int fim;
    int rodada;
    int verificar;
    int divisor;
    int multiplo;
    int multiplicado;
      
    scanf("%d %d",&inicio,&fim);
    
    for(rodada=inicio+1; rodada<fim; rodada++){
        if(inicio>fim){
            break;
        }
        else{
          verificar=1;
            for(divisor=2; divisor<=rodada/2; divisor++){  
                if(rodada%divisor==0){
                    verificar=0;
                    continue;
                }
            }
            if(verificar){
                printf("%d\n ",rodada);
                multiplicado=2;
            do{
                multiplo=multiplicado*rodada;
                if(multiplo>inicio&&multiplo<fim){
                    printf("%d ",multiplo);
                    
                }
                multiplicado++;
            }
                while(multiplo<fim);
                 if (rodada*2>=fim){
                    printf("*");
                }
                
    
                }
               printf("\n"); 
                
                
            }
          
        }
    
    
    return 0;
}