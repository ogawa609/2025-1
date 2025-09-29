#include <stdio.h>
#include <math.h>

int main() {
  float altura,largura, p;
  scanf("%f",&altura);
  scanf("%f",&largura);
  p = 2*(altura+largura);
  printf("%.2f\n", p);
  return 0;
}

