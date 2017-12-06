;----------------------------------------------------------------------
;  "If then else" in CLIPS is quite strange!  Basically, every rule is an
;  if then, so there is no separate control structure.  This makes writing
;  if then elses quite cumbersome.  The following asks the user if he/she
;  wants to destroy the world, using the (read) function.  If the user
;  answers y or Y or yes or Yes, then something is asserted.  Otherwise,
;  something else is asserted.
;----------------------------------------------------------------------

(defrule if1
   (initial-fact)
=>
   (printout t "Do you want to blow up the world? ")
   (assert (blowup =(read)))
)

(defrule then1
   ?x <- (blowup y|Y|yes|Yes)
=>
   (retract ?x)
   (assert (world destroyed))
)

(defrule else1
   ?x <- (blowup ?)
=>
   (retract ?x)
   (assert (world still-there))
)
