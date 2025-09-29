#include <stdio.h>
int main(){
int x1,y1,x2,y2;
int SDx,SDy,SEx,SEy,IDx,IDy,IEx,IEy;
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
if(x1<x2){
    IDx=x2; 
    IEx=x1;
    SDx=x2;
    SEx=x1;
   
}
else{
    IDx=x1;
    IEx=x2;
    SDx=x1;
    SEx=x2;
}
if(y1<y2){
    
    IDy=y1;
    
    IEy=y1;
    
    SDy=y2;
    
    SEy=y2;
}
else{
    IDy=y2;
    IEy=y2;
    SDy=y1;
    SEy=y1;
}
printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)",SEx,SEy,IEx,IEy,IDx,IDy,SDx,SDy);
return 0;
}