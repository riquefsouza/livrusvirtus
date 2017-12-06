!     WriteBmp
!
!     Create a bmp file.
!     This code assumes integer*2 takes up 2 bytes: not the space
!     taken by 2 integers.  If the implementation is such that it
!     takes up the space of 2 integers, lots of declarations will
!     have to be changed
!
!     Many of the numbers are hard coded: no excuse except laziness
!
!     Maximum image size is 32x32.  If it is
!     Any bigger, change all arrays preceded by !!!!!!CHANGE
!**********************************************************************
      program main
!     Common Blocks
!     Locals
!!!!!!CHANGE
      integer image(32,32)
      integer imageHeight, imageWidth
      
      call CreateImage (image, imageHeight, imageWidth)
      call CreateBmp ('criss.bmp', image, imageHeight, imageWidth)
      stop
      end
!**********************************************************************
!     Create a dummy image
!**********************************************************************
      subroutine CreateImage (oImage, oHeight, oWidth)
      implicit none
!     Parameters
!!!!!!CHANGE
      integer oImage(32,32)
      integer oHeight
      integer oWidth
!     Common Blocks
!     Locals
      integer x, y

!     Clear the image
      oHeight = 16
      oWidth = 16
      do 20 x = 1, oWidth, 1
          do 10 y = 1, oHeight, 1
              oImage(x,y) = 0
10        continue
20    continue
!     Draw a cross
      do 30 x = 1, oWidth, 1
          oImage(x,x) = 1
          oImage(oWidth - x + 1, x) = 1
30    continue
!     Put a line at the top
      do 40 x = 1, oWidth, 1
          oImage(x,3) = 1
40    continue
!     Put a line at the side
      do 50 y = 1, oHeight, 1
          oImage(5,y) = 1
50    continue
      return
      end
!**********************************************************************
!     Create a bitmap
!**********************************************************************
      subroutine CreateBmp (iFilename, iImage, iWidth, iHeight)
      implicit none
!     Parameters
      character*(*) iFilename
!!!!!!CHANGE
      integer iImage(32,32)
      integer iHeight
      integer iWidth
!     Common Blocks
!     Locals
      integer fhand
      
      fhand = 10
!     try
          open (
     &        unit = fhand,
     &        file = iFilename,
     &        status = 'UNKNOWN',
     &        access = 'DIRECT', ! Otherwise it assumes a record header
     &        form = 'UNFORMATTED',
     &        recl = 1,
     &        err = 100)
          goto 200
!     catch
100       print *, 'Unable to open ', iFilename
          return
!     end catch
200   continue

      call CreateBmpInfo (fhand, iWidth, iHeight)
      call CreateBmpColours (fhand)
      call CreateBmpData (fhand, iImage, iWidth, iHeight)
      call CreateBmpFile (fhand)
      return
      end
!**********************************************************************
!**********************************************************************
      subroutine CreateBmpFile (iHand)
      implicit none
!     Parameters
      integer iHand
!     Common Blocks
      include 'BitMap.h'
!     Locals

      bfType = 'BM'
!     bfSize is set by CreateBmpData
      bfReserved = 0
      bfOffBits = 62
      write (iHand, rec=1) bfType, bfSize, bfReserved, bfOffBits
      return
      end
!**********************************************************************
!     Write Bmp Info Header to the file
!**********************************************************************
      subroutine CreateBmpInfo (iHand, iWidth, iHeight)
      implicit none
!     Parameters
      integer iHand
      integer iWidth
      integer iHeight
!     Common Blocks
      include 'BitMap.h'
!     Locals
      integer scanwidth
      
      biSize = 40            ! Size of BITMAPINFOHEADER
      biWidth = iWidth
      biHeight = iHeight
      biPlanes = 1           ! for a 2 colour bitmap
      biBitCount = 1         ! for a 2 colour bitmap
      biCompression = 0      ! no compression
!     Minimum number of bytes
      scanwidth = ((biWidth - 1) / 8 + 1)
!     Scan width must be a multiple of 4
      scanwidth = ((scanwidth - 1) / 4 + 1) * 4
      biSizeImage = scanwidth * iHeight
      biXPelsPerMeter = 3780 ! Some random figure that MS chooses
      biYPelsPerMeter = 3780
      biClrUsed = 0          ! for a 2 colour bitmap
      biClrImportant = 0     ! for a 2 colour bitmap
      bmpPosn = 55           ! where the colour table starts
      write (iHand, rec = 15)
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
     &    biClrImportant
      return
      end
!**********************************************************************
!     Write the data to the file.  This is written backwards because
!     .bmp format stores everything backwards
!**********************************************************************
      subroutine CreateBmpData (iHand, iImage, iHeight, iWidth)
      implicit none
!     Parameters
      integer iHand
!!!!!!CHANGE
      integer iImage(32,32)
      integer iHeight
      integer iWidth
!     Common Blocks
      include 'BitMap.h'
!     Locals
      integer row, col
!!!!!!CHANGE At least iImage xmax / 32
      character bmp(32)*1
      integer ix, ixmax, posninc, patn
      
      ixmax = ((biWidth - 1) / 8 + 1)
!     Get the nearest number of 32-bit words
      ixmax = ((ixmax - 1) / 4 + 1) * 4

      do 30 row = iHeight, 1, -1
          do 10 ix = 1, ixmax, 1
              bmp(ix) = char (0)
10        continue
          ix = 1
          patn = 0
          do 20 col = 1, iWidth, 1
              patn = iShft (patn, 1)
!             0 = black, 1 = white
              if (iImage(col,row) .eq. 0)
     &            patn = iOr (patn, 1)

              if (mod (col, 8) .eq. 0) then
                  bmp(ix) = char (patn)
                  patn = 0
                  ix = ix + 1
              endif
20        continue
          write (iHand, rec = bmpPosn) (bmp(ix), ix = 1, ixmax, 1)
          bmpPosn = bmpPosn + ixmax
30    continue
      bfSize = bmpPosn - 1
      return
      end
!**********************************************************************
!     Set the colours
!**********************************************************************
      subroutine CreateBmpColours (iHand)
      implicit none
!     Parameters
      integer iHand
!     Common Blocks
      include 'BitMap.h'
!     Locals
      character*1 red, green, blue, reserved

!     bmpPosn is initialized in CreateBmpInfo
!     Set up for B/W bitmap
      bcColours = 2
      bcIxPerByte = 8
      bcBitsPerIx = 1
!     Black
      red = char(0)
      green = char(0)
      blue = char(0)
      reserved = char(0)
      write (iHand, rec = bmpPosn) blue, green, red, reserved
      bmpPosn = bmpPosn + 4
!     White
      red = char(255)
      green = char(255)
      blue = char(255)
      write (iHand, rec = bmpPosn) blue, green, red, reserved
      bmpPosn = bmpPosn + 4
      return
      end

