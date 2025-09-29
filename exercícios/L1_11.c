#include <stdio.h>
#include <math.h>
int main (){
  int entrada;
  scanf("%d", &entrada);
  
   if (entrada==1){
    printf("Jan.");
  }
  else if (entrada==2){
    printf("Fev.");
  }
  else if (entrada==3){
    printf("Mar.");
  }
  else if (entrada==4){
    printf("Abr.");
  }
  else if (entrada==5){
    printf("Mai.");
  }
  else if (entrada==6){
    printf("Jun.");
  }
  else if (entrada==7){
    printf("Jul.");
  }
  else if (entrada==8){
    printf("Ago.");
  }
  else if (entrada==9){
    printf("Set.");
  }
  else if (entrada==10){
    printf("Out.");
  }
  else if (entrada==11){
    printf("Nov.");
  }
  else if (entrada==12){
    printf("Dez.");
  }
  else {
    printf("Invalido.");
  }
  return 0;
}