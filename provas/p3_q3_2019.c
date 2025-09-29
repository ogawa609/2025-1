#include <stdio.h>

typedef struct {

    int id;
    int passageiros;
    char marca[100];
    int km;
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

        p= ObtemNumPassageirosCarro(concessionaria.carros[i]);
        k= ObtemKmCarro(concessionaria.carros[i]);

        if(pass==-1 && km==-1){
            ImprimeCarro(concessionaria.carros[i]);
            printf("\n");
        }

        else if(pass==-1&&km>-1){
            if(k<=km){

                ImprimeCarro(concessionaria.carros[i]);
                printf("\n");
            }

            else{
                continue;
            }
        }

        else if(pass>-1&&km==-1){

            if(p==pass){

                ImprimeCarro(concessionaria.carros[i]);
                 printf("\n");
                
            }

            else{

                continue;
            }
        }


        else if(pass>-1&&km>-1){

            if(p==pass&&k<=km){

                ImprimeCarro(concessionaria.carros[i]);
                 printf("\n");
            }

            else{
                continue;
            }
        }
        
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

while(scanf("%d,%d", &qtdPassageiros, &km) == 2){

printf("Caso %d:\n", ++i);

ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);

}

return 0;
}

