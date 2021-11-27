
position(firoz,sweeper).
position(parthiv,winger).
position(sanjay,goalkeeper).
position(parimal,midfilder).
position(praveen,defense).
position(samantak,defense).
position(gaurav,striker).
valuable(X):-position(X,Y),position(X,Z),Y\=Z.
comb1([],[]).
comb1([H|T],[X|Y]):-valuable(H),!,position(H,X),comb1(T,Y).
comb2([],[]).
comb2([H|T],[X|Y]):-position(H,X),comb2(T,Y),\+ member(H,T).
