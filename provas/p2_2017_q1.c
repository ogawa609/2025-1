#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    if(n==0){
        return 0;
    }

    int vet [n];

    for(int i=0; i<n;i++){

        scanf("%d",&vet[i]);
    }

    int menor = vet[0];

    for (int j=0; j<n; j++){

        if (menor>vet[j]){
            menor=vet[j];
        }
    }
int k;
    for( k=0;k<n;k++){

        if(menor==vet[k]){
            break;
        }
    }

    printf("POS:%d",k+1);
}