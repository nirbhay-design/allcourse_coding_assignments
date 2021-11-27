program part1
    implicit none
    
    character(len = 30) :: mystring

    print *,"enter a string " 
    read(*,'(A)') mystring
    !mystring = "nirbhay sharma" 
    print *,"you entered :" , mystring

end program part1