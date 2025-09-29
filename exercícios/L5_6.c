#include <stdio.h>

int main(){

    int n1, n2;
    int k, l;
    int igual=0;

    scanf("%d",&n1);

    int e1[n1];

    for(int i=0; i<n1; i++){

        scanf("%d", &e1[i]);
    }

    scanf("%d",&n2);

    int e2[n2];

    for(int j=0; j<n2; j++){

        scanf("%d",&e2[j]);
    }

    for( k=0; k<n1; k++){

        for( l=0; l<n2; l++){

            if(e1[k]==e2[l]){
                igual++;
                break;
            }
        }
    }

    if(igual==0){
        printf("NENHUM");
    }

    else if(igual==n1){
        printf("TODOS");

        }

    else{
        printf("PARCIAL");
    }
    
return 0;

}