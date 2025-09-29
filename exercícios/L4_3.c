#include <stdio.h>
#define TRUE 1
#define FALSE 0

int EhBissexto (int year);
void Imprimir (int day, int month, int year);
int retornadia (int day, int month, int year);
int retornames (int month);


    int retornames (int month){

        if(month<1){
            return 1;
        }

        else if(month>12){

            return 12;
        }
        else{
        return month;
    }
}



int retornadia(int day, int month, int year){

    if(EhBissexto(year)){

        if(month==2){

            if(day<1){

                return 1;
            }

            else if(day>29){

                return 29;
            }

            else{

                return day;
            }
        }

           if(month==4||month==6||month==11||month==9){

            if(day<1){

                return 1;
            }

            else if(day>30){

                return 30;
            }

            else{

                return day;
            }
        }

        else {

            if(day<1){

                return 1;
            }

            else if(day>30){

                return 31;
            }

            else{

                return day;
            }
         }
    }

    else{

        if(month==2){

            if(day<1){

                return 1;
            }

            else if(day>28){

                return 28;
            }

           else{
            return day;
           }
        }

          else if(month==4||month==6||month==11||month==9){

            if(day<1){

                return 1;
            }

            else if(day>30){

                return 30;
            }

            else{

                return day;
            }
        }

    else {

         if(day<1){

                return 1;
            }

            else if(day>30){

                return 31;
            }

            else{

                return day;
            }
    }
    }

}

typedef struct D{
    
    int day;
    int month;
    int year;
}tdata;

int EhBissexto (int year){

    if(year%1000==0){

        if(year%400==0){

            return TRUE;
        }

        else{

            return FALSE;
        }
    }

    else{

        if(year%4==0){

            return TRUE;
        }

        else{

            return FALSE;
        }
    }
}

void Imprimir (int day, int month, int year){

    if(EhBissexto(year)){

        printf("'%02d/%02d/%d':Bisexto\n",day,month,year);
    }

    else{

        printf("'%02d/%02d/%d':Normal\n",day,month,year);
    }
}

int main (){

    tdata d; 
    int n;

    scanf("%d",&n);

   for(int i=0; i<n;i++){

    scanf("%d %d %d",&d.day,&d.month,&d.year);
    d.month = retornames(d.month);
    d.day = retornadia(d.day,d.month,d.year);

    Imprimir(d.day,d.month,d.year);
    }

    return 0;
}