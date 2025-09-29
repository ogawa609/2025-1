#include <stdio.h>
int main(){
int opcao;
int quant, diferenca, subtrai;
char codigo,cod;

scanf("%d",&opcao);
if(opcao==1){
    scanf("%d",&quant);
    do{
        scanf(" %c",&codigo);
        if(codigo=='.'){
            printf("%c",codigo);
            break;
        }
        else if(codigo>=97 && codigo<=122){
            diferenca= 122-(int)codigo;
            if(quant>diferenca){
            subtrai=quant-diferenca;
            cod=(subtrai%26)+96;
            }
            else if(quant<=diferenca){
                cod= quant+codigo;
            }
            printf("%c",cod);
        }
        else {
            printf("%c",codigo);
        }
    }
    while(codigo=='.');
}
else if(opcao==2){
     scanf("%d",&quant);
    do{
        scanf(" %c",&codigo);
        if(codigo=='.'){
            printf("%c",codigo);
            break;
        }
        else if(codigo>=97 && codigo<=122){
            diferenca= (int)codigo-97;
            if(quant>diferenca){
            subtrai=quant-diferenca;
            cod=(subtrai%26)-122;
            }
            else if(quant<=diferenca){
                cod= codigo-quant;
            }
            printf("%c",cod);
        }
        else {
            printf("%c",codigo);
        }
    }
    while(codigo=='.');
}

    return 0;
}