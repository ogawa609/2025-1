#include <stdio.h>

int main(){

    int X;
    int N;
    int marca =1;

    scanf("%d %d", &X, &N);

    int num[N];

    for(int i=0; i<N; i++){

        scanf("%d", &num[i]);
    }

    for(int j=0; j<N;j++){

        if(X==num[j]){
            printf("RESP:%d", j);
            marca=0;
            break;
        }
    }

    if(marca){
        printf("RESP:%d", N);
    }

    return 0;
}