: 3max \ n1 n2 n3 -- n4
    2dup > if swap then
    rot 2dup > if swap then ;

: 3dup \ a b c -- a b c a b c
    2dup 4 pick -rot ;

: paper locals| x y z |
    x y * 2 *
    x z * 2 *
    y z * 2 *
    + +
    
    x y z 3max drop *
    + ;

: ribbon locals| x y z |
    x y z 3max drop
    + dup +
    x y z * * + ;
