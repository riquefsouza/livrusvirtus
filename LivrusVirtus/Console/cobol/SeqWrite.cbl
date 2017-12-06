        IDENTIFICATION DIVISION.
        PROGRAM-ID.  SeqWrite.
        AUTHOR.  Michael Coughlan.
        
        ENVIRONMENT DIVISION.
        INPUT-OUTPUT SECTION.
        FILE-CONTROL.
            SELECT StudentFile ASSIGN TO "STUDENTS.DAT"
        		ORGANIZATION IS LINE SEQUENTIAL.
        
        DATA DIVISION.
        FILE SECTION.
        FD StudentFile.
        01 StudentDetails.
           02  StudentId       PIC 9(7).
           02  StudentName.
               03 Surname      PIC X(8).
               03 Initials     PIC XX.
           02  DateOfBirth.
               03 YOBirth      PIC 9(2).
               03 MOBirth      PIC 9(2).
               03 DOBirth      PIC 9(2).
           02  CourseCode      PIC X(4).
           02  Grant           PIC 9(4).
           02  Gender          PIC X.
        
        PROCEDURE DIVISION.
        Begin.
           OPEN OUTPUT StudentFile.
           DISPLAY "Enter student details using template below. ".
           PERFORM GetStudentDetails.
           PERFORM UNTIL StudentDetails = SPACES
              WRITE StudentDetails
              PERFORM GetStudentDetails
           END-PERFORM.
           CLOSE StudentFile.
           STOP RUN.
        
        GetStudentDetails.
           DISPLAY "NNNNNNNSSSSSSSSIIYYMMDDCCCCGGGGS".
           ACCEPT  StudentDetails.
