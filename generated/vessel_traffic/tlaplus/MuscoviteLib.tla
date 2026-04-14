---- MODULE MuscoviteLib ----
EXTENDS Naturals, Sequences, FiniteSets

\* ── Set operators ────────────────────────────────────────────

\* IsSubset(S, T) — TRUE iff S \subseteq T
IsSubset(S, T) == S \subseteq T

\* MapApply(f, S) — apply function f to each element of set S
MapApply(f, S) == {f[x] : x \in S}

\* Injective(f) — TRUE iff f is injective over its domain
Injective(f) ==
    \A a, b \in DOMAIN f:
        a /= b => f[a] /= f[b]

\* ── Bag/multiset operators ────────────────────────────────────

\* BagAdd(bag, elem) — increment count of elem in bag
BagAdd(bag, elem) ==
    IF elem \in DOMAIN bag
        THEN [bag EXCEPT ![elem] = bag[elem] + 1]
        ELSE [x \in (DOMAIN bag \union {elem}) |->
            IF x = elem THEN 1 ELSE bag[x]]

\* ── Sequence utilities ────────────────────────────────────────

\* Last(seq) — last element of a non-empty sequence
Last(seq) == seq[Len(seq)]

\* Front(seq) — all but last element
Front(seq) == SubSeq(seq, 1, Len(seq) - 1)

\* Contains(seq, elem) — TRUE iff elem appears in seq
Contains(seq, elem) ==
    \E i \in 1..Len(seq): seq[i] = elem

====
