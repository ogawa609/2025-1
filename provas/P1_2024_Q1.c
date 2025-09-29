#include <stdio.h>
int main(){
int temp, quant, criadouros, casos, dia,semana;
scanf("%d %d %d",&temp,&quant,&criadouros);
if(!(criadouros==0||criadouros==1)){
    return 0;
}
else{
scanf("%d %d",&casos, &dia);
if(!(dia>=1&&dia<=365)){
    return 0;
}
else{
if(dia%7==0){
    semana=dia/7;
}
else{
semana=(dia/7)+1;
}

if((temp>30&&quant>50)||(criadouros==1&&casos>100)||semana%2==0){
    printf("Risco alto");
}
else if((temp<=30&&temp>=25&&quant<=50&&quant>=20)||(criadouros==1&&casos<=100&&casos>=50)){
    printf("Risco medio");
}
else{
    printf("Risco baixo");
}

}
}
return 0;
}