#include <stdio.h>

int main() {
  float temp, TempConvert;
  char unid;
  scanf("%f %c", &temp, &unid);
  
  if (unid == 'C'){
    TempConvert = (temp * 1.8)+32;
    printf("%.2f (F)", TempConvert);
  }
  if (unid=='c'){
     TempConvert = (temp * 1.8)+32;
     printf("%.2f (f)", TempConvert);
  }
  if (unid=='F'){
    TempConvert = (temp - 32)/1.8;
    printf("%.2f (C)", TempConvert);
  }
  if (unid=='f'){
    TempConvert = (temp - 32)/1.8;
    printf("%.2f (c)", TempConvert);
  }
  
  return 0;
}

