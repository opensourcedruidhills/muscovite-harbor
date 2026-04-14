---- MODULE ContainerHandoff ----
EXTENDS Integers, Sequences, FiniteSets, TLC

CONSTANTS
    Instances,          \* Set of saga instance IDs
    MaxRedeliveries     \* Retry limit

VARIABLES
    status,         \* Function: instance -> state
    currentStep,    \* Function: instance -> step name
    stepOutcome,    \* Function: instance -> outcome
    compIdx,        \* Function: instance -> compensation index
    eventBus        \* Set of in-flight events

vars == <<status, currentStep, stepOutcome, compIdx, eventBus>>

\* State constants
InProgress   == "in_progress"
Compensating == "compensating"
Completed    == "completed"
Failed       == "failed"

IsTerminal(i) == status[i] \in {Completed, Failed}

\* ── Initial state ──────────────────────────────────────────────
Init ==
    /\ status      = [i \in Instances |-> InProgress]
    /\ currentStep = [i \in Instances |-> "ReserveYardExit"]
    /\ stepOutcome = [i \in Instances |-> ""]
    /\ compIdx     = [i \in Instances |-> 0]
    /\ eventBus    = {}

\* ── Step actions ───────────────────────────────────────────────

\* Step: ReserveYardExit
ReserveYardExitInvoke(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "ReserveYardExit"
    /\ eventBus' = eventBus \union {<<i, "invoke_reserve_yard_exit">>}
    /\ UNCHANGED <<status, currentStep, compIdx>>

ReserveYardExitSuccess(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "ReserveYardExit"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "success"]
    /\ UNCHANGED <<compIdx, eventBus>>

ReserveYardExitFailure(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "ReserveYardExit"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "failure"]
    /\ status' = [status EXCEPT ![i] = Compensating]
    /\ compIdx' = [compIdx EXCEPT ![i] = 0]
    /\ UNCHANGED <<currentStep, eventBus>>

\* Step: CheckoutGate
CheckoutGateInvoke(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "CheckoutGate"
    /\ eventBus' = eventBus \union {<<i, "invoke_checkout_gate">>}
    /\ UNCHANGED <<status, currentStep, compIdx>>

CheckoutGateSuccess(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "CheckoutGate"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "success"]
    /\ UNCHANGED <<compIdx, eventBus>>

CheckoutGateFailure(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "CheckoutGate"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "failure"]
    /\ status' = [status EXCEPT ![i] = Compensating]
    /\ compIdx' = [compIdx EXCEPT ![i] = 1]
    /\ UNCHANGED <<currentStep, eventBus>>

\* Step: LoadTransport
LoadTransportInvoke(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "LoadTransport"
    /\ eventBus' = eventBus \union {<<i, "invoke_load_transport">>}
    /\ UNCHANGED <<status, currentStep, compIdx>>

LoadTransportSuccess(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "LoadTransport"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "success"]
    /\ UNCHANGED <<compIdx, eventBus>>

LoadTransportFailure(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "LoadTransport"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "failure"]
    /\ status' = [status EXCEPT ![i] = Compensating]
    /\ compIdx' = [compIdx EXCEPT ![i] = 2]
    /\ UNCHANGED <<currentStep, eventBus>>

\* Step: ConfirmDeparture
ConfirmDepartureInvoke(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "ConfirmDeparture"
    /\ eventBus' = eventBus \union {<<i, "invoke_confirm_departure">>}
    /\ UNCHANGED <<status, currentStep, compIdx>>

ConfirmDepartureSuccess(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "ConfirmDeparture"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "success"]
    /\ UNCHANGED <<compIdx, eventBus>>

ConfirmDepartureFailure(i) ==
    /\ status[i] = InProgress
    /\ currentStep[i] = "ConfirmDeparture"
    /\ stepOutcome' = [stepOutcome EXCEPT ![i] = "failure"]
    /\ status' = [status EXCEPT ![i] = Compensating]
    /\ compIdx' = [compIdx EXCEPT ![i] = 3]
    /\ UNCHANGED <<currentStep, eventBus>>

\* ── Compensation ──────────────────────────────────────────────
Compensate(i) ==
    /\ status[i] = Compensating
    /\ IF compIdx[i] > 0
        THEN /\ compIdx' = [compIdx EXCEPT ![i] = compIdx[i] - 1]
             /\ UNCHANGED <<status, currentStep, stepOutcome, eventBus>>
    ELSE /\ status' = [status EXCEPT ![i] = Failed]
            /\ UNCHANGED <<currentStep, stepOutcome, compIdx, eventBus>>

\* ── Next relation ─────────────────────────────────────────────
Next == \E i \in Instances:
    \/ ReserveYardExitInvoke(i)
    \/ ReserveYardExitSuccess(i)
    \/ ReserveYardExitFailure(i)
    \/ CheckoutGateInvoke(i)
    \/ CheckoutGateSuccess(i)
    \/ CheckoutGateFailure(i)
    \/ LoadTransportInvoke(i)
    \/ LoadTransportSuccess(i)
    \/ LoadTransportFailure(i)
    \/ ConfirmDepartureInvoke(i)
    \/ ConfirmDepartureSuccess(i)
    \/ ConfirmDepartureFailure(i)
    \/ Compensate(i)

\* ── Specification ─────────────────────────────────────────────
Spec     == Init /\ [][Next]_vars
FairSpec == Init /\ [][Next]_vars /\ WF_vars(Next)

====
