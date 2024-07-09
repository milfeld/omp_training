#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
void fun1(int *ptr){ for (int i=0; i<N; i++) ptr[i] = i; }
int main()
{
  int *ptr;
  ptr = (int *)malloc(sizeof(int)*N);
  for(int i=0;   i<N; i++) ptr[i]=i;

//  TODO 1  offload the the fun1, and map the pointer (ptr)
//
//  TODO 2  Map and array section of size N (offset of 0)
//          in an optimal way.

  #pragma omp target map(from: ptr[0:N])
//#pragma omp target map(ptr)
  {
    fun1(ptr);
  }

  for(int i=0;   i<N; i++) assert(ptr[i]==i  ); // validate loop

}
