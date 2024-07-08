# Hello world with OpenMP offloading

INTERATIVE:

Create an idev session on a gpu node:
Vista:   idev -m 20 -p gh-dev-64k
LS6:     idev -m 20 -p gpu-a100-small

OR

BATCH:

You can compile on the login and 
submit the job script (use "job" in directory above) to execute the "a.out".

=========================================================================

Compile and run the simple OpenMP `hello(.c|.F90)` with/without offloading.

1.) Look over the code.
    What is the purpose of omp_is_init_device()?
    What is the purpose of omp_is_init_device()?

2.) Compile the code, as is, without any openmp support.
    (Vista:  nvc++ | nvfortran -fopenmp -mp=gpu                  hello.cpp|F90)
    (ls6:   clang++|   flang   -fopenmp -fopenmp-targets=nvptx64 hello.cpp|F90)
    What is the problem?
    Hint:  openmp functions have no support without turning on compiler support
           Comp. support and header|use (C/C++|F90) files are required.

3.) Correct so that openmp functions are supported.
    Compile code with JUST openmp support and run.
    (Vista:  nvc++ | nvfortran -fopenmp  hello.cpp|F90)
    (ls6:   clang++|   flang   -fopenmp  hello.cpp|F90)

    Run a.out:
    How many devices did it find?
    Did it run on the host or a device? NO, because we have no target constructs?

4.) Now let's instrument it to run on the device, 
    Execute the code block below the TODO2: comment on the GPU
    with an appropriate target construct without any clauses,
    and compile with
    (Vista:  nvc++ | nvfortran -fopenmp -mp=gpu                  hello.cpp|F90)
    (ls6:   clang++|   flang   -fopenmp -fopenmp-targets=nvptx64 hello.cpp|F90)

    Compile and run.
          
    How many devices did it find?
    Did the TODO2: block run on the device (GPU)?

5.) Now turn off offloading with the OMP_TARGET_OFFLOAD variable,
    and show that it works:

       export OMP_TARGET_OFFLOAD=disabled
       ./a.out

    Where did it run? 
    FYI:  You can also require aborting, to avoid target 
          fallback executions on the host (for whatever reason)
          by setting OMP_TARGET_OFFLOAD=mandatory.

******** DON'T FORGET TO UNSET OMP_TARGET_OFFLOAD
                         unset OMP_TARGET_OFFLOAD

```
#!/bin/bash
#                       **** FILL IN account, reservation, and partition ****
#SBATCH --job-name=hello
#SBATCH --account=
#SBATCH --reservation=
#SBATCH --partition=
#SBATCH --time=00:05:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1

./a.out
```
