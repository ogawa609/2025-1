#include <stdio.h>
int main(){
  int entrada;
  int contadorPositivos=0;
  int contadorNegativos=0;
  int somaPositivos=0;
  int somaNegativos=0;
  int nada=0;
  

  
   while((scanf("%d",&entrada))==1){
    
    if(entrada>0){
      contadorPositivos++;
      somaPositivos=somaPositivos+entrada;
    }
     if(entrada<0){
      contadorNegativos++;
      somaNegativos=somaNegativos+entrada;
    }
    if(entrada==0){
      nada++;
    }
  }

  printf("%d %d %d %d",contadorNegativos,contadorPositivos,somaNegativos,somaPositivos);
  
return 0;
}
