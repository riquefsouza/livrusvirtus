function sqr(n) {
  return n*n
}

BEGIN {
  for(i=1; i<=10; i++) {
    printf "%d ", sqr(i) 
  }
  print    # new line
}
