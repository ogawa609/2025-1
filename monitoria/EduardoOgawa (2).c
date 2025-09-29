#include <stdio.h>


#define PENDENTE 0
#define ESCOVADO 1
#define ARRUMADA 1
#define PREPARADO 1


void EscovarDentes(int *dentes, int *tempo);
void ArrumarCama(int *cama, int *tempo);
void PrepararCafe(int *cafe, int *tempo);

int main() {
    int dentes = PENDENTE;
    int cama = PENDENTE;
    int cafe = PENDENTE;
    int tempo = 15;
    int opcao;

    while (1) {
        scanf("%d", &opcao);

        if (tempo <= 0) {
            printf("### Perdeu o onibus! ###\n");
            break;
        }

        switch(opcao) {
            case 1:
                EscovarDentes(&dentes, &tempo);
                break;
            case 2:
                ArrumarCama(&cama, &tempo);
                break;
            case 3:
                PrepararCafe(&cafe, &tempo);
                break;
            case 0:
                if (dentes == ESCOVADO && cama == ARRUMADA && cafe == PREPARADO) {
                    printf("Saindo de casa!\n");
                } else if (tempo <= 0) {
                    printf("### Perdeu o onibus! ###\n");
                } else {
                    printf("### Ainda ha tarefas pendentes! ###\n");
                }
                if (dentes == ESCOVADO && cama == ARRUMADA && cafe == PREPARADO || tempo <= 0) {
                    return 0;
                }
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}


void EscovarDentes(int *dentes, int *tempo) {
    if (*dentes == ESCOVADO) {
        printf("Isso ja foi feito!\n");
    } else {
        printf("Escovando os dentes!\n");
        *dentes = ESCOVADO;
    }
    *tempo -= 2;
    printf("Tempo restante: %d minutos\n", *tempo);
}

void ArrumarCama(int *cama, int *tempo) {
    if (*cama == ARRUMADA) {
        printf("Isso ja foi feito!\n");
    } else {
        printf("Arrumando a cama!\n");
        *cama = ARRUMADA;
    }
    *tempo -= 3;
    printf("Tempo restante: %d minutos\n", *tempo);
}

void PrepararCafe(int *cafe, int *tempo) {
    if (*cafe == PREPARADO) {
        printf("Isso ja foi feito!\n");
    } else {
        printf("Preparando o cafe!\n");
        *cafe = PREPARADO;
    }
    *tempo -= 5;
    printf("Tempo restante: %d minutos\n", *tempo);
}