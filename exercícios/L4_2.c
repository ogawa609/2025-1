#include <stdio.h>
#define true 1
#define false 0


int ChecarMes(int month);
int ChecarDia(int day, int month, int year);
int ChecarBissexto ( int year);
int RetornaUltimoDia (int month, int year);


typedef struct Date{
    int day;
    int month;
    int year;
}Data;

int RetornaUltimoDia(int month, int year){

    if(ChecarBissexto(year)){

        if(month==2){

            return 29;
        }

        else if(month==4||month==6||month==9||month==11){

            return 30;
        }

        else{

            return 31;
        }
    }

    else{

        if(month==2){

            return 28;
        }

        else if(month==4||month==6||month==9||month==11){

            return 30;
        }

        else{

            return 31;
        }

    }
}

int ChecarBissexto ( int year){

    if(year%1000==0){

        if(year%400==0){

            return true;
        }

        return false;
    }

    else{

        if(year%4==0){

             return true;
         }

        return false;
    }
}

int ChecarMes (int month){

    if (month>12){

        return 12;
    }
    else{

        return month;
    }
}

int ChecarDia(int day, int month, int year){

    if(ChecarBissexto(year)){

        if(month==2){

            if(day>=1&&day<=29){

                return day;
            }

            else{

                return 29;
            }
        
    }
    else if(month==4||month==6||month==9||month==11){

        if(day>=1&&day<=30){

            return day;
        }

        else{

            return 30;
        }
        
    }

    else if(month>12){

        if(day>=1&&day<=31){

            return day;
        }

        else{

            return 31;
        }
    }

    else{

        if(day>=1&&day<=31){

            return day;
        }

        else{

            return 31;
        } 
    }

}

else{

    if(month==2){

        if(day>=1&&day<=28){

            return day;
        }

        else{

            return 28;
        }
    
}
else if(month==4||month==6||month==9||month==11){

    if(day>=1&&day<=30){

        return day;
    }

    else{

        return 30;
    }
    
}

else if(month>12){

    if(day>=1&&day<=31){

        return day;
    }

    else{

        return 31;

    }
}

else{

    if(day>=1&&day<=31){

        return day;
    }

    else{

        return 31;
    } 
}
}
}





int main (){

    Data di;
    Data df;
    int contar_mes;
    int contar_dia;
    int contar_ano;


    scanf("%d %d %d",&di.day,&di.month,&di.year);
    scanf ("%d %d %d",&df.day,&df.month,&df.year);

    di.month=ChecarMes(di.month);
    di.day=ChecarDia(di.day,di.month,di.year);
    df.day=ChecarDia(df.day,df.month,df.year);
    df.month=ChecarMes(df.month);

    contar_mes=di.month;
    contar_dia=di.day;
    contar_ano=di.year;

    while(contar_ano<=df.year){

        if(contar_ano==df.year){

            do{

                if(contar_mes==df.month){

                    while(contar_dia<df.day){

                printf("'%02d/%02d/%d'\n",contar_dia,contar_mes,contar_ano);

                contar_dia++;
            }

                return 0;
                }

                else{
            
            while(contar_dia<=RetornaUltimoDia(contar_mes,contar_ano)){

                printf("'%02d/%02d/%d'\n",contar_dia,contar_mes,contar_ano);

                contar_dia++;
            }

            contar_dia=1;
            contar_mes++;

        }
    }
        while(contar_mes<=df.month);

        }

        do{
            
            while(contar_dia<=RetornaUltimoDia(contar_mes,contar_ano)){

                printf("'%02d/%02d/%d'\n",contar_dia,contar_mes,contar_ano);

                contar_dia++;
            }

            contar_dia=1;
            contar_mes++;

        }
        while(contar_mes<=12);

        contar_mes=1;
        contar_ano++;
    }


    
return 0;
}

