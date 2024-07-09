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


When a pointer is passed through a function to be used to access data it
is pointing to, an array section must be used to specifying the extent of
the pointee (data pointed to).  Without explicit mapping, the pointer is
first private, and is attached to the pointee data of the array section.



1.) Look over the simple code.  
    TODO 1. Offload the function call and just map the pointer (ptr).
    Compile and execute.

    What is the runtime message.

2.) 
    TODO 2. Map an array section starting at an offset of zero,
    with an extent of N, and an optimal way.
    Compile and execute.

    Does it run correctly?

    If you mapped: map( ptr[2:N-1] )
    would it be valid for the target code to
    access ptr[0] and ptr[1]?  (Answer: no.)
    Optimal mapping would use a from map-type.

```
./a.out
```

