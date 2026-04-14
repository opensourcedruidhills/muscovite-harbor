---- MODULE VoyageStatusSpec ----
EXTENDS Naturals, Sequences, FiniteSets

\* State machine: VoyageStatus
\* Entity: Voyage

VARIABLES current_state, history

vars == <<current_state, history>>

\* ── State set ────────────────────────────────────────────────
AllStates == {"ANNOUNCED", "PILOT_ORDERED", "APPROACHING", "BERTHING", "MOORED", "CARGO_OPS", "DEPARTURE_PREP", "UNMOORED", "DEPARTED"}

TerminalStates == {"DEPARTED"}

\* ── Initial state ────────────────────────────────────────────
Init ==
    /\ current_state = "ANNOUNCED"
    /\ history = <<"ANNOUNCED">>

\* ── Transition actions ────────────────────────────────────────

VoyageStatusSpecTransition_ANNOUNCED_To_PilotOrdered ==
    /\ current_state = "ANNOUNCED"
    /\ current_state' = "PILOT_ORDERED"
    /\ history' = Append(history, "PILOT_ORDERED")

VoyageStatusSpecTransition_PilotOrdered_To_APPROACHING ==
    /\ current_state = "PILOT_ORDERED"
    /\ current_state' = "APPROACHING"
    /\ history' = Append(history, "APPROACHING")

VoyageStatusSpecTransition_APPROACHING_To_BERTHING ==
    /\ current_state = "APPROACHING"
    /\ current_state' = "BERTHING"
    /\ history' = Append(history, "BERTHING")

VoyageStatusSpecTransition_BERTHING_To_MOORED ==
    /\ current_state = "BERTHING"
    /\ current_state' = "MOORED"
    /\ history' = Append(history, "MOORED")

VoyageStatusSpecTransition_MOORED_To_CargoOps ==
    /\ current_state = "MOORED"
    /\ current_state' = "CARGO_OPS"
    /\ history' = Append(history, "CARGO_OPS")

VoyageStatusSpecTransition_CargoOps_To_DeparturePrep ==
    /\ current_state = "CARGO_OPS"
    /\ current_state' = "DEPARTURE_PREP"
    /\ history' = Append(history, "DEPARTURE_PREP")

VoyageStatusSpecTransition_DeparturePrep_To_UNMOORED ==
    /\ current_state = "DEPARTURE_PREP"
    /\ current_state' = "UNMOORED"
    /\ history' = Append(history, "UNMOORED")

VoyageStatusSpecTransition_UNMOORED_To_DEPARTED ==
    /\ current_state = "UNMOORED"
    /\ current_state' = "DEPARTED"
    /\ history' = Append(history, "DEPARTED")

VoyageStatusSpecTransition_APPROACHING_To_ANNOUNCED ==
    /\ current_state = "APPROACHING"
    /\ current_state' = "ANNOUNCED"
    /\ history' = Append(history, "ANNOUNCED")

VoyageStatusSpecTransition_BERTHING_To_APPROACHING ==
    /\ current_state = "BERTHING"
    /\ current_state' = "APPROACHING"
    /\ history' = Append(history, "APPROACHING")

\* ── Next relation ────────────────────────────────────────────
Next ==
    \/ VoyageStatusSpecTransition_ANNOUNCED_To_PilotOrdered
    \/ VoyageStatusSpecTransition_PilotOrdered_To_APPROACHING
    \/ VoyageStatusSpecTransition_APPROACHING_To_BERTHING
    \/ VoyageStatusSpecTransition_BERTHING_To_MOORED
    \/ VoyageStatusSpecTransition_MOORED_To_CargoOps
    \/ VoyageStatusSpecTransition_CargoOps_To_DeparturePrep
    \/ VoyageStatusSpecTransition_DeparturePrep_To_UNMOORED
    \/ VoyageStatusSpecTransition_UNMOORED_To_DEPARTED
    \/ VoyageStatusSpecTransition_APPROACHING_To_ANNOUNCED
    \/ VoyageStatusSpecTransition_BERTHING_To_APPROACHING

\* ── Type invariant ───────────────────────────────────────────
TypeInvariant ==
    /\ current_state \in AllStates
    /\ Len(history) >= 1

\* ── Safety: only valid transitions ───────────────────────────
NoInvalidTransitions ==
    \A i \in 1..(Len(history) - 1):
        <<history[i], history[i+1]>> \in ValidTransitionPairs

ValidTransitionPairs == {
    <<"ANNOUNCED", "PILOT_ORDERED">>,
    <<"PILOT_ORDERED", "APPROACHING">>,
    <<"APPROACHING", "BERTHING">>,
    <<"BERTHING", "MOORED">>,
    <<"MOORED", "CARGO_OPS">>,
    <<"CARGO_OPS", "DEPARTURE_PREP">>,
    <<"DEPARTURE_PREP", "UNMOORED">>,
    <<"UNMOORED", "DEPARTED">>,
    <<"APPROACHING", "ANNOUNCED">>,
    <<"BERTHING", "APPROACHING">>
}

\* ── Specification ────────────────────────────────────────────
Spec     == Init /\ [][Next]_vars
FairSpec == Init /\ [][Next]_vars /\ WF_vars(Next)

====
