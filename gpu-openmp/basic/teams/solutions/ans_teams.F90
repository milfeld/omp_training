program main
    !! TODO 1: add openmp support with use statement
    use omp_lib

    !! TODO 2: execute the print statement in target teams region on device
    !$omp  target teams  num_teams(132)
!      write(*,'(" team number ",i0.6,"  out of ",i0.6)') omp_get_team_num(), omp_get_num_teams()
       print*,omp_get_team_num(), omp_get_num_teams()
    !$omp end target teams
end program main

