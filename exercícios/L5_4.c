#include <stdio.h>

int main(){

    int N;
    int a, b;

    scanf("%d",&N);

    int nume [N];

    for(int i=0; i<N;i++){

        scanf("%d",&nume[i]);
    }

    scanf("%d %d", &a,&b);

    if(b<a){
        return 0;
    }

    int dentro = 0;
    int fora = 0;

    for(int x=0; x<N; x++){

        if(nume[x]>=a && nume[x]<=b){

            dentro++;
        }
        else{
        fora++;
        }
    }

    printf("%d %d",dentro, fora);

    return 0;
}
