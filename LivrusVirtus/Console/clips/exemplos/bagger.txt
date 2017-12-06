(defrule b1
   (step is check order)
   (not (need-bagging pepsi))
   (need-bagging potato-chips)
=>
   (printout t "bag some pepsi?")
   (assert (if1 =(read)))
)

(defrule b1-if1
   ?x <- (if1 y)
=>
   (retract ?x)
   (assert (need-bagging pepsi))
)

(defrule b1-else1
   ?x <- (if1 ~y)
=>
   (retract ?x)
)


(defrule b2
   ?x <- (step is check order)
=>
   (retract ?x)
   (assert (step is bag large items))
)

(defrule b3
   (step is bag large items)
   ?y <- (need-bagging ?x)
   (sizeof ?x large)
=>
   (retract ?y)
   (assert (bag it up ?x))
)

(defrule change-bag
   ?x <- (number of items in current bag is ?n)
   ?y <- (current bag ?cb)
   (test (>= ?n 4))
   ?z <- (bag contains $?itemlist)
=>
   (retract ?x) 
   (retract ?y) 
   (retract ?z) 
   (assert (number of items in current bag is 0))
   (assert (current bag =(+ 1 ?cb)))
   (assert (bag number ?cb contains $?itemlist))
   (assert (bag contains))
)

(defrule do-bag
   ?r1 <- (need-bagging ?x)
=>
   (retract ?r1)
   (assert (bag it up ?x))
)

(defrule bag-up
   ?r1 <- (bag it up ?item)
   ?r2 <- (bag contains $?itemlist)
   ?r3 <- (number of items in current bag is ?n)
=>
   (retract ?r1)
   (retract ?r2)
   (retract ?r3)
   (assert (bag contains $?itemlist ?item))
   (assert (number of items in current bag is =(+ 1 ?n)))
)


(deffacts start-out
   (step is check order)
   (current bag 1)
   (number of items in current bag is 0)
   (bag contains)
)

(deffacts items-bagged "These are the initial items to be bagged with sizes"
   (need-bagging bread)
   (need-bagging glop)
   (need-bagging granola)
   (need-bagging ice-cream)
   (need-bagging potato-chips)
;  (need-bagging pepsi)

   (sizeof bread medium)
   (sizeof glop small)
   (sizeof granola large)
   (sizeof ice-cream medium)
   (sizeof potato-chips medium)
   (sizeof pepsi large)

   (container bread plastic-bag)
   (container glop jar)
   (container granola cardboard-box)
   (container ice-cream cardboard-carton)
   (container potato-chips plastic-bag)
   (container pepsi bottle)

   (frozen ice-cream)
)
