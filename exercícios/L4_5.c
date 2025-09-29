#include <stdio.h>
#include <math.h>

typedef struct point{
    
    int x;
    int y;
}tponto;

double Distancia(tponto p1, tponto p2);

double Distancia(tponto p1, tponto p2){

    double R;

    R = sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));

    return R;
}

int main(){

    int n;
    tponto p1, p2;
    double distancia;

    scanf("%d",&n);
    

    for(int i=0; i<n; i++){

        if(i>0){
            p2=p1;
        }

        scanf("%d %d",&p1.x,&p1.y);
         


        if(i==0){

            printf("-\n");
            continue;

        }

        else if (i>0){

            distancia= Distancia(p1,p2);
            printf("%.2f\n",distancia);
        }
    }

    return 0;
}
