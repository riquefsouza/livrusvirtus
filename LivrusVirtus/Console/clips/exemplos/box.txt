;------------------------------------------------------------------
;  This simple CLIPS program shows how you can box up toys, 4 to a box.
;  You have an initial set of facts about which toys need boxing.
;  After initial fact, you assert that (box 1 contains) meaning that
;  it currently contains nothing.  Then you select a toy to be boxed,
;  put it into that box, and remove the (needs-boxing ...) fact.
;  You may have to change boxes when you fill up the current one with 4
;  toys.  To use, assume this file is called "box":
;
;     % clips
;     CLIPS> (batch "box")
;     CLIPS> (reset)
;     CLIPS> (run)
;     CLIPS> (facts)
;
;  The (facts) command will print out which assertion are now true.
;  You should see:
;
;   f-15    (box 1 contains colors doll gun car)
;   f-20    (box 2 contains toy-piano dollhouse camera shovel)
;   f-23    (box 3 contains globe teddy-bear)
;------------------------------------------------------------------

(deffacts toys
    (needs-boxing colors)
    (needs-boxing doll)
    (needs-boxing gun)
    (needs-boxing car)
    (needs-boxing toy-piano)
    (needs-boxing dollhouse)
    (needs-boxing camera)
    (needs-boxing shovel)
    (needs-boxing globe)
    (needs-boxing teddy-bear)
)

(defrule start-out
    ?r <- (initial-fact)
=>
    (retract ?r)
    (assert (box 1 contains))
)

(defrule change-box
    ?r1 <- (box ?boxnum contains $?itemlist)
    (test (<= 4 (length $?itemlist)))
=>
    (assert (box =(+ 1 ?boxnum) contains))
)

(defrule box-up
    ?r1 <- (needs-boxing ?item)
    ?r2 <- (box ?boxnum contains $?itemlist)
=>
    (retract ?r1)
    (retract ?r2)
    (assert (box ?boxnum contains $?itemlist ?item))
)
