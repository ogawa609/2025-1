#include <stdio.h>

void ImprimirMenu();

void ImprimirMenu(){

    printf("====== CYBERTEST - MENU ======\n");
    printf("1. Cadastrar novo dispositivo\n");
    printf("2. Listar dispositivos\n");
    printf("3. Ordenar por vulnerabilidade\n");
    printf("4. Sair\n");
}

int main(){

    int escolha;
    int p=0;
    int codigo[20000];
    float nota[20000];
    float temp1;
    int temp2;
    int a=0;


    
    do{

        ImprimirMenu();


    scanf("%d",&escolha);
    printf("Escolha: %d\n",escolha);

    if(escolha>4||escolha<1){
        printf("Opcao invalida!!");
        return 0;
    }

    if(escolha==1){

        scanf("%d",&codigo[p]);
        printf("Codigo do dispositivo: %d\n",codigo[p]);
        scanf("%f", &nota[p]);
        printf("Nota de Vulnerabilidade: %.1f\n",nota[p]);
        p++;
        printf("\n");
        continue;

    }

    else if(escolha==2){

        printf("Lista de dispositivos cadastrados:\n");

        if(p==0){

            printf("Nenhum dispositivo cadastrado.\n");
            printf("\n");
            continue;
        }

        for(a=0;a<p;a++){

            printf("Codigo: %d | Vulnerabilidade: %.1f\n",codigo[a],nota[a]);
           

        }

        printf("\n");
        continue;
    }

    else if(escolha==3){

         if(p==0){

            printf("Nenhum dispositivo cadastrado para ordenar.\n");
            printf("\n");
            continue;
        }

        printf("Ordenando dispositivos...\n");

        for(int i=0; i<p; i++){

            for(int b=i;b<p;b++){

                if(nota[i]<nota[b]){

                    temp1=nota[b];
                    temp2=codigo[b];

                    codigo[b]=codigo[i];
                    codigo[i]=temp2;

                    nota[b]=nota[i];
                    nota[i]=temp1;

                    continue;
                }

                else{

                    continue;
                }
            }
        }

        printf("\n");

        continue;


    }

    if(escolha==4){

        break;
    }

    } while(escolha!=4);

    printf("Saindo do sistema...\n");

    return 0;
}