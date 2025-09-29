#include <stdio.h>
#define TRUE 1
#define FALSE 0;

int Propriedade(int num);

int Propriedade(int num){
    int ab;
    double cd;
    int ef;

    ab=num/100;
    cd=(num/100.0)-ab;
    cd=cd*100;
    ef=ab+cd;
    int r = ef*ef;

    if(r==num){
        return TRUE;
    }
    return FALSE;
}

int main(){
   
    int n, m;

    scanf("%d %d",&n,&m);

    if(n>m){
        return 0;
    }

    else if (n<1000||m>9999){
        return 0;
    }

    for(int i=n+1;i<m;i++){

        if(Propriedade(i)){

            printf("%d\n",i);
        }
    }
    return 0;
}