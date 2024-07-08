program hello
  !! TODO 1: Add appropriate use statement for OMP functions

  implicit none

  integer :: num_devs
  logical :: init_dev

    num_devs = omp_get_num_devices()
    print *, "Number of available devices", num_devs


   !! TODO 2: execute this block on a device

    if (omp_is_initial_device()) then
      write(*,*) "Running on host"
    else 
      write(*,*) "Running on device"
    end if

end program
