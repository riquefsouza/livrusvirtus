                             CLIPS TUTORIAL
==========================================================================
To start, just type "clips".  The prompt is 

   CLIPS>

To stop, type

   CLIPS> (exit)
--------------------------------------------------------------------------
There are facts and rules.  Facts may take on any form of a list of atoms.
Deffacts are clusters of facts.  Each cluster is a list of facts, and has
a name.  For sake of notation, the word "fact" == "assertion".

   (facts)                             Lists all current facts
   (clear)                             Gets rid of all facts
   
   (deffacts xyz "something stupid"    Group of facts, it is asserted whenever
      (animal is duck)                 you do (reset)
      (sound is quack)
   )
   (list-deffacts)                     List all deffacts
   (ppdeffact xyz)                     pretty-print deffact xyz
   (undeffacts xyz)                    get rid of xyz
   
   (excise take-a-walk)                remove rule take-a-walk
   
   (assert (duck says quack))          Assert a fact (put into working memory)
   ?var <- (sound is quack)            Matches the assertion (sound is quack)
                                       and put its fact number into ?var
   (retract f-1)                       Retract a fact (must know is number)

----------------------------------------------------------------------------
Rules have the form:

   (defrule rulename "Explanation string"
        1 or more antecedent facts
   =>
        1 or more CLIPS commands
   )

The antecedent facts may be simple assertions from the fact list, or they
may have variables in them, and complicated pattern matching (see below.)
They may also follow the notation "variable <- (fact)"  where the left 
arrow means "if you find a matching fact, put its fact-number into the
variable."

   (rules)                             Lists all rules
   (pprule duck)                       Pretty-print rule whose name is duck

----------------------------------------------------------------------------
Running a CLIPS program involves first defining some rules, then making some
assertions, then doing run to start forward chaining.  CLIPS figures out
which rules have antecedents that fully match the assertion database.  These
rules are said to be triggered, and they are put on the agenda list.  Next,
the first one in sequence of physical ordering is selected to be fired.
Its CLIPS commands are done (these follow =>).

   (reset)                             Remove everything from agenda list and
                                       assert (initial-fact) and all deffacts
   (run)                               Have CLIPS do foward chaining
   (watch facts)                       Print out facts as they are entered
   (watch rules)                       Print out when rules fire 
   (unwatch ...)
   (watch all) 
   (agenda)                            show agenda list (the agenda list con-
                                       tains rules that have been triggered 
                                       but not yet fired.)
   (matches take-a-vacation)           Show all partial matches of antecedents
                                       for rule "take-a-vacation"

----------------------------------------------------------------------------
MATCHING ANTECEDENTS

   (sound is ?sound)                   Matches any assertion and instantiates
                                       variable ?sound
   ?var <- (sound is ?sound)           Matches any assertion and puts fact #

VARIABLES
   ?     -- single-field wildcard, match one thing
   ?var  -- single-field variable, match one thing and put it into ?var
   $?    -- multi-field wildcard, zero or more fields
   $?var -- multi-field wildcard and assign to a variable.

