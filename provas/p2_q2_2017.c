#include <stdio.h>
#define TRUE 1
#define FALSE 0

 int EhIgual(int a, int b);
 int InverteNumero(int num);

    int EhIgual(int a, int b){

        if(a==b){
            return TRUE;
        }

        return FALSE;
    }

     int InverteNumero(int num){

        int soma=0;
        int p=10;
        int resto;
        while(num!=0){
           resto= num%p;
           soma=soma*10+resto;
           num=num/10;
        }

        return soma;
     }

     int main(){

        int num;
        int cont=0;
        int inverso;
        while(scanf("%d",&num)==1){
            inverso= InverteNumero(num);
            if(EhIgual(num,inverso)){

                cont++;
            }
        }

        printf("COUNT:%d",cont);
     }