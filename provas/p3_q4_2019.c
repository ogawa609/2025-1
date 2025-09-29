#include <stdio.h>

typedef struct {

    int id;
    int passageiros;
    char marca[100];
    int km;
    char situacao;
}tcarro;

typedef struct{

    int numero_carros;
    tcarro carros[100];

}tConcessionaria;

tcarro LeCarro();
void ImprimeCarro(tcarro carro);
int ObtemNumPassageirosCarro(tcarro carro);
int ObtemKmCarro(tcarro carro); 
tConcessionaria LeCarrosConcessionaria();
void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);
int EstaDisponivelCarro(tcarro carro);
tcarro AlugaCarro(tcarro carro, int cliente);

int EstaDisponivelCarro(tcarro carro){

    if(carro.situacao=='A'){
        return 1;
    }
    return 0;
}

void ImprimeCarro(tcarro carro){
    int i=0;

    printf("CARRO (%d): ",carro.id);

    while(carro.marca[i]!='\0'){

        printf("%c",carro.marca[i]);
        i++;
    }
    printf(" de %d passageiros e com %d km",carro.passageiros,carro.km);
}

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km){

    int p;
    int k;

    for(int i=0; i<concessionaria.numero_carros;i++){

     if(concessionaria.carros[i].situacao=='L'){}  
}
}


int ObtemNumPassageirosCarro(tcarro carro){

    int passageiros;

    passageiros=carro.passageiros;
    return passageiros;
}

int  ObtemKmCarro(tcarro carro){

    int km = carro.km;
    return km;
}


tcarro LeCarro(){

    tcarro carro;
    
    

    scanf("%d",&carro.id);
    scanf("%d ",&carro.passageiros);
        scanf("%s",carro.marca);

    scanf("%d",&carro.km);
    carro.situacao='L';
    
return carro;
}

tConcessionaria LeCarrosConcessionaria(){

    tConcessionaria C;

    scanf("%d",&C.numero_carros);

    for(int i=0; i<C.numero_carros;i++){

        C.carros[i]= LeCarro();
        scanf("\n");
    }

    return C;
}


int main(){

tConcessionaria concessionaria;

concessionaria = LeCarrosConcessionaria();

int qtdPassageiros, km, i = 0;
char situacao;
int cliente;

while((scanf("%d,%c", &cliente, &situacao) != EOF)&&(scanf("%d,%d",&qtdPassageiros,&km)==2)){

printf("Caso %d:\n", ++i);

ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);

}

return 0;
}

