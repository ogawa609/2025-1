#include <stdio.h>
#define ESCOVADO 1
#define ARRUMADA 1
#define PREPARADO 1
#define PENDENTE 0

int EscovarDentes(int dentes);
int ArrumarCama(int cama);
int PrepararCafe(int cafe);

int EscovarDentes(int dentes){
    if(dentes==ESCOVADO){
        printf("Já foi escovado!\n");
    }
    else{
dentes= ESCOVADO;
printf("Escovando os dentes!\n");
    }
    return dentes;
}

int ArrumarCama(int cama){
    if(cama==ARRUMADA){
        printf("Já foi arrumada!\n");
    }
    else{
    cama=ARRUMADA;
    printf("Arrumando a cama!\n");
    }
    return cama;
}

int PrepararCafe(int cafe){
    if(cafe==PREPARADO){
        printf("Já foi feito!\n");
    }
    else{
    cafe=PREPARADO;
    printf("Preparando o cafe!\n");
    }
return cafe;
}

int main(){
int tempo=15;
int cafe=PENDENTE;
int cama=PENDENTE;
int dentes=PENDENTE;
int opcao;
    
while(1){
scanf("%d",&opcao);

if(opcao!=0&&tempo<=0){
    printf("###Perdeu o onibus!###\n");
    break;
}

if(opcao==0){
    if((cama==PENDENTE||cafe==PENDENTE||dentes==PENDENTE)&&tempo>0){
       printf("###Ainda ha tarefas pendentes!###\n");
       continue; 
    }
    else if(tempo<=0){
        printf("###Perdeu o onibus!###\n");
        break;
    }
    else if(cama==ARRUMADA&&cafe==PREPARADO&&dentes==ESCOVADO){
        printf("Saindo de casa!\n");
        break;
    }
}
else if(opcao==1){
    dentes = EscovarDentes(dentes);
    tempo-=2;
    printf("Tempo restante: %d\n",tempo);
    continue;
}
else if(opcao==2){
cama = ArrumarCama(cama);
    tempo-=3;
    printf("Tempo restante: %d\n",tempo);
continue;
}
else if(opcao==3){
   cafe =  PrepararCafe(cafe);
    tempo-=5;
    printf("Tempo restante: %d\n",tempo);
    continue;
}
else {
    printf("Opcao inválida!");
    continue;
}
}
return 0;
}