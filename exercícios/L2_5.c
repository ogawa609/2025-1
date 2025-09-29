#include <stdio.h>
#include <math.h>

int main() {
   float soma=0;
    int n;
    float pi;
    int i;
    scanf("%d",&n);
    for ( i = 1; i <= n; i++){
        soma= soma + (6.0/(i*i));
    }
    pi= sqrt(soma);
    printf("%.6f",pi);
    return 0;
}