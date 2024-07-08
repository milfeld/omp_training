#include <assert.h>
#include <stdio.h>
//#include <math.h>
#include <stdlib.h>
#include <omp.h>

int main(){
int a=2, n=1<<4; // 16

    int x[n], y[n];
// TODO 1b:  Comment out above declarations,
//          declare x and y as pointers, and
//          dynamically allocate with malloc
//          
  for(int i=0;i<n;i++){ x[i]=1; y[i]=1; }

  // TODO 1a: Create a target region
  //         FYI: only one thread executes the loop
  //         Compile and run. (old compilers may fail when pointer/pointees are not mapped)
  // TODO 2: map x and y as array sections.
  //         Compile and run.
  for(int i=0;i<n;i++) y[i]=a*x[i]+y[i];     // axpy loop


  for(int i=0; i<n; i++) assert(y[i]==3);   // validate loop

  printf("Passed OpenMP %d\n", _OPENMP);

  // TODO 3:  Do axpy on last half of vectors in above code.
  //          Modify map, axpy loop and the validate loop
}
