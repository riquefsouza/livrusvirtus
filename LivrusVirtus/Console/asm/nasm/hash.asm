;;
;; A Fast and Good Hash Function
;;
;; Algorithm by Bob Jenkins, December 1996
;; (see http://burtleburtle.net/bob/c/lookupa.c for C version)
;;
;; Implemented by Michael Neumann, June 2002.
;;
;; Requires NASM - the Netwide Assembler.
;;

global s_lookup
section .text

%macro mix_line 6
        ;;; parameters: r x y shift temp direction(left|right)
        ;;; r -= x; r -= y; r ^= (y(>>|<<)shift)

        ; r -= x
        sub %1, %2

        ; r -= y
        sub %1, %3

        ; r ^= (y>>shift)
        mov %5, %3
%ifidni %6,left
        shl %5, %4
%else
        shr %5, %4
%endif
        xor %1, %5
%endmacro

%macro mix 4
        ;;; parameters: a b c temp

        ;;;a -= b; a -= c; a ^= (c>>13); 
        mix_line %1, %2, %3, 13, %4, right

        ;;;b -= c; b -= a; b ^= (a<<8); 
        mix_line %2, %3, %1, 8, %4, left

        ;;;c -= a; c -= b; c ^= (b>>13); 
        mix_line %3, %1, %2, 13, %4, right

        ;;;a -= b; a -= c; a ^= (c>>12);  
        mix_line %1, %2, %3, 12, %4, right

        ;;;b -= c; b -= a; b ^= (a<<16); 
        mix_line %2, %3, %1, 16, %4, left

        ;;;c -= a; c -= b; c ^= (b>>5); 
        mix_line %3, %1, %2, 5, %4, right

        ;;;a -= b; a -= c; a ^= (c>>3);  
        mix_line %1, %2, %3, 3, %4, right

        ;;;b -= c; b -= a; b ^= (a<<10); 
        mix_line %2, %3, %1, 10, %4, left

        ;;;c -= a; c -= b; c ^= (b>>15); 
        mix_line %3, %1, %2, 15, %4, right
%endmacro

jump_table: dd case0, case1, case2, case3, case4, case5, case6, case7, case8, case9, case10, case11

; unsigned long s_lookup(void *key, int length, int level)
s_lookup:

%define temp edx        ; temporary register: edx
%define a ecx           ; a 
%define b ebx           ; b
%define c eax           ; c
%define len edi         ; len
%define key esi         ; key

        push    ebp
        mov     ebp, esp
        push    esi
        push    edi
        push    ebx
        push    ecx
        push    edx
        ; --------------------------------------------------------

        mov     key, [ebp+8]            ; first argument (key)

        ; Set up the internal state

        ;;; len = length
        mov     len, [ebp+12]           ; second argument (length)

        ;;; a = b = 0x9e3779b9 
        mov     a, 9e3779b9h
        mov     b, a

        ;;; c = level
        mov     c, [ebp+16]

        ;;; while (len >= 12)
while:
        cmp len, 12
        jl near end_while                  ; exit if len < 12

        ;;; a += (k[0] +((ub4)k[1]<<8) +((ub4)k[2]<<16) +((ub4)k[3]<<24));
        add a, [key]

        ;;; b += (k[4] +((ub4)k[5]<<8) +((ub4)k[6]<<16) +((ub4)k[7]<<24));
        add b, [key+4]

        ;;; c += (k[8] +((ub4)k[9]<<8) +((ub4)k[10]<<16)+((ub4)k[11]<<24));
        add c, [key+8]

        mix a, b, c, temp

        add key, 12
        sub len, 12

        jmp near while

end_while:

        ;;; c += length;
        add c, [ebp+12]


;; jump table

        jmp [jump_table+len*4]

case11:
        add a, [key]       ; cases 1,2,3,4
        add b, [key+4]     ; cases 5,6,7,8
        mov temp, [key+8]  ; cases 9,10,11
        shl temp, 8
        add c, temp
        jmp ende

case10:
        add a, [key]       ; cases 1,2,3,4
        add b, [key+4]     ; cases 5,6,7,8
        mov temp, [key+8]  ; cases 9,10
        shl temp, 8
        and temp, 0FFFFFFh
        add c, temp
        jmp ende

case9:
        add a, [key]       ; cases 1,2,3,4
        add b, [key+4]     ; cases 5,6,7,8
        mov temp, [key+8]  ; cases 9
        shl temp, 8
        and temp, 0FFFFh
        add c, temp
        jmp ende

case8:
        add a, [key]     ; cases 1,2,3,4
        add b, [key+4]   ; cases 5,6,7,8
        jmp ende

case7:
        add a, [key]       ; cases 1,2,3,4
        mov temp, [key+4]  ; cases 5,6,7
        and temp, 0FFFFFFh
        add b, temp
        jmp ende

case6:
        add a, [key]       ; cases 1,2,3,4
        mov temp, [key+4]  ; cases 5,6
        and temp, 0FFFFh
        add b, temp
        jmp ende

case5:
        add a, [key]       ; cases 1,2,3,4
        mov temp, [key+4]  ; cases 5
        and temp, 0FFh
        add b, temp
        jmp ende

case3:
        mov temp, [key]
        and temp, 0FFFFFFh
        add a, temp        ; cases 1,2,3
        jmp ende

case2:
        mov temp, [key]
        and temp, 0FFFFh
        add a, temp        ; cases 1,2
        jmp ende

case1:
        mov temp, [key]
        and temp, 0FFh
        add a, temp        ; cases 1
        jmp ende

;; the last case should be the most often occuring one (so we can save one jump instruction)
case4:
        add a, [key]       ; cases 1,2,3,4

case0:
ende:

        mix a, b, c, temp


        ; return value in eax
%ifnidni c,eax
        mov eax, c
%endif

        ; --------------------------------------------------------
        pop     edx
        pop     ecx
        pop     ebx
        pop     edi
        pop     esi
        pop     ebp
        ret
