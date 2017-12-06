!!*********************************************************************
!! No Copyright - this is Freeware
!!*********************************************************************
!! File:       CnM.f
!! Author:     Xie Wei Bao
!! Email:      tech@cup.btinternet.co.uk
!!
!! Purpose:
!! Cannibals and missionaries
!!
!! Three missionaries and three cannibals seek to cross a river.  A boat
!! is available which will hold two people and which can be navigated
!! by any combination of missionaries and cannibals involving one or
!! two people.  The cannibals on either bank should not at any time
!! outnumber the missionaries.  The program works out a schedule of
!! crossings that will permit all members of both parties to cross the
!! river safely.
!!
!! This is a Fortran77 conversion of an Algol 60 program I wrote
!! on 15 Dec 1976 as part of the AI module in my Computer Science
!! degree course.  It is an example of how the alpha-beta technique
!! is used.
!!
!!*********************************************************************
      program main
!      include 'CnM.h'
      integer steps
      call Initialize
      call FormPath
      call GetBestPath (steps)
      call PrintPath (steps)
      stop
      end
!**********************************************************************
! Form path.  All the boat combinations are attempted on a node.
! Any legal ones are checked for uniqueness.  If they are unique,
! they will be inserted into the list of nodes.
!**********************************************************************
      subroutine FormPath
      implicit none
!     parameters
!     common
      include 'CnM.h'
!     local
      integer expnd  ! expanded nodes
      logical across ! true when everyone is across
      logical unique ! true if the node is unique
      integer temp(ixLo:ixHi)
      integer op
      integer i
      external GeNz
      logical GeNz

      across = .false.
      expnd = 1
      do while (expnd .lt. unexp .and.
     &          unexp .le. nodemax .and.
     &          .not. across)
          temp(ixParent) = expnd
          temp(ixDirn) = -node(expnd,ixDirn)
!         apply the operators held in boat
          op = 1
          do while (op .le. opmax .and. .not. across)
              if (boat(op,miss) .le. node(expnd,-temp(ixDirn)) .and.
     &            boat(op,cann) .le. node(expnd,-2*temp(ixDirn))) then
!                 operator valid for this node
                  temp(optm) = boat(op,miss)
                  temp(optc) = boat(op,cann)
!                 apply the operator and check goal
                  across = goal(ixDirn) .eq. temp(ixDirn)
                  do 30 i = -cann, cann, 1
                      if (i .eq. 0) goto 30
                      temp(i) = node(expnd,i) +
     &                    isign(1, i) * temp(ixDirn)* boat(op,iabs(i))
                      across = across .and. goal(i) .eq. temp(i)
30                continue
                  if (across) then
!                     Everyone across: goal achieved
                      call InsertNode(temp)
                  else if (genz(temp(lmiss), temp(lcann)) .and.
     &                     genz(temp(rmiss), temp(rcann))) then
!                     combination is valid: is it unique?
                      unique = .true.
                      i = unexp - 1
                      do while (i .gt. 0 .and. unique)
!                         no checks are made on columns -1 and -2
!                         since they are dependent on columns 1
!                         and 2
                          unique = temp(rmiss) .ne. node(i,rmiss) .or.
     &                             temp(rcann) .ne. node(i,rcann) .or.
     &                             temp(ixDirn) .ne. node(i,ixDirn)
                          i = i - 1
                      enddo
                      if (unique) call InsertNode(temp)
                  endif
              endif
!             move to next operator
              op = op + 1
          enddo

!         move to the next unexpanded item
          expnd = expnd + 1
      enddo
      return
      end
!**********************************************************************
! Check if a path is legal - Greater than or equal to and Non Zero
!**********************************************************************
      logical function GeNz (iMissionary, iCannibal)
      implicit none
!     parameters
      integer iMissionary, iCannibal

      GeNz = (iMissionary .eq. 0) .or.
     &       (iMissionary .ge. iCannibal .and. iMissionary .ne. 0)
      return
      end
!**********************************************************************
! Get the path
!**********************************************************************
      subroutine GetBestPath (oSteps)
      implicit none
!     parameters
      integer oSteps
!     common
      include 'CnM.h'
!     local
      integer i

!     work backwards to find the parent from the last
!     unexpanded node
      oSteps = 1
      path(oSteps) = unexp - 1
      i = oSteps + 1
      do while (path(oSteps) .ne. 0)
          path(i) = node(path(oSteps),ixParent)
          oSteps = i
          i = i + 1
      enddo
      return
      end
!**********************************************************************
! Initialize the globals
!**********************************************************************
      subroutine Initialize
!     parameters
!     common
      include 'CnM.h'
!     local
      integer temp(ixLo:ixHi)
      
      unexp = 1              ! First unexpanded node
      temp(lmiss) = 3
      temp(lcann) = 3
      temp(rmiss) = 0
      temp(rcann) = 0
      temp(ixDirn) = boatLeft
      temp(ixParent) = 0
      temp(optc) = 0
      temp(optm) = 0
      call InsertNode (temp)
      
!     Valid combinations
      boat(1,miss) = 0
      boat(1,cann) = 2
      
      boat(2,miss) = 0
      boat(2,cann) = 1
      
      boat(3,miss) = 1
      boat(3,cann) = 1

      boat(4,miss) = 1
      boat(4,cann) = 0

      boat(5,miss) = 2
      boat(5,cann) = 0

!     Target to be achieved
      goal(lmiss) = 0
      goal(lcann) = 0
      goal(ixDirn)  = boatRight
      goal(rmiss) = 3
      goal(rcann) = 3
      return
      end
!**********************************************************************
! Insert one array into another
!**********************************************************************
      subroutine InsertNode (iTemp)
      implicit none
!     common
      include 'CnM.h'
!     parameters
      integer iTemp(ixLo:ixHi)
!     local
      integer i

      do 10 i = ixLo, ixHi, 1
          node(unexp,i) = iTemp(i)
10    continue
      unexp = unexp + 1
      return
      end
!**********************************************************************
! Print the path
!**********************************************************************
      subroutine PrintPath (iSteps)
      implicit none
!     parameters
      integer iSteps
!     common
      include 'CnM.h'
!     local
      integer i, j
      character*12 direction(boatLeft:boatRight)
      
      direction(boatLeft)  = '   -<<<<<-  '
      direction(boatRight) = '   ->>>>>-  '
      
      print *,'Initially, everyone is on the left bank'
      print *,'Msnry = number of missionaries'
      print *,'Cnnbl = number of cannibals'
      print *
      print *,'  Schedule   Direction       After Crossing'
      print *,'             of Travel   Left Bank  Right Bank'
      print *
      print *,'Msnry Cnnbl             Msnry Cnnbl Msnry Cnnbl'
      do 10 j = iSteps - 1, 1, -1
          i = path(j)
          print '(i4,i6,2x,a12,i4,3i6)',
     &        node(i,optm), node(i,optc),
     &        direction(node(i,ixDirn)),
     &        node(i,lmiss), node(i,lcann),
     &        node(i,rmiss), node(i,rcann)
10    continue
      return
      end

