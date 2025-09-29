#include <stdio.h>

int main(){

    int elementos;
    char tipo;

    scanf("%d %c\n",&elementos,&tipo);

    int linha, coluna;

    scanf("%d %d\n",&linha,&coluna);

    char matriz[linha][coluna];

    for(int i=0; i<linha;i++){

        for(int j=0; j<coluna; j++){

            scanf("%c",&matriz[i][j]);
        }
        scanf("\n");
    }

    int v=0;
    int h=0;
    int check=0;

    if(tipo=='V'){

        for(int a=0; a<coluna; a++){

            for(int b=0; b<linha; b++){ 

                if(matriz[b][a]=='X'){

                    for(int d=b;d<linha;d++){

                        if(matriz[d][a]=='X'){
                            check++;

                            if(check==elementos){
                                v++;
                            }

                        }
                        else{
                            check=0;
                            break;
                        }
                    }
                    
                }

              check=0;  
        }

       
    }
 printf("CONT: V %d",v);

}


if(tipo=='H'){

        for(int a=0; a<linha; a++){

            for(int b=0; b<coluna; b++){ 

                if(matriz[a][b]=='X'){

                    for(int d=b;d<coluna;d++){

                        if(matriz[a][d]=='X'){
                            check++;

                            if(check==elementos){
                                h++;
                            }

                        }
                        else{
                            check=0;
                            break;
                        }
                    }
                    
                }

              check=0;  
        }

       
    }
 printf("CONT: H %d",h);

}

}