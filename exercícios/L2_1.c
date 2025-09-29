#include <stdio.h>
#include <stdlib.h>

int main(){

int n, m;
    scanf("%d %d", &n,&m);
    int i =n+1;
     printf("RESP:");
    while (i<m){
    
        if (i%2==0){ 
            printf("%d ", i);
        }
        i++;
    }

    return 0;
}
