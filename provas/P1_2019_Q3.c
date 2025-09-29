#include<stdio.h>
int main(){
   
    char letra;
    int i,validar=1;

    for(i=1;i<=8;i++){
        scanf("%c",&letra);
        if(i==1||i==2||i==3){
            if((letra>='a'&&letra<='z')||(letra>='A'&&letra<='Z')){
                continue;
            }
            else{
                validar=validar+2;
                
            }
        }
       else if(i==4){
            if(letra=='-'){
                continue;
            }
        }
        else if(i==5||i==6||i==7||i==8){
            if(letra>='0'&&letra<='9'){
                continue;
            }
            else{
                validar=validar+3;
               
            }
        }
    }
    if(validar==1){
        printf("Codigo valido!");
    }
    else if(validar==3){
        printf("Codigo invalido!Problema nas letras!");
    }
    else if(validar==4){
        printf("Codigo invalido!Problema nos numeros!");
    }
    else if(validar==6){
        printf("Codigo invalido!Problema nas letras e nos numeros!");
    }
    return 0;
}
