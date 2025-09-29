#include <stdio.h>
int main(){
    int troco1, troco2;
    int Q1,Q2;
    int resto5t1;
    int resto5t2;

    scanf("%d %d",&troco1,&troco2);

    resto5t1=troco1%5;
    resto5t2=troco2%5;
   Q1=(troco1/5)+resto5t1;
   Q2=(troco2/5)+resto5t2;

    if(Q1>Q2){
        printf("QTD troco 1 eh maior!");
    }
    else if(Q2>Q1){
        printf("QTD troco 2 eh maior!");
    }
    else{
        printf("Iguais!");
    }

return 0;
}