----------------------------------------------------------------------------
MORE COMPLICATED ANTECEDENTS:
   (or ?fact <- (light red)            Note that we match all to ?fact so that
       ?fact <- (walk-sign dont walk)      we can retract whatever fact
       ?fact <- (police say dont walk))    triggered this.

   (or (x1) (and (y1) (y2))            And is not used that much because all
            (and (y3) (y4)))           antecedents in a rule implicitly have 
                                       And between them.  But nested inside ors
                                       Ands may come in useful.

   (not (light red))                   True if (light red) is not in fact list.

   (number ?x&:(> ?x 1))               True if (number ?x) is there and ?x is
                                       greater than 1.  (test (> ?x 1)) would
                                       also work.

   (number ?x&:(and (> ?x 1) (< ?x 4)) Same as...
   (number ?x&:(> ?x 1)&:(< ?x 4))     this

----------------------------------------------------------------------------
PREDICATES
   (numberp <arg>)                     If <arg> is a number
   (stringp <arg>)                     If <arg> is a string
   (wordp <arg>)                       If <arg> is a word (single atom)
   (evenp <arg>)                       If <arg> is an even number
   (oddp <arg>)                        If <arg> is an odd number
   eq                                  General equality, = or atom equal
   =                                   Numeric equal only
   
----------------------------------------------------------------------------
SALIENCE
   (defrule rule1                      Salience numbers go from -10000 to
      (declare (salience 30))          10000.  Default is 0.  The rule on
      (priority first)                 the agenda list which has the highest
    =>                                 salience is fired next.
      (printout t "rule 1" crlf)
   )

Salience is used to order the rules so you can determine which will fire
next.  Normally order of the rules is also used.

----------------------------------------------------------------------------
ARITHMETIC:

(assert =(+ 5 3))                   You need to use =( if you want something 
                                    evaluated.
(bind ?x (+ ?y (* ?x 3)))           bind doesn't need this convention

LOGICAL CONSTRAINTS:
(light ~green)                      Matches (light ...anything but green...)
(light yellow|red)                  yellow or red
(light ?color&yellow|blinking)      If yellow or blinking match, assign to color
(light ?color&~red&~yellow)         If light is not red and not yellow, then
                                    match and assign the value to ?color

----------------------------------------------------------------------------
CONTROL STRUCTURES:
  RHS of rules can have if-then-else and while loops.  Ifs and whiles can be
  simulated by multiple rules that keep asserting facts.

  => (printout t "More whipped cream?" crlf)
     (bind ?answer (read))
     (if (or (eq ?answer y)(eq ?answer yes))
      then (retract ?cream)
           (assert (loop whipped-cream))
      else (halt)                                 Don't always need "else"
     )
)

  => (bind ?count 10)               Example of a counting loop
     (while (> ?count 0)
          (bind ?sym (gensym))
          (printout t ?sym crlf)
          (bind ?count (- ?count 1)) 
     )
)
     
----------------------------------------------------------------------------
OUTPUT:
(printout t "Hi there" crlf)        Prints out on stdout "Hi there" and carr.ret
(format t "format string" ...vars...)  Just like format in Common LISP or C

   Format Codes within %-M.Nx

        -            left justify within field. default is right justify
        M            width of field
        .N           optional, number of digits after decimal
        x            type of data (d, f, g, e, o, x, s, n %)

   The newline is %n.  %% is the percent character

----------------------------------------------------------------------------
INPUT:
(assert (color =(read)))            ask for user input, reads an atom
(bind ?string (readline))           reads a character string
(str-assert ?string)                asserts atoms in the string

TEST:
(test (<= ?count ?max))             when included in the antecedents of a 
                                    rule, it performs the function and if T, 
                                    then it enables triggering the rule
                                    (other later antecedents may still cause
                                    the rule not to be triggered)

----------------------------------------------------------------------------
FUNCTIONS:
(length $?names)                    number of fields
(nth <number> $?names)              just like LISP's nth, 1-based, not 0-based
(member ?field $?multifield)        is it a member?
(subset $?subset $?mainset)         is value of $?subset a subset of $?mainset


----------------------------------------------------------------------------
FILE SYSTEM:
(batch "somefile")                  read in file as if typed in-line
(load "somefile")                   read in a file of rules
(save "somefile")                   save rules to a file
(load-facts "somefile")             read in a file of facts
(save-facts "somefile")             save facts to a file
(system "ls")                       operating system escape

----------------------------------------------------------------------------
FILE I/O:
(open "filename" atom-name "r")     Open up "filename" and bind to atom-name
      file access is
        r -- read     w -- write    a -- append     r+ -- read & write

(close)                             Close all open files
(close atom-name)                   Close just this file
(read atom-name)                    Read next atom from open file
                                    Returns special atom EOF when you try to
                                    read beyond last atom in file
(readline atom-name)                Reads next line (on EOF returns ????)

----------------------------------------------------------------------------
LOOP USING RULES:

(defrule loop1                      "Start the loop.  This is a counting loop"
   ?x <- (loop counter is ?n)
   (test (<= ?n 7))
=>
   (retract ?x)
   (assert (loop counter is =(+ 1 ?n)))
   (format t "loop body %d%n" ?n)
)

(defrule loop2                      "Continuation & test of loop, body of loop"
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

(defrule endloop2                   "End of the loop"
   ?x <- (keep going)
=>
   (retract ?x)
)

----------------------------------------------------------------------------
IF THEN USING RULES:

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
----------------------------------------------------------------------------
