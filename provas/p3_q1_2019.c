#include <stdio.h>

int main(){

    int lista1, lista2;

    scanf("%d",&lista1);

    int numeros1[lista1];

    for(int i=0; i<lista1; i++){

        scanf("%d",&numeros1[i]);
    }

    scanf("%d",&lista2);

    int numeros2[lista2];

    for(int j=0; j<lista2;j++){

        scanf("%d",&numeros2[j]);
    }

    printf("PARES:\n");

    int dois=0;

    for(int a=0; a<lista1; a++){

        if(dois==lista2){
            dois=0;
        }

        printf("%d - %d\n",numeros1[a],numeros2[dois]);

        dois++;
    }

    return 0;
}