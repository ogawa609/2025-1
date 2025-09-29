#include <stdio.h>
#include <stdlib.h>
int main (){
  int dx,dy,ex,ey,px,py;
  scanf("%d %d %d %d %d %d", &dx, &dy,&ex,&ey,&px,&py);
  if (((px>=dx&&px<=ex)||(px>=ex&&px<=dx))&&((py>=dy&&py<=ey)||(py>=ey&&py<=dy)))
  {
    printf ("Dentro");
  }
  else 
  {
    printf ("Fora");
  }
  return 0;
}