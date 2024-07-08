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


Change the X and Y arrays to dynamic arrays (C|C++: malloc)
and map the pointer and the pointee storage with array sections.

Compile and run `array_section.cpp

------------------------------------------------------------

1.) Look over the code.  
    TODO 1a. Offload the axpy loop with a target construct.
    Array X and Y are mapped implicitly in the target region.
    (You can compile and run the codes, as is; it will work.)

    TODO 1b.
    Allocate X and Y as dynamic arrays (do nothing more). 

    Compile the code and run, as is, with one thread on target
       Did is work?  (for NVHPC, they make it work, but is is no compliant)
                     (for LLVM, the code correctly has a runtime error.)

   2.) Fix it by including an explicit map clause
       with an array section which maps the pointer and 
       the data pointed to. TODO 2:
       (hint:  array section format: map(ptr[<start>:<#of elements>])
       Compile and run.

       If you didn't use a map-type (to|from|tofrom)
       to minimize transfers, do that, and run again.

   3.) Now, only map elments n/2 to n-1, and
       perform the axpy on the mapped elements. 
       (Also fix the assert.)

   4.) Try setting a stride (2) and compiling. 
       Does it work on this versions of the compiler?
       (UH!, neither nvhpc nor llvm support striding yet.)

```
./a.out
```
