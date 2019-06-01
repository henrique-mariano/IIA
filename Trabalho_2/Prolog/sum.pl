%Soma
soma([],0).
soma([H|T], S) :- soma(T, S1), S is S1 + H.

%Soma de 1 a 100
soma_1_a_100 :- numlist(1, 100, L), soma(L, Soma), write(Soma).