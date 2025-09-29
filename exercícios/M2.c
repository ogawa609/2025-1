#include <stdio.h>
int main (){
  float x, y;
  int z;
  scanf("%f", &x);
  y = x - (int)x;
  z = (int)x;
  printf("INTEIRO:%d,REAL:%.2f", z, y);
  return 0;
}