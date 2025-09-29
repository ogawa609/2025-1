#include <stdio.h>
#include <math.h>
int main (){
  char letra, letra2;
  
  scanf ("%c", &letra);
  if (letra>=97&&letra<=122){
     letra2=letra-32;
    printf("%c(%d)", letra2, letra2);
  }
  else if (letra>=65&&letra<=90){
    printf("A letra deve ser minuscula!");
  }
  else {
    printf("Nao e letra!");
  }
  return 0;
}