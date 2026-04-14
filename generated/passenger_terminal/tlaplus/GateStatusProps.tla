---- MODULE GateStatusProps ----
EXTENDS GateStatusSpec

\* Safety: state is always valid
StateValid == current_state \in AllStates

\* Safety: history consistency
HistoryConsistent ==
    /\ Len(history) >= 1
    /\ history[Len(history)] = current_state

\* Liveness: eventually reaches a terminal state
EventuallyTerminal == <>(current_state \in TerminalStates)

\* Liveness: state always changes eventually (no deadlock)
NoDeadlock == []<>(ENABLED(Next))

====
