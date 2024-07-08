#include <stdio.h>
int main(){
   int a[2]={9,9};

   // TODO 1a:  map the data tofrom (same as implicit)
   // TODO 1b:  map the data from   (optimal)
   // TODO 1c:  map the data to     (not what you want)
   // TODO 2:  specify defaultmap(none)  only
   // TODO 3:  specify defaultmap(from:aggregate) only

   { a[0]=1; a[1]=2;}

   printf("%d %d\n",a[0], a[1]);
}
