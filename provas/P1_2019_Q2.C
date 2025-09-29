#include <stdio.h>
int main(){
    int n1,n2,resultado,resto;
    char operacao;
    scanf("%d",&n1);
    scanf(" %c",&operacao);
    scanf("%d",&n2);
if(operacao=='+'){
    resultado=n1+n2;
    printf("SOMA:%d",resultado);
}
else if(operacao=='-'){
    resultado=n1-n2;
    printf("SUB:%d",resultado);
}
else if(operacao=='*'){
    resultado=n1*n2;
    printf("MULT:%d",resultado);
}
else if(operacao=='/'){
    resultado=n1/n2;
    resto=n1%n2;

    if(resto==0){
        printf("DIV:%d",resultado);
    }
    else{
        printf("DIV:%d, RESTO:%d",resultado,resto);
    }
}
return 0;
}