#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct point{

    int x;
    int y;
}tponto;

typedef struct straight{

    tponto pi;
    tponto pf;

}treta;



treta Iniciar();
int Quadrante(int x, int y);
int Comparar(int x, int y);


treta Iniciar(){

    treta R;
    scanf("%d %d %d %d",&R.pi.x,&R.pi.y,&R.pf.x,&R.pf.y);

    return R;
}

int Quadrante(int x, int y){


     if(x>0&&y>0){

        return 1;
    }

    else if(x<0&&y>0){
        return 2;
    }

    else if(x<0&&y<0){

        return 3;
    }

    else if(x>0&&y<0){

        return 4;
    }
}

int Comparar(int x, int y){


    if(x==y){

        return TRUE;
    }
    
    return FALSE;
}

int main (){

    int num;

    scanf("%d",&num);

    for(int i=0;i<num;i++){

        treta R = Iniciar();
        int pi = Quadrante(R.pi.x,R.pi.y);
        int pf = Quadrante(R.pf.x,R.pf.y);

        if((R.pi.x==0||R.pi.y==0)&&(R.pf.x==0||R.pf.y==0)){

            if(R.pi.x==R.pf.x&&R.pi.y==R.pf.y){

                printf("MESMO\n");
            }

            else{

                printf("DIFERENTE\n");
            }
        }

        else if(Comparar(pi,pf)){

            printf("MESMO\n");
        }

        else{

            printf("DIFERENTE\n");
        }
    }

    return 0;
}