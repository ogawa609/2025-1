#include <stdio.h>
#include <stdlib.h>
int main (){
  int a,b;
  float teste;
  
  scanf("%d %d", &a,&b);
  
    if(a>=b)
    {
    printf ("RESP: %d",b);
    }
      
    else 
    {
       teste=b%a;
          if(teste==0)
          {
            printf("RESP: %d", a);
          }
         else {
         printf("RESP: %.0f",teste);
         }
     }
  return 0;
}