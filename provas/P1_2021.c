#include <stdio.h>
#define TRUE 1
#define FALSE 0

int EhLetraMinuscula(char c);
int EhLetraMaiuscula (char c);
int EhLetra (char c);
long long int exponenciacao (int x, int y);
int EhPrimo (int p);
int CalculaChave (int base, int chave, int primo);
char Decodifica (char letra, int n);
char Codifica(char letra, int n);

int EhLetraMinuscula(char c){
    if(c>='a'&&c<='z'){
        return TRUE;
    }
    return FALSE;
}


int EhLetraMaiuscula (char c){
    if(c>='A'&&c<='Z'){
        return TRUE;
    }
    return FALSE;
}



int EhLetra(char c){
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
        return TRUE;
    }
    return FALSE;
}


int EhPrimo(int p){
    int cont;

    if(p==0||p==1){
        return FALSE;
    }
    else if(p<0){
        return FALSE;
    }
    else{

    for(cont=2;cont<=p/2;cont++){
        if((p%cont)==0){
            return FALSE;
        }
        else{
            continue;
        }
    }
    return TRUE;
    }
}

long long int exponenciacao(int x, int y){
    int i=1;
    long long int R=1;
    for(i=1;i<=y;i++){
        R=R*x;
    }
    return R;
}

int CalcularChave(int base, int chave, int primo){
  int Cc;
long long int ex;
    ex=exponenciacao(base,chave);
    
  Cc= ex % primo;
  return Cc;
}

char Decodifica(char letra, int n){
    char LetraDecodificada;
    if(EhLetraMaiuscula(letra)){
LetraDecodificada = 'Z'+(((letra-'Z')-n)%26);
    }
    else if(EhLetraMinuscula(letra)){
    LetraDecodificada = 'z'+(((letra-'z')-n)%26);
    }
    return LetraDecodificada;
}
//c=('a'+(c+s)%26)
char Codifica (char letra, int n){
    char LetraCodificada;
    if(EhLetraMaiuscula(letra)){
        LetraCodificada='A'+(((letra-'A')+n)%26);
    }
    else if(EhLetraMinuscula(letra)){
        LetraCodificada='a'+(((letra-'a')+n)%26);
    }
    return LetraCodificada;
}

int main(){
    int tipo;
    int InteiroSecreto, base,primo;
    int ChavePublica;
    int ChaveAmigo,B,S,Limpeza;
    char mensagem, mensagem2;

    scanf("%d",&tipo);
    if(tipo==1){
        scanf("%d %d %d",&InteiroSecreto,&base,&primo);
        ChavePublica= CalcularChave(base,InteiroSecreto,primo);
        printf("%d",ChavePublica);
    }
    else if(tipo==3){
        scanf("%d %d %d %d", &InteiroSecreto, &base, &primo,&ChaveAmigo);
        S=CalcularChave(ChaveAmigo,InteiroSecreto,primo);
        getchar();
        while (mensagem!='\n')
        {
            scanf("%c",&mensagem);

            if(EhLetra(mensagem)){
               mensagem2= Decodifica(mensagem,S);
               printf("%c",mensagem2);
               continue;
            }
            else if(mensagem==' '){
            printf("%c",mensagem);
            continue;
            }
            else{
                printf("%c",mensagem);
            }
        } 
    }

    else if(tipo==2){
         scanf("%d %d %d %d", &InteiroSecreto, &base, &primo,&ChaveAmigo);
        if(!EhPrimo(primo)){
            printf("Primo invalido!");
            return 0;
        }
        
        S=CalcularChave(ChaveAmigo,InteiroSecreto,primo);
        getchar();
        while (mensagem!='\n')
        {
            scanf("%c",&mensagem);
            
            if(EhLetra(mensagem)){
               mensagem2= Codifica(mensagem,S);
               printf("%c",mensagem2);
               continue;
            }
            else if(mensagem==' '){
            printf("%c",mensagem);
            continue;
            }
            else{
                printf("%c",mensagem);
            }
        } 
    }
    else{
        printf("Operacao Invalida.");
    }
    return 0;
}
//ALICE
//Alice inteiro secreto a=6
//primo = 23
//base=5
//chave publica de alicer -> A=base^inteiro % primo ->5^6%23


//BOB
//Inteiro de bob = 15
//chave publica de bob -> 5^15%23

//indice de soma -> cheve do coleguinha^Meu Inteiro % primo

