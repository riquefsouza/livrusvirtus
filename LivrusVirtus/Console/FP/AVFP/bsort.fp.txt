#
# A divide-and-conquer sorting algorithm
#
{grpleft
    concat @ &( > -> tl ; %<>) @ distl }
{grpright
    concat @ &( < -> tl ; %<>) @ distl }
{arb 1}
{bsort
    (>@[length %1] ->
    concat@[bsort@grpleft [1] bsort@grpright]@[arb id]
    ; id)
}
