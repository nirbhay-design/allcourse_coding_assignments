loves(romeo,juliet).
loves(juliet,romeo) :- loves(romeo,juliet).


male(ramesh).
male(rameshi).
male(rames).
male(rameh).
male(rash).
male(rame).

female(boss).
female(bos).
female(bss).
female(oss).
female(bs).


happy_female(Xar) :- female(Xar),
    write('Female is happy because she is female'),
    format('~w ~s female ~n',[Xar,'hi']).
    # format('~w ~s ~2f female ~n',[Xar,'hi']).

    # people(name,surname,20).
    # people(name,_,20).

    # manveer(nirbhay(mayank(X,Y),mayank(X,Y1))).
    # horizontal(line(point(X,Y),point(X1,Y))).


sum_from(X,X,Z,P):-
    O is X + Z,
    P is O.

sum_from(X,Y,Z,P) :-
    O is X+Z,
    M is X + 1,
    sum_from(M,Y,O,P).



