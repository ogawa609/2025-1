#include <stdio.h>

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
int area (int x1, int y1, int x2, int y2);

//inferior esquerda e superior direita

int area (int x1, int y1, int x2, int y2){

    int base = x2-x1;
    int altura = y2-y1;

    return base*altura;
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){

    int area1= area(r1_x1, r1_y1, r1_x2, r1_y2);
    int area2= area(r2_x1, r2_y1, r2_x2, r2_y2);

    if((r2_x1>r1_x1&&r2_x1<r1_x2&&r2_y1>r1_y1&&r2_y1<r1_y2)||(r2_x2>r1_x1&&r2_x2<r1_x2&&r2_y2>r1_y1&&r2_y2<r1_y2)){

        if(r2_x1>r1_x1&&r2_x1<r1_x2&&r2_y1>r1_y1&&r2_y1<r1_y2){

            int subtrai1= area(r2_x1,r2_y1,r1_x2,r1_y2);
            area2=area2-subtrai1;

            return area2+area1;

        }

        else if (r2_x2>r1_x1&&r2_x2<r1_x2&&r2_y2>r1_y1&&r2_y2<r1_y2){
            int subtrai2= area(r1_x1,r1_y1,r2_x2,r2_y2);
            area2=area2-subtrai2;

            return area2+area1;
        }
    }

    return area1+area2;
}

int main(){

    int r1_x1,r1_y1,r1_x2,r1_y2,r2_x1,r2_y1,r2_x2,r2_y2;

    scanf("%d %d %d %d %d %d %d %d", &r1_x1,&r1_y1,&r1_x2,&r1_y2,&r2_x1,&r2_y1,&r2_x2,&r2_y2);

    if(r1_x1>r1_x2||r1_x1>r2_x1||r1_x1>r2_x2||r1_y1>r1_y2||r1_y1>r2_y1||r1_y1>r2_y2){
        return 0;
    }

    if (r1_x1>r2_x2||r1_x2>r2_x2||r2_x1>r2_x2||r1_y1>r2_y2||r1_y2>r2_y2||r2_y1>r2_y2){
        return 0;
    }

    if(r2_x1>r1_x1&&r2_x2<r1_x2&&r2_y1>r1_y1&&r2_y2<r1_y2){
        return 0;
    }

    int resp = area_total(r1_x1,r1_y1,r1_x2,r1_y2,r2_x1,r2_y1,r2_x2,r2_y2);

    printf("RESP:%d",resp);

    return 0;
}