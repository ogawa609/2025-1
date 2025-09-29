#include <stdio.h>
#define TRUE 1
#define FALSE 0
int ValidarPlaca();
int EhLetraMaiuscula(char c);
int EhDigito(char c);
void ImprimirRegiao(int n);

int EhLetraMaiuscula(char c){
    if(c>='A'&&c<='Z'){
        return TRUE;
    }
    return FALSE;
}

int EhDigito(char c){
    if(c>='0'&&c<='9'){
        return TRUE;
    }
    return FALSE;
}

void ImprimirRegiao(int n){
    int regiao = n%5;
    if(regiao==0){
        printf("VALIDA SUL\n");
    }
    else if(regiao==1){
        printf("VALIDA SUDESTE\n");
    }
    else if(regiao==2){
        printf("VALIDA CENTRO-OESTE\n");
    }
    else if (regiao==3){
        printf("VALIDA NORTE\n");
    }
    else if(regiao==4){
        printf("VALIDA NORDESTE\n");
    }
    else{
        printf("INVALIDA\n");
    }
    
}

int ValidarPlaca(){
int soma=0;
int contagem;
char c;
int validar=1;
for (contagem=0;contagem<=6;contagem++){
    scanf("%c",&c);

    if(c=='\n'){
        return -1;
    }

    if((contagem==0||contagem==1||contagem==2||contagem==4)&&!EhLetraMaiuscula(c)){
        validar=0;
    }
    if((contagem==3||contagem==5||contagem==6)&&!EhDigito(c)){
        validar=0;
    }
    if ((contagem==3||contagem==5||contagem==6)&&EhDigito(c)){
        soma= soma+ (c-'0');
    }
}
 if(getchar()!='\n'){
while ((c= getchar())!='\n' && c != EOF);
 return -1;
}
if(validar==0){
    return -1;
}
return soma;
}

int main(){
    int vezes;
    int somatorio;
    scanf("%d",&vezes);
    getchar();
    for(int r=1;r<=vezes;r++){
       somatorio= ValidarPlaca();
       ImprimirRegiao(somatorio);
    }
    return 0;
}
