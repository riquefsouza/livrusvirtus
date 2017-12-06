\ define function (definiere Funktion)

: FAC recursive       ( n-n)
  DUP 1 >
  IF                  \ if n > 1
    DUP 1 - FAC *     \   n * fac n-1
  ELSE                \ else 
    DROP 1            \   1 
  ENDIF               \ end 
;

\ call function (Funtkion aufrufen)

6 FAC .
