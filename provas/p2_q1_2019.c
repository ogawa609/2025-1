#include <stdio.h>

int main(){

    int a,b,c;
    int soma=0;

    scanf("%d %d %d", &a,&b,&c);

    int n;

    scanf("%d",&n);

    int gasto[n];

    for(int i=0; i<n; i++){

        scanf("%d",&gasto[i]);
    }

    for(int j=0;j<n;j++){

        if(gasto[j]==1){
            soma= soma+a;
        }

        else if(gasto[j]==2){
             soma= soma+b;
        }

         else if(gasto[j]==3){
             soma= soma+c;
        }
    }

    printf("CUSTO:%d\n", soma);

    return 0;
}