; WRITTEN IN TASM (Turbo Assembler)
.MODEL TINY
CODE SEGMENT
ASSUME CS:CODE, DS:CODE
ORG 100h
START:
        mov ah,9
        mov dx,OFFSET Msg
        int 21h
        int 20h
        Msg DB 'Hello World',13,10,'$'
CODE ENDS
END START 
