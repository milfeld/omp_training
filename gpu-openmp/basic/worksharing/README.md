# Parallel Work with OpenMP offloading

INTERATIVE:

Create an idev session on a gpu node:
Vista:   idev -m 20 -p gh-dev
LS6:     idev -m 20 -p gpu-a100-small

OR

BATCH:

You can compile on the login and
submit the job script (use "job" in directory above) to execute the "a.out".

=========================================================================

The "target teams distribute parallel for|do" (TTDPF) construct 
(what a long combined directive!) parallelizes a for/do loop across 
teams for threaded execution using a default number of teams and threads.
   o First approach is to just let the compiler decide the
     best combination of thread per team and the number of teams.

1.) Insert the TTDPF directive to offload the axpy operation.

    Compile and run to make sure it work.
```
    (Vista:  nvc++ | nvfortran -fopenmp -mp=gpu                  hello.cpp|F90)
    (ls6:   clang++|   flang   -fopenmp -fopenmp-targets=nvptx64 hello.cpp|F90)
```
    Did you need a header file?  Why not.



2.) Now instrument the file with the included timer.

    a.) insert the declaration:
        CPP:  Instantiate:   Timer_Collector timer;
        F90:  Declare type:  type(Timer_Collector) timer
              (Use the module defined in timer.f90 (mod_timer)
              and define "timer" as type(Timer_Collector).

    b.) Around the TTDPF region, start, stop, and print
        the timer results:
```
        CPP:
        timer.start("    Offload     ");
           ...
        timer.stop();
        timer.print(); 

        F90:
        call timer%start("    Offload     ");
           ...
        call timer%stop();
        call timer%print(); 
```

    c.) Compile and run.
        How much time did it take?
        Remember, data is being moved to the device (in a non-optimal way)

    d.) Now increase the size of the problem by 4x:
      
        change 1<<28  to 1<<30

    e.) Compile and run
        Was the total cost 4x?
        Was most of the time used for data motion?
        (How can you support your answer?
        We will look at that later.)

Include the following code if you want to check the results:

CPP:
```
//Check for rounding errors

//Include following headers and namespace 
//        statement at beginning
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

  //Insert after axpy calculation
  for (int i=0; i<N; i++)
    assert( (fabs(y[i]-3.0f)) < 0.000001);
  cout << " Passed Validation "<< endl;
```

F90:
```
  do i = 1,N 
    if( abs(y(i)-3.0e0) > 0.0000001 ) stop("Failed Validation");  
  enddo
  print*," Passed Validation"

```
