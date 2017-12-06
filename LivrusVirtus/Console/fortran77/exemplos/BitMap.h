!     BmpMap.h
!
!     Bitmap file header
***********************************************************************
      common /BitMap/
     &    bfSize,
     &    bfReserved,
     &    bfOffBits,
     &    biSize,
     &    biWidth,
     &    biHeight,
     &    biPlanes,
     &    biBitCount,
     &    biCompression,
     &    biSizeImage,
     &    biXPelsPerMeter,
     &    biYPelsPerMeter,
     &    biClrUsed,
     &    biClrImportant,
     &    bcColours,
     &    bcIxPerByte,
     &    bcBitsPerIx,
     &    bmpPosn,
     &    bfType     ! Smallest so it must appear last

!     type:: BmpFileHeader
          character*2 bfType
          integer*4 bfSize
          integer*4 bfReserved ! actually Reserved1 & 2
          integer*4 bfOffBits
!     end type BmpFileHeader

!     type:: BmpInfoHeader
          integer*4 biSize
          integer*4 biWidth
          integer*4 biHeight
          integer*2 biPlanes
          integer*2 biBitCount
          integer*4 biCompression
          integer*4 biSizeImage
          integer*4 biXPelsPerMeter
          integer*4 biYPelsPerMeter
          integer*4 biClrUsed
          integer*4 biClrImportant
!     end type BmpInfoHeader
!
!     Some variables for colours
      integer bcColours    ! number of colours
      integer bcIxPerByte  ! colour indices per byte
      integer bcBitsPerIx  ! bits per colour index
      integer bmpPosn

