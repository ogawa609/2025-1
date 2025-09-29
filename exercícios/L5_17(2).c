#include <stdio.h>

int EhLetra(char c);

int EhLetra(char c){

    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
        return 1;
    }

    return 0;
}

int main() {
    char palavra[500][501];
    int a=0;
    int b=0;
    int l;
    char c;

    while(scanf("%c",&c)==1){
        if(EhLetra(c)){

            palavra[a][b]=c;
            b++;
            continue;
        }

        if(b!=0){
            palavra[a][b]='\0';
            b=0;
            a++;
        }
    }

    for( l=a+1;l<=500;l++){
        palavra[l][0]='\0';
    }

    for(l=500-1;l>=0;l--){
        if(palavra[l][0]=='\0'){
            continue;
        }
        printf("%s",palavra[l]);
        printf(" ");
    }
    return 0;
}





   