---- MODULE GateStatusSpec ----
EXTENDS Naturals, Sequences, FiniteSets

\* State machine: GateStatus
\* Entity: Gate

VARIABLES current_state, history

vars == <<current_state, history>>

\* ── State set ────────────────────────────────────────────────
AllStates == {"CLOSED", "CHECK_IN_OPEN", "BOARDING", "FINAL_CALL"}

TerminalStates == {"CLOSED"}

\* ── Initial state ────────────────────────────────────────────
Init ==
    /\ current_state = "CLOSED"
    /\ history = <<"CLOSED">>

\* ── Transition actions ────────────────────────────────────────

GateStatusSpecTransition_CLOSED_To_CheckInOpen ==
    /\ current_state = "CLOSED"
    /\ current_state' = "CHECK_IN_OPEN"
    /\ history' = Append(history, "CHECK_IN_OPEN")

GateStatusSpecTransition_CheckInOpen_To_BOARDING ==
    /\ current_state = "CHECK_IN_OPEN"
    /\ current_state' = "BOARDING"
    /\ history' = Append(history, "BOARDING")

GateStatusSpecTransition_BOARDING_To_FinalCall ==
    /\ current_state = "BOARDING"
    /\ current_state' = "FINAL_CALL"
    /\ history' = Append(history, "FINAL_CALL")

GateStatusSpecTransition_FinalCall_To_CLOSED ==
    /\ current_state = "FINAL_CALL"
    /\ current_state' = "CLOSED"
    /\ history' = Append(history, "CLOSED")

GateStatusSpecTransition_CheckInOpen_To_CLOSED ==
    /\ current_state = "CHECK_IN_OPEN"
    /\ current_state' = "CLOSED"
    /\ history' = Append(history, "CLOSED")

\* ── Next relation ────────────────────────────────────────────
Next ==
    \/ GateStatusSpecTransition_CLOSED_To_CheckInOpen
    \/ GateStatusSpecTransition_CheckInOpen_To_BOARDING
    \/ GateStatusSpecTransition_BOARDING_To_FinalCall
    \/ GateStatusSpecTransition_FinalCall_To_CLOSED
    \/ GateStatusSpecTransition_CheckInOpen_To_CLOSED

\* ── Type invariant ───────────────────────────────────────────
TypeInvariant ==
    /\ current_state \in AllStates
    /\ Len(history) >= 1

\* ── Safety: only valid transitions ───────────────────────────
NoInvalidTransitions ==
    \A i \in 1..(Len(history) - 1):
        <<history[i], history[i+1]>> \in ValidTransitionPairs

ValidTransitionPairs == {
    <<"CLOSED", "CHECK_IN_OPEN">>,
    <<"CHECK_IN_OPEN", "BOARDING">>,
    <<"BOARDING", "FINAL_CALL">>,
    <<"FINAL_CALL", "CLOSED">>,
    <<"CHECK_IN_OPEN", "CLOSED">>
}

\* ── Specification ────────────────────────────────────────────
Spec     == Init /\ [][Next]_vars
FairSpec == Init /\ [][Next]_vars /\ WF_vars(Next)

====
