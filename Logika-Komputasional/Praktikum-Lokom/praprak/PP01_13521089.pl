/* Bagian 1 */
/* Facts */

pria(gede).
pria(gojo).
pria(vonNeumann).
pria(vanRossum).
pria(bambang).
pria(vito).
pria(ave).
pria(wesly).
pria(elonMusk).
pria(patrick).

wanita(indah).
wanita(lovelace).
wanita(khelli).
wanita(power).
wanita(aqua).
wanita(wulandari).
wanita(anya).

usia(gede, 96).
usia(gojo, 90).
usia(vonNeumann, 92).
usia(vanRossum, 65).
usia(bambang, 60).
usia(vito, 56).
usia(ave, 54).
usia(wesly, 26).
usia(elonMusk, 28).
usia(patrick, 24).
usia(indah, 92).
usia(lovelace, 79).
usia(khelli, 89).
usia(power, 50).
usia(aqua, 50).
usia(wulandari, 24).
usia(anya, 4).

menikah(gede, indah).
menikah(indah, gede).
menikah(gojo, lovelace).
menikah(lovelace, gojo).
menikah(khelli, vonNeumann).
menikah(vonNeumann, khelli).
menikah(vito, power).
menikah(power, vito).
menikah(ave, aqua).
menikah(aqua, ave).
menikah(wulandari, wesly).
menikah(wesly, wulandari).

anak(vanRossum, gede).
anak(bambang, gede).
anak(vito, gede).
anak(vanRossum, indah).
anak(bambang, indah).
anak(vito, indah).
anak(power, gojo).
anak(ave, gojo).
anak(power, lovelace).
anak(ave, lovelace).
anak(aqua, khelli).
anak(aqua, vonNeumann).
anak(wesly, vito).
anak(wesly, power).
anak(elonMusk, ave).
anak(patrick, ave).
anak(elonMusk, aqua).
anak(patrick, aqua).
anak(anya, wulandari).
anak(anya, wesly).

saudara(vanRossum, bambang).
saudara(vanRossum, vito).
saudara(bambang, vanRossum).
saudara(bambang, vito).
saudara(vito, vanRossum).
saudara(vito, bambang).
saudara(power, ave).
saudara(ave, power).
saudara(elonMusk, patrick).
saudara(patrick, elonMusk).

/* Rules */
/* X adalah kakak dari Y */
kakak(X, Y) :- 
    saudara(X, Y),
    usia(X, A),
    usia(Y, B),
    A > B.

/* X adalah keponakan dari Y */
keponakan(X, Y) :-
    anak(X, Z),
    saudara(Y, Z).

/* X adalah suami dari Y */
suami(X, Y) :-
    pria(X),
    wanita(Y),
    menikah(X, Y).

/* X adalah sepupu dari Y */
sepupu(X, Y) :-
    anak(X, Z),
    saudara(Z, A),
    anak(Y, A).

/* X adalah menantu dari Y */
menantu(X, Y) :-
    menikah(X, Z),
    anak(Z, Y).

/* X adalah orang tua dari Y */
orangtua(X, Y) :-
    anak(Y, X).

/* X adalah bibi dari Y */
bibi(X, Y) :-
    keponakan(Y, X),
    wanita(X).

/* X adalah cucu dari Y */
cucu(X, Y) :-
    anak(X, Z),
    anak(Z, Y).

/* X adalah keturunan dari Y */
keturunan(X, Y) :-
    anak(X, Y).
keturunan(X, Y) :-
    anak(X, Z),
    keturunan(Z, Y).

/* X adalah anak paling tua */
anaksulung(X) :-
    anak(X, Y),
    pria(Y),
    \+ kakak(_, X).

anakbungsu(X) :-
    anak(X, Y),
    pria(Y),
    \+ kakak(X, _).

/* Bagian 2 */

factorial(0, 1).
factorial(N, X) :-
    N > 0,
    M is N - 1,
    factorial(M, R),
    X is R * N.

combination(N, C, X) :-
    factorial(N, A),
    factorial(C, B),
    R is N - C,
    factorial(R, Z),
    X is A / (B * Z).

change(1, 1).
change(1, 2).
change(1, 5).
change(X, Y) :-
    Y > 5,
    A is Y - 5,
    change(Z, A),
    X is 1 + Z.
change(X, Y) :-
    Y > 2,
    A is Y - 2,
    change(Z, A),
    X is 1 + Z.


fpb(A, 0, A).
fpb(A, B, X) :-
    A < B,
    fpb(B, A, X).
fpb(A, B, X) :-
    /* Algoritma Euclidean */
    B > 0,
    R is A mod B,
    fpb(B, R, X).

mod(0, B, 0).
mod(A, B, X) :-
    A < B,
    X is A.
mod(A, B, X) :-
    A >= B,
    Z is A - B,
    mod(Z, B, Y),
    X is Y.

deret(1, 1).
deret(X, Y) :-
    X > 0,
    A is X mod 2,
    A =:= 0,
    B is X - 1,
    deret(B, C),
    Y is 1 + C.
deret(X, Y) :-
    X > 0,
    A is X mod 2,
    A =:= 1,
    B is X - 1,
    deret(B, C),
    Y is 2 * C.

/* Bagian 3 */
less(X, Y, X) :-
    X =< Y.
less(X, Y, Y) :-
    X > Y.

min([X], X).
min([H | T], Min) :-
    min(T, A),
    less(H, A, Min).

more(X, Y, X) :-
    X >= Y.
more(X, Y, Y) :-
    X < Y.

max([X], X).
max([H | T], Max) :-
    max(T, A),
    more(H, A, Max).

range(List, Range) :-
    min(List, Min),
    max(List, Max),
    Range is Max - Min.

count([X], 1).
count([H | T], Count) :-
    count(T, X),
    Count is 1 + X.

sum([X], X).
sum([H | T], Sum) :-
    sum(T, X),
    Sum is H + X.

getIndex([X | T], X, 1).
getIndex([H | T], SearchedElement, Result) :-
    getIndex(T, SearchedElement, X),
    Result is 1 + X.

concat([], L, L).
concat([H | T], L, [H | Z]) :-
    concat(T, L, Z).

getElmt([X | _], 1, X).
getElmt([_ | T], Idx, Elmt) :-
    Idx > 1,
    A is Idx - 1,
    getElmt(T, A, Elmt).

setElmt([X | T], 1, Y, [Y | T]).
setElmt([H | T], Idx, Elmt, [H | Z]) :-
    Idx > 1,
    A is Idx - 1,
    setElmt(T, A, Elmt, Z).

swap(List, 1, 1, List).
swap(List, X, Y, Result) :-
    X < Y,
    swap(List, Y, X, Result).
swap(List, X, Y, Result) :-
    getElmt(List, X, A),
    getElmt(List, Y, B),
    setElmt(List, X, B, Z),
    setElmt(Z, Y, A, Result).

splitListGanjil([X], [X], []).
splitListGanjil([H | B], [H | ListGanjil], ListGenap) :-
    splitListGenap(B, ListGanjil, ListGenap).

splitListGenap([X], [], [X]).
splitListGenap([H | B], ListGanjil, [H | ListGenap]) :-
    splitListGanjil(B, ListGanjil, ListGenap).

splitList([X], [X], []).
splitList(List, ListGanjil, ListGenap) :-
    splitListGanjil(List, ListGanjil, ListGenap).

/* BONUS */
/* Gajadi deh tubes lain gangotak */