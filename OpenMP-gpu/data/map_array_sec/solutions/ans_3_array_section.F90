program main
  integer, parameter :: n=16
  integer :: a=2, version=0
!!integer, :: x(n), y(n)
  integer, target, allocatable :: x(:), y(:)
  integer, pointer             :: xp(:), yp(:)

!! TODO 1:  Give x and y allocatable attributes
!!          and allocate them dynamically
   allocate( x(n), y(n) )
   xp=>x 
   yp=>y

   do i=1,n; x(i)=1; y(i)=1; enddo  !! init

   !! Create a target region and 
   !! one thread executes the loop
   !! TODO 1: Create a target region and 
   !!         no map required for allocatable arrays
   !!         FYI: one thread executes the loop
   !!         compile and run 


   !! TODO 2:  Do axpy on last half of vectors
   !!          Modify map, axpy loop and the validate loop
   !!          compile and run

   !! TODO 3: Declare pointers xp and yp, and point them to the arrays,
   !!         and use these pointers in the array section map
   !!         and in the target region (instead of the x and y vars).
   !!         Note there is no need to use array sections

   !$omp target map(xp(n/2:n)) map(yp(n/2:n))   !! TODO 3
      do i=n/2,n; yp(i)=a*xp(i)+yp(i); enddo    !! axpy loop
   !$omp end target


   do i=n/2,n; if(y(i) /= 3) stop("y != 3"); enddo  !! validate loop

#ifdef _OPENMP
   print*, "Passed OpenMP ", _OPENMP
#else
   print*, "Passed OpenMP off"
#endif

end program
