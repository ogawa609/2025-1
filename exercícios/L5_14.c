#include <stdio.h>
#include <stdlib.h>

typedef struct{

int codigo;
char sobrenome[21];
char nome[21];
int nota;
int idade;

} tCandidato;


tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
int ComparaString(char * str1, char * str2);

int CompararString(char *str1,char *str2){

    int i=0;

    while(str1[i]!='\0'||str2[i]!='\0'){

        if(str1[i]!=str2[i]){
            return 0;
        }

        i++;
    }

    return 1;
}


int main(){

int qtdCand, i = 0;

scanf("%d", &qtdCand);

tCandidato candidatos[qtdCand];
int imprimiu [qtdCand];

for(i = 0; i < qtdCand; i++){

candidatos[i] = LeCandidato();
 imprimiu[i]=0;
}

for(int a=0;a<qtdCand;a++){

    for(int b=a+1;b<qtdCand;b++){

        if(CompararString(candidatos[a].sobrenome,candidatos[b].sobrenome)){

            if(!imprimiu[a]){

                ImprimeCandidato(candidatos[a]);
                imprimiu[a]=1;
            }
            if(!imprimiu[b]){

                imprimiu[b]=1;
                ImprimeCandidato(candidatos[b]);

            }
        }
    }
    
    
}


return 0;
}


tCandidato LeCandidato(){

tCandidato candidato;

scanf("%*[^{]");
scanf("%*[{ ]");
scanf("%d", &candidato.codigo);
scanf("%*[, ]");
scanf("%[^,],", candidato.sobrenome);
scanf("%*[ ]");
scanf("%[^,],", candidato.nome);
scanf("%d", &candidato.nota);
scanf("%*[, ]");
scanf("%d", &candidato.idade);
scanf("%*[^\n]\n");

return candidato;
}


void ImprimeCandidato(tCandidato candidato){

    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",

    candidato.codigo, candidato.nome,
    candidato.sobrenome, candidato.nota, candidato.idade);

    }