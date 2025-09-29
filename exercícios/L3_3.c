#include <stdio.h>
#define TRUE 1
#define FALSE 0

int EhPrimo(int num, int y);

int EhPrimo(int num, int y){
    int i;
    if(num==0||num==1){
            return FALSE;
        }
        else if(num<0){
            return FALSE;
        }
        else if(y!=2){
            return FALSE;
        }
        else{
    for(i=2;i<=num/2;i++){
        
         if(num%i==0){
            return FALSE;
        }
    }
}
    return TRUE;
}

int main(){
    int  num,fim,i;
   int y= scanf("%d %d",&num,&fim);
   if(num>fim){
    return 0;
   }
    for(i=num+1;i<fim;i++){
        if(EhPrimo(i, y)){
            printf("%d ",i);
        }
        else{
            continue;
        }
    }
return 0;
}