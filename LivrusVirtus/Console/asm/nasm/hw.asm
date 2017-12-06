;
; Hello World in nasm/NetBSD(aout)
;

; Compile:
;    nasm -f aoutb hw.asm
;    ld -s -o hw hw.o

section .text


_start:
    push    dword len    ; Länge
    push    dword msg    ; Adresse
    push    dword 1      ; Stdout
    mov     eax, 0x4     ; write
    call    _syscall
    add     esp, 12      ; Stack bereinigen

    push    dword 0
    mov     eax, 0x1     ; exit
    call    _syscall

_syscall:
    int     0x80
    ret

msg db      "Hello World",0xa
len equ     $ - msg
