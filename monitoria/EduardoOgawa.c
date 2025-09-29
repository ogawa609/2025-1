#include <stdio.h>

int main() {
    
char figura;
char corpo,diagonal,oposta;
int base, altura, contador,contador2, contador3, controlador1;
char posicao;
    
    scanf("%c",&figura);
    
    if(figura=='R'){
        
        scanf(" %c %d %d",&corpo, &altura, &base);
        
        for(contador2=1;contador2<=altura;contador2++){
    
            for(contador=1;contador<=base;contador++){
     
                 printf("%c",corpo);
             }
            printf("\n");
    
        }
    }
    else if(figura=='T'){
        
        scanf(" %c %d %c",&corpo, &base, &posicao);
        
        if(posicao=='D'){
            
            do{  
                for(contador=1;contador<=base;contador++){
                  
                    printf("%c",corpo);
                }
                
                printf("\n");
             
                base= base-1;
            }
             
            while(base>=1);
            
        }
            
        else if(posicao=='C'){
            
            contador2=1;
            
            do{
                for(contador=1;contador<=contador2;contador++){
                    
                    printf("%c",corpo);
                }
                
                printf("\n");
                
                contador2++;
            }
                
            while(contador2<=base);
        }
            
       else{
           
           printf("NAO EH FORMA VALIDAAAAAA!!!!!!!");
       }
    }

    else if(figura=='Q'){
 
       scanf(" %c %c %c %d",&corpo, &diagonal, &oposta, &base);
        
       contador3=base-1;
        
       for(contador=0;contador<base;contador++){
           
                for(contador2=0;contador2<=contador;contador2++){
                    
                   if(contador2>0){
                       
                       printf("%c",corpo);
                   }
               }
           
           printf("%c",diagonal);  
           
          controlador1=1;
           
           do{
               if(contador3>0){
                   
                   printf("%c",oposta);
               }
               
               controlador1++;
           }
               while(controlador1<=contador3);
           
           contador3--;
           
           printf("\n");
               
       }
    }

    else{
        printf("NAO EH FORMA VALIDAAAAAA!!!!!!!");
    }
    
       
return 0;
}