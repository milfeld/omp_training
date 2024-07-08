# array section in map clause

INTERATIVE:

Create an idev session on a gpu node:
Vista:   idev -m 20 -p gh-dev-64k
LS6:     idev -m 20 -p gpu-a100-small

OR

BATCH:

You can compile on the login and
submit the job script (use "job" in directory above) to execute the "a.out".

=========================================================================

README_fortran.md

For Fortran allocatable arrays the user-level 
behavior is similar to non-allocatable arrays,
for simple cases (even for fortran pointers).

1.) Look over the code.  
    Array X and Y are mapped implicitly in the target region.
    (You can compile and run the codes, as is; it will work.)

    Declare X and Y as allocatable, and allocate them.

    Compile the code and run, as is, in a target regdion (1 thread)
       It should run fine.  (Although for updates, one may
       need to take care with early versions of OpenMP offloading.
       More on this later.)

   2.) Now, only map elments n/2 to n-1, and
       perform the axpy on the mapped elements. 
       Use fortran array notation for section range.
       (Also fix the validation code.)

   3.) Declare pointers xp and yp, that can point to arrays.
       After allocation of x and y, point to them, and use
       them in the target region.
       Note there is no need to use array sections
       for the Fortran pointers (because, unlike C/C++,
       the pointers contain array info)

   4.) Try setting a stride and compiling. 
       Does it work on this version of the compiler?

```
./a.out
```
