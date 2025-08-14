% 1. It has been optimized for readability, understandability, and
% maintainability.
% 2. It follows proper, modern Prolog conventions.
% 3. It is clean, safe, and effective code.
% 4. And it follows the philosophy of open to extensibility but closed off to
% modifications.
% 5. Lastly, any other rules, aka modern industry standards or anything that I
% didn't include above, that I need to follow, since the above rules aren't
% exhaustive.

% Problem #01
shuffle([], [], []).
shuffle([HeadOne | TailOne], [HeadTwo | TailTwo], [HeadOne, HeadTwo |
TailThree]) :- shuffle(TailOne, TailTwo, TailThree).

% Problem #02
double([], []).
double([HeadOne | TailOne], [HeadOne, HeadOne | TailTwo]) :- double(TailOne,
TailTwo).

% Problem #03
no_duplicates([], []).
no_duplicates([Head | Tail], OutputList) :- member(Head, Tail),
no_duplicates(Tail, OutputList).
no_duplicates([Head | Tail], [Head | OutputList]) :- \+ member(Head, Tail),
no_duplicates(Tail, OutputList).

% Problem #04
same_elements([], []).
same_elements([HeadOne | TailOne], ListTwo) :- select(HeadOne, ListTwo,
ListThree), same_elements(TailOne, ListThree).
