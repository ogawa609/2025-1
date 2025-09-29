#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    int prog[n];

    for(int i=0; i<n; i++){

        scanf("%d",&prog[i]);
    }

    if(n==1){
        printf("NAO");
        return 0;
    }

   
    int recebe=prog[0];
    int p= prog[1]-prog[0];
    int aviso=0;

    for(int j=1; j<n;j++){
        if(prog[j]-recebe!=p){
            aviso=1;
        }
        recebe=prog[j];
    }

    if(aviso){
        printf("NAO");
        return 0;
    }

     printf("RESP:%d",p);
    return 0;
}