#include <stdio.h>

int main() {
    int quebra1 = 1;
    int quebra2 = 1;
    int entrada, entrada2;
    int contador = 0;
    int marco1, marco2;
    int menor;
    int r, g, limpeza;
  

   
    do {
        r = scanf("%d", &entrada);
        
        if (r == 1) {
            if (quebra1 == 1) {
                menor = entrada;
                quebra1 = 0;
            }
             else if (entrada < menor) {
                menor = entrada;
            } 
            else{
                continue;
            }
        }
        else{
            break;
        }
        
        
    }
        while (r == 1);

    
     while((limpeza=getchar())!=EOF){
                if(isdigit(limpeza)|| limpeza=='-'|| limpeza=='+'){
                    ungetc(limpeza,stdin);
                    break;
                }
            }

    
    do {
        g = scanf("%d", &entrada2);
        if(entrada2<-32000||entrada2>32000){
            return 0;
        }
        if (g == 1) {
            if (quebra2 == 1 && entrada2 == menor) {
                marco1 = contador;
                quebra2 = 0;
            }
             if (entrada2 == menor) {
                marco2 = contador;
            }
            contador++;
        }
        else{
            break;
        }
    } while (g == 1);

    
    if (quebra2 == 1) {
        marco1 = contador;
        marco2 = contador;
    }

    printf("%d %d %d", menor, marco1, marco2);

    

    return 0;
}