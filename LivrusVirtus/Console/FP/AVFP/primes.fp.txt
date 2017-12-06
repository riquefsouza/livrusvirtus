#
# Print prime numbers from 3 to ?
#
{factors
    &(+@[id %1]@*@[id %2])@iota@div@[id %4]
}
{isprime
    |and@&(~=@[id %0])@&mod@distl@[id factors]
}
{primes
    concat@&(isprime -> [id] ; %<>)@&(+@[id %1]@*@[id %2])@iota
}
