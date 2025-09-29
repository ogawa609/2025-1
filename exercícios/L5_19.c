#include <stdio.h>




int main(){

    int horas;
    int largura, altura;
    int terra=0;
    int posmare=0;



    scanf("%d %d %d", &horas, &largura,&altura);

    if(horas<0||horas>8){
        return 0;
    }

    if(largura>600||altura>600){
        return 0;
    }

    int foto[altura][largura];

    for(int i=0; i<altura; i++){

        for(int j=0;j<largura;j++){

            scanf("%d", &foto[i][j]);
        }
    }



    for(int i=0;i<altura;i++){

        for(int j=0; j<largura;j++){

            if(foto[i][j]==0){

                terra++;
            }
        }
    }


    for(int tempo=0; tempo<horas; tempo++){

        

        for(int taltura=0;taltura<altura;taltura++){

            for(int tlargura=0;tlargura<largura; tlargura++){

                if(foto[taltura][tlargura]==0){

                    if( foto[taltura+1][tlargura]==1||
                        foto[taltura-1][tlargura]==1||
                        foto[taltura][tlargura+1]==1||
                        foto[taltura][tlargura-1]==1 ){

                            foto[taltura][tlargura]=2;
                            
                        }
                        
                }

                
            }

            if(tempo==0){
                for(int a=0; a<largura;a++){
                    foto[0][a]=1;
                }

                for(int b=0;b<altura;b++){
                    foto[b][0]=1;
                }
            }
        }
    }

    for(int p=0;p<altura;p++){

        for(int q=0; q<largura;q++){

            if(foto[p][q]==0){

                posmare++;
            }
        }
    }

    printf("%d %d", terra, posmare);

    return 0;

}