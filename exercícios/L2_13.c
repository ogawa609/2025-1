#include <stdio.h>
int main(){
  char entrada;
  do{
    scanf("%c", &entrada);
    if(entrada>=97&&entrada<=122){
      entrada=entrada-32;
      printf("%c", entrada);
    }
    else if(entrada=='?'||entrada=='!'||entrada=='.'){
      printf("%c",entrada);
      break;
    }
    else{
      printf("%c",entrada);
    }
  }
    while(1);

return 0;
}
