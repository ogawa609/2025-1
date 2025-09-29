#include <stdio.h>
int main(){
    int L, C,V;
    int cont1, cont2;
    int maior = -9999999;
    int p1,p2;

    scanf("%d %d",&L,&C);

    for(cont1=1;cont1<=L;cont1++){
        for(cont2=1;cont2<=C;cont2++){
            scanf("%d",&V);
            if(maior<V){
                maior=V;
                p1=L;
                p2=C;
            }
            else{
                continue;
            }
        }

    }
    printf("%d %d %d", maior, p1, p2);
    return 0;
}