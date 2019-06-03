%Fatos
pai(joao, maria).
pai(arthur, alice).
pai(davi, gabriel).
pai(henrique, lucas).
pai(henrique, sarah).
pai(lucas, yuri).
pai(lucas, isadora).
pai(gustavo, joao).
pai(gustavo, mariana).
mae(lara, maria).
mae(cecilia, alice).
mae(beatriz, gabriel).
mae(yasmin, esther).
mae(sarah, joao).
mae(sarah, mariana).
mae(esther, isadora).
mae(esther, yuri).

%Regras
irmao(A,B) :- ((pai(P,A), pai(P,B)), A \== B;
               (mae(M,A), mae(M,B))), A \== B.

tio(A,B) :- (pai(P,B), irmao(A,P));
            (mae(M,B), irmao(A,M)).

avo(A,N) :- (pai(A,P), pai(P,N));
            (pai(A,P), mae(P,N)).

avoh(A,N) :- (mae(A,M), mae(M,N));
             (mae(A,M), pai(M,N)).
