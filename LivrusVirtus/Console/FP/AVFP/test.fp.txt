#
# Test cases for FP
#
)load blah
)blah
~
+:<1 2>
+:<1.0 2.0>
+:<1>
+:?
+:<>
+:<1 2 3>
-:<1 2>
-:<1.0 2.0>
-:<1>
-:?
*:<1 2>
*:<1.0 2.0>
*:<1>
*:?
mod:<1 2>
mod:<1.0 2.0>
mod:<1>
mod:?
mod:<1 0>
mod:< <1> <2> >
/:<1 2>
/:<1.0 2.0>
/:<1>
/:?
/:<1 0>
/:< <1> <2> >
<:<1 2>
<:<1.0 2.0>
<:<1>
<:<1 T>
<:?
>:<1 2>
>:<1.0 2.0>
>:<1>
>:?
>=:<1 2>
>=:<1.0 2.0>
>=:<1>
>=:?
<=:<1 2>
<=:<1.0 2.0>
<=:<1>
<=:?
eq:<1 2>
eq:<1 1>
eq:<1 T>
eq:<1.0 2.0>
eq:< <1 2> <1 2> >
eq:< <1 2> <1 3> >
eq:?
=:<1 2>
=:<1 1>
=:<1 T>
=:<1.0 2.0>
=:< <1 2> <1 2> >
=:< <1 2> <1 3> >
=:?
~=:<1 2>
~=:<1 1>
~=:< <1 2> <1 2> >
~=:< <1 2> <1 3> >
~=:?
hd:<1 2 3>
hd:1
hd:?
tl:<>
tl:<1>
tl:<1 2>
tl:<1 2 3>
tl:1
tl:?
iota:9
iota:<9>
&id@iota:9
&%1:?
&+:<>
|+@iota:9
|+:<1>
|+:<>
|-:<>
|=:<>
|+:?
|and:<>
|or:<>
|xor:<>
|/:<>
|/:<1 0 0>
|*:<>
|id:<>
|%7:?
|%7:<>
!+@iota:9
!+:<1>
!+:<>
!-:<>
!+:?
!=:<>
!and:<>
!or:<>
!xor:<>
!/:<>
!/:<1 2 0>
!*:<>
!id:<>
!%7:<>
!%7:?
&(+@[%1, id])@iota:9
[id, id, +, id]:9
(1 -> 2 ; 3):<T 1 2>
(1 -> 2 ; 3):<F 1 2>
(1 -> 2 ; 3):<? 1 2>
(1 -> 2 ; 3):<1 1 2>
%?:9
9:<1 2 3>
3:<1 2>
&+:< <1 2> <3> <4 5> >
%7:?
hd:<>
tl:<>
iota:-8
%+5:<4>
(while 1 tl ):<T F>
(while 1 tl):<1 F>
(while 1 /@tl ):<T <1 0>>
length:?
length:1
length:<>
length:<1>
length:<1 2>
reverse:?
reverse:<>
reverse:<1>
reverse:<1 2>
first:?
first:<>
first:<1>
first:<1 2>
last:?
last:<>
last:<1>
last:<1 2>
atom:?
atom:1
atom:T
atom:<>
atom:<1>
pick:?
pick:<2 <7 8 9>>
pick:<T <7 8 9>>
pick:<2 T>
pick:<99 <1 2 3>>
pick:<4 <1 2 3>>
pick:<0 <>>
pick:<>
pick:<2>
not:1
not:T
null:<>
null:<1>
null:<1 2>
null:?
reverse:?
reverse:<>
reverse:<1>
reverse:<1 2>
reverse:<1 2 3>
distl:<>
distl:?
distl:<1 <2 3 4>>
distl:<1 2>
distr:<>
distr:?
distr:<<2 3 4> 1>
distr:<1 2>
trans:<>
trans:?
trans:< <1 2 3> <4 5 6> >
trans:< <1 2> <3 4 5> >
trans:< <1 2> T >
trans:< <> <> >
apndl:< T <1 2 3>>
apndl:?
apndl:<<1 2 3> 4>
apndl:<<1 2> <3 4>>
apndl:<1 <>>
apndr:< T <1 2 3>>
apndr:?
apndr:<<1 2 3> 4>
apndr:<<1 2> <3 4>>
apndr:<1 <>>
tlr:?
tlr:<>
tlr:<1>
tlr:<1 2 3>
front:?
front:<>
front:<1>
front:<1 2>
rotl:?
rotl:<>
rotl:<1>
rotl:<1 2 3>
rotr:?
rotr:<>
rotr:<1>
rotr:<1 2 3>
pair:<>
pair:?
pair:<1>
pair:<1 2>
pair:<1 2 3>
split:<>
split:?
split:<1>
split:<1 2>
split:<1 2 3>
concat:?
concat:<>
concat:<<>>
concat:< <> <1> <2> <> >
concat:< <> <1> T <> >
id:?
id:1
out:?
out:1
sin:?
sin:1
cos:?
cos:1
tan:?
tan:1
log:?
log:1
exp:?
exp:1
asin:?
asin:1
acos:?
acos:1
atan:?
atan:1
or:?
or:<1 2>
or:<T 2>
or:<T T>
or:<1 T>
or:< 1 2 3 >
and:?
and:<1 2>
and:<T 2>
and:<T T>
and:<1 T>
and:< 1 2 3 >
xor:?
xor:<1 2>
xor:<T 2>
xor:<T T>
xor:<1 T>
xor:< 1 2 3 >
{a 1}
{a 2}
a:<4 5 6>
{b a@a}
