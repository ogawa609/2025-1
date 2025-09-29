#include <stdio.h>
int main(){

int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11;
char c1,c2,c3;
int val=0;

scanf("%d %d %d %c %d %d %d %c %d %d %d %c",&d1,&d2,&d3,&c1,&d4,&d5,&d6,&c2,&d7,&d8,&d9,&c3);

if(c1!='.'&&c2!='.'&&c3!='-'){
    printf("invalido");
    return 0;
}


int soma= d1*10+d2*9+d3*8+d4*7+d5*6+d6*5+d7*4+d8*3+d9*2;
scanf("%d",&d10);
if(soma%11<2){
    if(d10!=0){
        val=val+1;
    }
}
else{
    if(d10!=(11-(soma%11))){
        val = val+1;
    }
}
scanf("%d",&d11);
int soma2= d1*11+d2*10+d3*9+d4*8+d5*7+d6*6+d7*5+d8*4+d9*3+d10*2;
if(soma2%11<2){
    if(d11!=0){
        val=val+2;
    }
}
else{
    if(d11!=(11-(soma2%11))){
        val=val+2;
    }
}

if(d1==d2&&d2==d3&&d3==d4&&d4==d5&&d5==d6&&d6==d7&&d7==d10&&d10==d11){
    printf("CPF invalido: digitod iguais!");
    return 0;
}

if(val=0){
    printf("CPF valido!");
}

if(val=1){
    printf("CPF invalido: primeiro digito!");
}

if(val=2){
    printf("CPF invalido: segundo digito!");
}

if(val=3){
    printf("CPF invalido: dois digitos!");
}

return 0;

}