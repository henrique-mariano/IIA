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

inverte_1_a_100 :- numlist(1, 100, L), statistics(runtime, [TimeSinceStart | [TimeSinceLastCall]]), 
invertern(L, Y1), statistics(runtime, [NewTimeSinceStart | [ExecutionTime]]), 
write('A Execucao levou '), write(ExecutionTime), write(' ms.'), nl.