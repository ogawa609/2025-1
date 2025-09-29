#include <stdio.h>

int main (){
  int  n, p, resto;
  float teste;
  
  scanf("%d %d",&n, &p);
  
  if(p==3)
  {
  	teste= (float)n/100;
  	resto = ((int)teste)%2;
  	
  	if (resto==0)
  	{
   	printf("PAR");
   	}
   	else{
   	printf("IMPAR");
   	}
   }
   if(p==2)
   {
   	teste= (float)n/10;
  	resto = ((int)teste)%2;
  	
  	if (resto==0)
  	{
   	printf("PAR");
   	}
   	else{
   	printf("IMPAR");
   	}
   }
   if(p==1)
   {
  	resto = n%2;
  	
  	if (resto==0)
  	{
   	printf("PAR");
   	}
   	else{
   	printf("IMPAR");
   	}
   }
  
  return 0;
}

