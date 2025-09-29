#include <stdio.h>

int main() {
    int n, i;
    int ehPrimo;

        scanf("%d", &n);
        if(n==0||n==1){
            printf("Nao primo");
        }
    else{
        ehPrimo=1;
        for(i=2;i<=n/2;i++){
            if(n%i==0){
                ehPrimo=0;
                break;
            }
        }
            if(ehPrimo){
                printf("Primo");
            }
            else{
                printf("Nao primo");
            }
        
    }
        


    return 0;
}