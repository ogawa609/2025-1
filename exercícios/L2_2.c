#include <stdio.h>
#include <stdlib.h>

int main(){

int n, m;
    scanf("%d %d", &n,&m);
    int i =n+1;
    while (i<m){
    
        if (i%3==0||i%4==0||i%7==0){ 
            printf("%d ", i);
        }
        i++;
    }

    return 0;
}
