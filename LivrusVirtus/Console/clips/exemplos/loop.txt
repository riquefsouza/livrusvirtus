;--------------------------------------------------------------
;  Loops
;     A loop consists of firing the same rule over and over.  But
;  a problem is that a rule only fires on a given fact once.  So
;  you must retract the fact and re-assert it.
;
;  The following loop runs for 7 times.  To start it, do
;
;      (assert (loop counter is 1))
;
;  then do (run).
;  Actually, you could assert (loop counter is 3) and it would only
;  run 4 times.  Or you could assert (loop counter is 8) and it 
;  would not run at all!
;--------------------------------------------------------------

(defrule loop1
   ?x <- (loop counter is ?n)
   (test (<= ?n 7))
=>
   (retract ?x)
   (assert (loop counter is =(+ 1 ?n)))
   (format t "loop body %d%n" ?n)
)

;--------------------------------------------------------------
;  The following is a general while loop.  The condition that it
;  stops on is the assertion (stop now).  It gives the user the
;  opportunity to stop by reading a line every time through the
;  loop.
;
;  Notice how the special symbol "not" is used to say (stop now)
;  is NOT in the current fact list.  Also, when the loop is done,
;  we clean up by defining rule endloop2, which removes the
;  keep going.
;
;  To start the loop, just assert (keep going).  When you type
;  in your assertion, do NOT put parentheses around it.
;--------------------------------------------------------------

(defrule loop2
   ?x <- (keep going)
   (not (stop now))
=>
   (retract ?x)
   (assert (keep going))
   (format t "Now in the loop%n")
   (format t "Please type in an assertion ")
   (bind ?assertion (readline))
   (str-assert ?assertion)
)

(defrule endloop2
   ?x <- (keep going)
=>
   (retract ?x)
)
