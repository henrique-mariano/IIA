%Soma
soma([],0).
soma([H|T], S) :- soma(T, S1), S is S1 + H.

%Concatenação
conc([], L, L).
conc([X|L1], L2, [X|L3]) :- conc(L1,L2,L3).

%Inversão O(n^2)
invertern2([],[]).
invertern2([X|Y], Z) :- invertern2(Y, Y1), conc(Y1,[X],Z).

%Inversão O(N)
invertern(X, Y) :- aux([], X, Y).
aux(L,[],L).
aux(L,[X|Y], Z) :- aux([X|L], Y, Z).