---- MODULE PassengerStatusSpec ----
EXTENDS Naturals, Sequences, FiniteSets

\* State machine: PassengerStatus
\* Entity: Passenger

VARIABLES current_state, history

vars == <<current_state, history>>

\* ── State set ────────────────────────────────────────────────
AllStates == {"CHECKED_IN", "SECURITY_CLEARED", "BOARDED", "DISEMBARKED"}

TerminalStates == {"DISEMBARKED"}

\* ── Initial state ────────────────────────────────────────────
Init ==
    /\ current_state = "CHECKED_IN"
    /\ history = <<"CHECKED_IN">>

\* ── Transition actions ────────────────────────────────────────

PassengerStatusSpecTransition_CheckedIn_To_SecurityCleared ==
    /\ current_state = "CHECKED_IN"
    /\ current_state' = "SECURITY_CLEARED"
    /\ history' = Append(history, "SECURITY_CLEARED")

PassengerStatusSpecTransition_SecurityCleared_To_BOARDED ==
    /\ current_state = "SECURITY_CLEARED"
    /\ current_state' = "BOARDED"
    /\ history' = Append(history, "BOARDED")

PassengerStatusSpecTransition_BOARDED_To_DISEMBARKED ==
    /\ current_state = "BOARDED"
    /\ current_state' = "DISEMBARKED"
    /\ history' = Append(history, "DISEMBARKED")

\* ── Next relation ────────────────────────────────────────────
Next ==
    \/ PassengerStatusSpecTransition_CheckedIn_To_SecurityCleared
    \/ PassengerStatusSpecTransition_SecurityCleared_To_BOARDED
    \/ PassengerStatusSpecTransition_BOARDED_To_DISEMBARKED

\* ── Type invariant ───────────────────────────────────────────
TypeInvariant ==
    /\ current_state \in AllStates
    /\ Len(history) >= 1

\* ── Safety: only valid transitions ───────────────────────────
NoInvalidTransitions ==
    \A i \in 1..(Len(history) - 1):
        <<history[i], history[i+1]>> \in ValidTransitionPairs

ValidTransitionPairs == {
    <<"CHECKED_IN", "SECURITY_CLEARED">>,
    <<"SECURITY_CLEARED", "BOARDED">>,
    <<"BOARDED", "DISEMBARKED">>
}

\* ── Specification ────────────────────────────────────────────
Spec     == Init /\ [][Next]_vars
FairSpec == Init /\ [][Next]_vars /\ WF_vars(Next)

====
