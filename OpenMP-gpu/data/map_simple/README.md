# map 1 simple map clauses

INTERATIVE:

Create an idev session on a gpu node:
Vista:   idev -m 20 -p gh-dev-64k
LS6:     idev -m 20 -p gpu-a100-small

OR

BATCH:

You can compile on the login and
submit the job script (use "job" in directory above) to execute the "a.out".

=========================================================================



Use the map clause to evaluate the effects of "tofrom", "to" and "from" map types.
Compile and run `map1(.cpp|.F90)` for each case.

1.) Look over the code.  It assigns values to the "a" array.
    Map the "a" array for each map type.
    Compile and run each time you change the map, and make sure
    the results are as you would expect. TODO 1a-c:
    (What is the default mapping?)

2.) Remove any map clauses, and include the defaultmap(none) clause
    This is like "implicit none" in the Fortan language. TODO 2:
    Compile:
    What did the compiler state?  ** see below

    After the defaultmap(none) include map(from:a)
    Compile and run.

3.) Now, just use the defaultmap clause to set ALL
    OpenMP "aggregate" types (an OpenMP variable-category)
    to an implicit behavior map type of "from". TODO 3:


     Hint: defaultmap(map type: variable-category) 

     You can always override the default map by
     including a map for specific variables:
     e.g., defaultmap(to:aggregate) map(from:a) 
     will override the default for a.


** nvhpc compiler does not recognize defaultmap(none), and uses default mapping.
   (This will be reported to NVIDIA.)
   LLVM give this error:
```
1.cpp:14:6: error: variable 'a' must have explicitly specified data sharing attributes, data mapping attributes, or in an is_device_ptr clause
   14 |    { a[0]=1; a[1]=2;}
      |      ^
1.cpp:11:4: note: explicit data sharing attribute, data mapping attribute, or is_device_ptr clause requested here
   11 |    #pragma omp target defaultmap(none)
      |    ^
1 error generated.
```


```
./a.out
```
