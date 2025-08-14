% 1. It has been optimized for readability, understandability, and
% maintainability.
% 2. It follows proper, modern Erlang conventions.
% 3. It is clean, safe, and effective code.
% 4. And it follows the philosophy of open to extensibility but closed off to
% modifications.
% 5. It is efficient in terms of implementation for the underlying low level
% hardware.
% 6. Lastly, any other rules, aka modern industry standards or anything that I
% didn't include above, that I need to follow, since the above rules aren't
% exhaustive.

-module(hw5).
-export([myremoveduplicates/1, myintersection/2, mylast/1, myreverse/1,
         myreplaceall/3]).

% Problem #01
myremoveduplicates([]) -> [];
myremoveduplicates([Head | Tail]) -> case lists:member(Head, Tail) of
    true -> myremoveduplicates(Tail);
    false -> [Head | myremoveduplicates(Tail)]
end.

% Problem #02
myintersection(_, []) -> [];
myintersection([], _) -> [];
myintersection([Head | Tail], Lst) -> case lists:member(Head, Lst) of
    true -> [Head | myintersection(Tail, Lst)];
    false -> myintersection(Tail, Lst)
end.

% Problem #03
mylast([]) -> [];
mylast([Head | []]) -> [Head];
mylast([_ | Tail]) -> mylast(Tail).

% Problem #04
myreversehelper([], Lst) -> Lst;
myreversehelper([Head | Tail], Lst) -> myreversehelper(Tail, [Head | Lst]).

myreverse(Lst) -> myreversehelper(Lst, []).

% Problem #05
myreplaceall(_, _, []) -> [];
myreplaceall(New, New, Lst) -> Lst;
myreplaceall(New, Old, [Head | Tail]) when Head =:= Old -> [New |
                                                           myreplaceall(New,
                                                                        Old,
                                                                        Tail)];
myreplaceall(New, Old, [Head | Tail]) -> [Head | myreplaceall(New, Old, Tail)].
