! Cannibals and Missionaries
!
! Header file for common blocks
! What we are trying to achieve here is structures.  Unfortunately,
! Fortran77 does not have structures so we just use array indices
! and a two dimensional array as an array of structures.
!**********************************************************************
!     Indices
      integer ixDirn, ixParent, optm, optc
      integer miss, cann, lmiss, lcann, rmiss, rcann
      integer boatLeft, boatRight
      integer ixLo, ixHi, nodemax, opmax
      parameter (
     &    ixLo = -2,
     &    ixHi = 5,
     &    lmiss = -1,
     &    lcann = -2,
     &    ixDirn = 0,       ! direction
     &    rmiss = 1,
     &    rcann = 2,
     &    ixParent = 3,       ! parent index
     &    optm = 4,       ! optimum number of missionaries
     &    optc = 5,       ! optimum number of cannibals
     &    miss = 1,
     &    cann = 2,
     &    boatLeft = -1,   ! boat on left bank
     &    boatRight = 1,   ! boat on right bank
     &    nodemax = 27, opmax = 5)
      common /CnM/
     &     goal,
     &     boat,
     &     node,
     &     path,
     &     unexp
      integer goal(-cann:cann)         ! goal to be achieved
      integer boat(1:opmax, miss:cann) !  legal boat combinations
      integer node(1:nodemax, ixLo:ixHi)! nodes for obtaining soln
      integer path(1:nodemax)          ! the path taken
      integer unexp                    ! index of next unexpanded node
