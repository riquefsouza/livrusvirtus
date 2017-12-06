!     OPEN ([UNIT=]unit
!           [,ACCESS=access]
!           [,BLANK=blanks]
!           [,BLOCKSIZE=blocksize]
!           [,ERR=errlabel]
!           [,FILE=file]
!           [,FORM=form]
!           [,IOSTAT=iocheck]
!           [,MODE=mode]
!           [,RECL=recl]
!           [,SHARE=share]
!           [,STATUS=status])
!     unit = Integer expression. Unit number.
!     access = Character expression. 'APPEND', 'DIRECT' or 'SEQUENTIAL' (Default).
!     blanks = Character expression. 'NULL' or 'ZERO'.
!     blocksize = Integer expression. Unit size.
!     errlabel = Integer expression. Label for error
!     file = Character expression. File name.
!     form = Character expression. 'FORMATTED' or 'UNFORMATTED'
!     iocheck = Integer variable. Assign 0 if no error, negative number if EOF or the error number.
!     mode = Character expression. 'READ', 'WRITE' or 'READWRITE'.
!     recl = Integer expression. Record size.
!     share = Character expression. 'DENYRW','DENYWR','DENYRD' or 'DENYNONE'.
!     status = Character expression. 'OLD','NEW' or 'UNKOWN' (Default).
!
!
!     CLOSE ([UNIT=]unit
!            [,ERR=errlabel]
!            [,IOSTAT=iocheck]
!            [,STATUS=status])
!     unit = Integer expression. Unit number.
!     errlabel = Integer expression. Label for error.
!     iocheck = Integer variable. Assign 0 if no error, negative number if EOF or the error number.
!     status = Character expression. 'KEEP' or 'DELETE'.
!
!
!     WRITE ([UNIT=]unit
!            [,[{[FMT=]format] | [NML=]nml }]]
!            [,ERR=errlabel]
!            [,IOSTAT=iocheck]
!            [,REC=rec]) iolist
!     unit = Integer expression. Unit number.
!     format = Integer or character expression. Format specifies.
!     nml = Variables list to write. (Only if iolist omitted)
!     errlabel = Integer expression. Label for error.
!     iocheck = Integer variable. Assign 0 if no error, negative number if EOF or the error number.
!     rec = Integer expression. Write position.
!     iolist = Variables list to write.
!
!
!     READ { { format, | nml } |
!            ([UNIT=]unit
!             [,[{[FMT=] format] | [NML=]nml }]]
!             [,END=endlabel]
!             [,ERR=errlabel]
!             [,IOSTAT=iocheck]
!             [,REC=rec])
!          } iolist
!     unit = Integer expression. Unit number.
!     format = Integer or character expression. Format specifies.
!     nml = Variables list to read. (Only if iolist omitted)
!     endlabel = Integer expression. Label for EOF.
!     errlabel = Integer expression. Label for error.
!     iocheck = Integer variable. Assign 0 if no error, negative number if EOF or the error number.
!     rec = Integer expression. Write position.
!     iolist = Variables list to read.
!
!
!     REWIND { unit |
!              ([UNIT=]unit
!               [,ERR=errlabel]
!               [,IOSTAT=iocheck])
!            }
!     unit = Integer expression. Unit number.
!     errlabel = Integer expression. Label for error.
!     iocheck = Integer variable. Assign 0 if no error, negative number if EOF or the error number.
!
!
!     BACKSPACE {unit |
!                 ([UNIT=]unit
!                  [,ERR=errlabel]
!                  [,IOSTAT=iocheck ]])
!               }
!     unit = Integer expression. Unit number.
!     errlabel = Integer expression. Label for error.
!     iocheck = Integer variable. Assign 0 if no error, negative number if EOF or the error number.
!
!
!     Note: [ ] = optionally items
!           {Item1 | Item2} = item1(s) or Item2(s)

      program Files
      integer day,month,year
      
      print *,day,month,year
      
      day=11
      month=3
      year=2002
      
      open (10,FILE='tmp.dat',FORM='UNFORMATTED')
        write(10) day
        write(10) month
        write(10) year
      close(10)

      print *,day,month,year
      
      day=0;month=0;year=0

      print *,day,month,year
      
      open (20,FILE='tmp.dat',FORM='UNFORMATTED')
        read (20) day
        read (20) month
        read (20) year
      close(20,STATUS='DELETE')
      
      print *,day,month,year
      
      stop
      end
