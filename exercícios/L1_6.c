#include <stdio.h>

int main() {
  float nota1, nota2, media;
  
  scanf("%f %f",&nota1, &nota2);
  media = (nota1 + nota2)/2;
  
  if (media >=7){
    printf("%.1f - Aprovado",media);
  }
  if (media <7&&media >=5){
    printf("%.1f - De Recuperacao", media);
  }
  if (media<5){
    printf("%.1f - Reprovado", media);
  }
  return 0;
}

