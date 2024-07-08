# Hello world with OpenMP offloading
INTERATIVE:

Create an idev session on a gpu node:
Vista:   idev -m 20 -p gh-dev-64k
LS6:     idev -m 20 -p gpu-a100-small

OR

BATCH:

You can compile on the login and
submit the job script (use "job" in directory above) to execute the "a.out".

==========================================================================


Offload and create teams for statements in the code block that
captures (and reports) the number of teams and the team number 
with/without specifying the number of teams. Code is teams(.cpp|.F90)

1.) Look over the code.
    
    TODO 1:  Make sure you have the OpenMP header/lib.

    Try compiling code, as is, with the -fopenmp and run it.
    Does the initial thread of the program run as a team?

    What are the number of teams for the initial thread?

    You can also create a league of teams for the CPU
    (#pragma omp teams | !$omp teams), but we are not
    interested in that here.
    

2.) Offload and create teams for the statement that
    prints (CPP version) or capture (F90) the number of
    teams and team numbers.  

    (**Fortan print on devices is limited, that is why the
    information is captured, and printed from the host)

    Hints   use the combined target teams construct,

    How many teams are created by default for CPP code,
    and F90?

3.) Now, add a num_teams clause and specify the number of teams equal to
    to something less than all the available SMs 
    (132 for vista gh; 108 for ls6 A100) teams.

    Compile and run to check your clause insertion.

         ./a.out | sort 
          

```
#!/bin/bash
#SBATCH --job-name=teams
#SBATCH --reservation=
#SBATCH --account=
#SBATCH --partition=
#SBATCH --time=00:05:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1

srun ./a.out
```
