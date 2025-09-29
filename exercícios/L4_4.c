#include <stdio.h>

typedef struct point{

    int x;
    int y;

}tponto;

int Quadrante(tponto o);
tponto Inverso (tponto p);
int quadranteinverso (tponto w);


int quadranteinverso (tponto w){

    if(w.x==0||w.y==0){
        return 0;
    }

    else if(w.x<0&&w.y>0){
        return 2;
    }

    else if(w.x>0&&w.y>0){
        return 1;
    }

    else if(w.x<0&&w.y<0){
        return 3;
    }

    else if(w.x>0&&w.y<0){
        return 4;
    }

}

tponto Inverso(tponto p){

    tponto I = p;
    I.x= p.x * -1;
    I.y= p.y * -1;

    return I;
}

int Quadrante(tponto o){

    if(o.x==0||o.y==0){
        return 0;
    }

    else if(o.x<0&&o.y>0){
        return 2;
    }

    else if(o.x>0&&o.y>0){
        return 1;
    }

    else if(o.x<0&&o.y<0){
        return 3;
    }

    else if(o.x>0&&o.y<0){
        return 4;
    }
}

tponto a ();

tponto a (){

    tponto p;

    scanf("%d %d",&p.x,&p.y);

    return p;
}

int main (){

    int n;
    tponto ponto;
    int quadrante, quadrante_inverso;
    tponto inverso;


    scanf("%d",&n);

    for (int i = 0; i<n; i++){

        ponto= a();

        printf("(%d,%d) ",ponto.x,ponto.y);
        quadrante = Quadrante(ponto);
        printf("%d ",quadrante);
        inverso = Inverso(ponto);
        printf("(%d,%d) ",inverso.x,inverso.y);
        quadrante_inverso = quadranteinverso(inverso);
        printf("%d\n",quadrante_inverso);
    }
    return 0;
}

