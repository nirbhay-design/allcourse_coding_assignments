sum_from(X,X,Z,P):-
    O is X + Z,
    P is O.

sum_from(X,Y,Z,P) :-
    O is X+Z,
    M is X + 1,
    sum_from(M,Y,O,P).

parent(alice,bob).
parent(alice,boby).
parent(bob,tonkey).
parent(tonkey,but).
parent(toney,but).
parent(mother,bob).

giveparent(X,Y):- 
    parent(Z,X),
    parent(Y,Z).

count(0) :-
    write(0),!.

count(X) :- 
    write(X),
    Y is X-1,nl,
    count(Y).

append([],Y,Z):-
    Z = Y.
append([H|T],Y,Z) :-
    write(H),nl,
    append(T,[H|Y],Z).

len([],Y) :- 
    Y is 0.
len([H|T],Y) :-
    len(T,M),
    M is Y+1. 


# copyfile(Src,Dest) :-
#     see(Src),
#     repeat,read(Data),
#     process(Data,Dest),
#     seen,!.

# process(end-file):-!.
# process(Data,Dest) :-
#     tell(Dest),
#     writenl(Data),
#     told,!.

loop(0):-
    write('loop ends'),nl.
loop(N) :- 
    write('N is : '), write(N),nl,Y is N-1,loop(Y).

go:-goinf(start).
goinf(end):-
    write("loop ends"),nl.
goinf(X):-
    X \= end,write(X),nl,read(Word),goinf(Word).

# process(end-file):-
#     write("reached end of file"),nl.
# process(Data):-
#     write("data is : "),write(Data),nl.
# readfile(File):-
#     see(File),repeat,read(Data),process(Data),seen.


# browse(File) :- 
#     seeing(Old),       
#     see(File),         
#     repeat, 
#     read(Data),        
#     process(Data),    
#     seen,              
#     see(Old),          
#     !.                
 
# process(end-of-file) :- !. 
# process(Data) :-  write(Data), nl, fail. 


issorted([X,Y|T]):- X=<Y,write(X),nl,issorted([Y|T]).
issorted([]):- write("emptylist"),nl.
issorted([_]):-write("single element is sorted"),nl.

show_me(X,[],[X]).
show_me(X,[H|T],[H|P]) :- show_me(X,T,P).
    