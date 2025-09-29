#include <stdio.h>
#include <math.h>
int main (){
  int entrada, teste;
  scanf ("%d", &entrada);
  teste = entrada % 2;
  if (teste == 0){
    printf("Par");
  }
  else if (teste != 0){
    printf("Impar");
  }
  return 0;
}