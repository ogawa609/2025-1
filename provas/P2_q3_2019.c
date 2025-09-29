#include <stdio.h>
#define TRUE 1
#define FALSE 0

 int EhDigito(char c);
  int LeProxChar(char terminador, char c);
  void ImprimePorExtenso(char digito);

  int EhDigito(char c){

    if(c>='0'&&c<='9'){
        return TRUE;
    }

    return FALSE;
  }

  int LeProxChar(char terminador, char c){

    if(c==terminador){

        return TRUE;
    }

    return FALSE;
  }


  void ImprimePorExtenso(char digito){

    if(digito=='1'){

        printf("um");
    }
    else if(digito=='0'){

        printf("zero");
    }

   else if(digito=='2'){

        printf("dois");
    }
    else if(digito=='3'){

        printf("tres");
    }
    else if(digito=='4'){

        printf("quatro");
    }
    else if(digito=='5'){

        printf("cinco");
    }
    else if(digito=='6'){

        printf("seis");
    }
    else if(digito=='7'){

        printf("sete");
    }
    else if(digito=='8'){

        printf("oito");
    }
    else if(digito=='9'){

        printf("nove");
    }
  }

  int main (){

    char c[5000];
    char terminador;
    int i=0;
    int j=0;

    scanf("%c ",&terminador);

    while(1){

        scanf("%c",&c[i]);
        
        if(c[i]==terminador){

            break;
        }

        i++;
    }

    while(c[j]!=terminador){

        if(EhDigito(c[j])){

            if((c[j+1]<'0'||c[j+1]>'9')&&(c[j-1]<'0'||c[j-1]>'9')){

                ImprimePorExtenso(c[j]);
            }

            else{

                printf("%c",c[j]);
            }


        }

        else{

            printf("%c",c[j]);
        }

        j++;
    }

    return 0;
    
  }



