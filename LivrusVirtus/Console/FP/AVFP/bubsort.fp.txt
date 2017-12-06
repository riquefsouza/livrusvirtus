{swap concat@[ [2,1],tl@tl ]}
{step (>@[1,2] -> swap ; id) }
{pass
    (<@[length,%2] -> id ;
    apndl@[1,pass@tl]@step)
}
{bubsort
    (<@[length,%2] -> id ;
    apndr@[bubsort@tlr,last]@pass)
}
