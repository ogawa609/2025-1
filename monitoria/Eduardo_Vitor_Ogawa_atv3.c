#include <stdio.h>
#define TRUE 1
#define FALSE 0

int EhPrimo(int primo);
int CalcularPoder(int A, int D, int B,int Mestre);
void ImprimirGanhador (int n1, int n2);

typedef struct Pokemon
{
    int ataque;
    int defesa;
    int mestre;
}Nivel;


int EhPrimo(int primo){

    if(primo==0||primo==1||primo<0){

        return FALSE;
    }
    else if(primo==2){

        return TRUE;
    }
    else{
        for(int i=2;i<=primo/2;i++){

            if(primo%i!=0){

                return TRUE;
            }
        }
    }
    return FALSE;
}

int CalcularPoder (int A, int D, int B, int Mestre){

    int poder=0;

    if(EhPrimo(Mestre)){

        poder= ((A+D)/2)+B;
    }

    else{

        poder=(A+D)/2;
    }

    return poder;
}

void ImprimirGanhador (int n1, int n2){

    if(n1>n2){

        printf("Primeiro\n");
    }

    else if(n2>n1){

        printf("Segundo\n");
    }

    else{

        printf("Empate\n");
    }
}

int main (){
    int rodadas=0;
    int bonus=0;
   
    Nivel pokemon1;
    Nivel pokemon2;
    int poder1=0;
    int poder2=0;

    scanf("%d %d",&rodadas,&bonus);
    
    for(int i=1; i<=rodadas; i++){

        scanf("%d %d %d %d %d %d", &pokemon1.ataque,&pokemon1.defesa,&pokemon1.mestre,&pokemon2.ataque,&pokemon2.defesa,&pokemon2.mestre);

        //Calcular poder pokemon 1;
        poder1= CalcularPoder(pokemon1.ataque,pokemon1.defesa,bonus,pokemon1.mestre);

        //Calcular poder pokemon 2;
        poder2= CalcularPoder(pokemon2.ataque,pokemon2.defesa,bonus,pokemon2.mestre);

        //Imprimir mensagem;
        ImprimirGanhador(poder1,poder2);
    }

    return 0;
}


