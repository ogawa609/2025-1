#include <stdio.h>
#include <stdlib.h>
int main (){
  int a, b, c;
  int n1=1, n2=2, n3=3;
  scanf("%d %d %d", &a, &b, &c);

  if (a>b&&b>c) {
    printf("N%d = %d, N%d = %d, N%d = %d",n3,c,n2,b,n1,a);
  }
  if (a>c&&c>b) {
    printf("N%d = %d, N%d = %d, N%d = %d",n2,b,n3,c,n1,a);
  }
 if (b>a&&a>c) {
    printf("N%d = %d, N%d = %d, N%d = %d",n3,c,n1,a,n2,b);
  }
 if (b>c&&c>a) {
    printf("N%d = %d, N%d = %d, N%d = %d",n1,a,n3,c,n2,b);
  }
 if (c>a&&a>b) {
    printf("N%d = %d, N%d = %d, N%d = %d",n2,b,n1,a,n3,c);
  }
  if (c>b&&b>a) {
    printf("N%d = %d, N%d = %d, N%d = %d",n1,a,n2,b,n3,c);
  }
  return 0;
}