#include <stdio.h>
#include <math.h>
#define pi  3.141592

int main() {
  float R, A, R2;
  scanf ("%f", &R);
  A = pi * R * R;
  R2 = sqrt((A/2)/pi);
  printf ("%.2f %.2f", A, R2);
  return 0;
}

