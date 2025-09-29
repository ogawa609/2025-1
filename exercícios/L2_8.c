#include <stdio.h>

int main() {
   int n,m,a,b,c;
   
      
    scanf("%d %d",&n,&m);
    printf("RESP: ");
    
    for(a=n+1;a<m;a++){
        if(n>m){
            break;
        }
        else{
          c=1;
            for(b=2;b<=a/2;b++){  
                if(a%b==0){
                    c=0;
                    continue;
                }
            }
            if(c){
                printf("%d ",a);
            }
          
        }
    
    }
    return 0;
}