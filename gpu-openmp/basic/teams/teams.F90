program main
    !! TODO 1: add openmp support with use statement

    !! TODO 2: execute the print statement in target teams region on device

       print*,omp_get_team_num(), omp_get_num_teams()

       !! execute with ./a.out | sort -n 

end program main

