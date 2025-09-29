#include <stdio.h>
#define TRUE 1
#define FALSE 0

 int EhPalindromo(int num);

 int EhPalindromo (int num){

    int reverso=0;
    int resto;
    int comparar = num;
    while(num!=0){
       resto= num%10;
       num=num/10;
       reverso=reverso*10+resto;
    }

    if(comparar==reverso){
        return TRUE;
    }
return FALSE;

 }

 int main(){

    int entrada;
   

    while ((scanf("%d",&entrada))!=EOF){
         
        if(EhPalindromo(entrada)){
            printf("S\n");
        }
        else{
            printf("N\n");
        }
    }
   
    return 0;
 }