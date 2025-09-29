#include <stdio.h>
int main(){
    int M,N;
    int valor=1;
    int valor2=0;
    int cont,x;
    int soma=0;
    scanf("%d %d",&N,&M);

    if(M==0){
        for(cont=0;cont<N;cont++){
            if(cont<2){
                printf("%d ",cont);
            }
            else{
        x=valor;        
        valor=2*(valor)+(valor2);
        valor2=x;
                
        printf("%d ",valor);
            }
         }
    }

    else if(M==1){

        for(cont=0;cont<N;cont++){
            if(cont<2&&(cont%2!=0)){
                printf("%d ",cont);
            }
                else if(cont<2&&(cont%2==0)){
                soma=soma+cont;
            }
            else{
                x=valor;        
                valor=2*(valor)+(valor2);
                valor2=x;
             if(valor%2!=0){
                printf("%d ",valor);
            }
            else{
                soma=soma+valor;
            }
            }
        }
        printf("\n");
        printf("%d\n",soma);
       
    }

return 0;
}
