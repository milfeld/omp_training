#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
int a=2, n=1<<4; // 16
//  int x[n], y[n];
// TODO 1:  Comment out above declarations,
//          declare x and y as pointers, and
//          dynamically allocate with malloc
//          Compile
//   
    int *x=(int*)malloc(n*sizeof(n));
    int *y=(int*)malloc(n*sizeof(n));
  for(int i=0;i<n;i++){ x[i]=1; y[i]=1; }

  // TODO 1a: Offload axpy with target construct (only)
  //         Compile and run.
  //

  // TODO 2: map x and y as array section.
  //         FYI: only one thread executes the loop
  //         Compile and run.

  #pragma omp target 
  for(int i=0;i<n;i++) y[i]=a*x[i]+y[i];


  for(int i=0; i<n; i++) assert(y[i]==3);//Validate

  printf("Passed OpenMP %d\n", _OPENMP);
  // TODO 3:  Do axpy on last half of vectors
  //          Modify map, axpy loop and the validate loop
}
