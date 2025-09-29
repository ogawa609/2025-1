#include <stdio.h>

int main(){

    int N;
    int i;
    int temp=0;
    int menor=0;
    
    scanf("%d",&N);

    if(N==1){
        printf("IMPOSSIVEL");
        return 0;
    }

    int poste[N];
    int sub[N-1];

    for(i=0;i<N;i++){

        scanf("%d",&poste[i]);
    }

    for(int j=0;j<N;j++){
        if(j==0){
            temp=poste[j];
            continue;
        }

        sub[j-1]= (temp-poste[j])*(temp-poste[j]);
        temp=poste[j];

    }

   temp=sub[0];

  for(int k =1; k<N-1;k++){

    if(temp<sub[k]){
        menor=k;
    }
    temp=sub[k];
}

for(int l=0; l<N-1;l++){
    if(sub[menor]==sub[l]){
        printf("(%d %d) ",l, l+1);
    }
}

return 0; 
}
