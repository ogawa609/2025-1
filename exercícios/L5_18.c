#include <stdio.h>

int main(){

   int n;

   scanf("%d",&n);

   int l1,l2,c1,c2;

   for(int casos=0;casos<n;casos++){

        scanf("%d %d",&c1,&l1);
        int A[l1][c1];

        for(int a1=0; a1<l1;a1++){
            for(int a2=0; a2<c1; a2++){

                scanf("%d",&A[a1][a2]);
            }


        }

        scanf("%d %d",&c2,&l2);
        int B[l2][c2];

        for(int b1=0;b1<l2;b1++){
            for(int b2=0; b2<c2;b2++){

                scanf("%d",&B[b1][b2]);
            }
        }

        if(c1!=l2){
            printf("IMPOSSIVEL\n");
        }

        else{

            int C[l1][c2];
            for(int lc1=0;lc1<l1;lc1++){

                for(int cc2=0; cc2<c2;cc2++){

                    C[lc1][cc2]=0;
                    for(int k=0;k<c1;k++){

                        C[lc1][cc2]+=A[lc1][k]*B[k][cc2];
                    }
                }
            }
        

         for (int i = 0; i < l1; i++) {
                for (int j = 0; j < c2; j++) {
                    printf("%d", C[i][j]);
                    if (j < c2 - 1) printf(" ");
                }
                printf("\n");
            }

        }
        
   }

   return 0;

}