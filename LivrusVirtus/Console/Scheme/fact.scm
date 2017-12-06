; define function
(define fak 
    (lambda (n) 
      (if (< n 2)
          1
          (* n (fak (- n 1)))
          )
      )
    )

; call function
(fak 6)
