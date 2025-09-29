#include <stdio.h>
#include <math.h>

typedef struct point{

    int x;
    int y;
}tponto;

typedef struct straight{

    tponto pi;
    tponto pf;

}treta;


tponto ReceberPonto();
treta RecebeReta();
void Proximo (tponto p, treta r);



tponto ReceberPonto(){

    tponto P;

    scanf("%d %d",&P.x,&P.y);

    return P;
}

treta RecebeReta(){

    treta R;

    scanf("%d %d %d %d", &R.pi.x,&R.pi.y,&R.pf.x,&R.pf.y);

    return R;
}

void Proximo (tponto p, treta r){

    double distanciaPi, distanciaPf;

    distanciaPi= sqrt(((p.x-r.pi.x)*(p.x-r.pi.x))+((p.y-r.pi.y)*(p.y-r.pi.y)));
    distanciaPf= sqrt(((p.x-r.pf.x)*(p.x-r.pf.x))+((p.y-r.pf.y)*(p.y-r.pf.y)));

    if(distanciaPi>distanciaPf){

        printf("FIM\n");
    }

    else if(distanciaPi<distanciaPf){

        printf("INICIO\n");
    }

    else{

        printf("EQUIDISTANTE\n");
    }


}

int main(){

    int n;

    scanf("%d",&n);

    for(int i=0; i<n; i++){

        tponto ponto = ReceberPonto();
        treta reta = RecebeReta();

        Proximo (ponto, reta);
    }

    return 0;
}



