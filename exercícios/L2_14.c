#include <stdio.h>
int main(){
  char entrada;
  int Resp=1;
  do{
    scanf("%c",&entrada);
    if(Resp){
      printf("RESP: ");
      Resp=0;
    }
    if(entrada==' '){
      continue;
    }
      else if(entrada=='!'||entrada=='.'||entrada=='?'){
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
