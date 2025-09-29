#include <stdio.h>
#include <math.h>

int main() {
  float a, b, x, y,p;
  scanf("%f %f",&a, &b);
  scanf("%f %f",&x, &y);
  p = 2*(x-a) + 2*(y-b);
  printf("%.2f\n", p);
  return 0;
}

