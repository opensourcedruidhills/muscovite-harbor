---- MODULE ContainerDischargeSequenceCoordination ----
EXTENDS Integers, Sequences, FiniteSets, TLC

CONSTANTS
    Contexts,       \* Set of participating context names
    MaxRetries      \* Retry limit per step

VARIABLES
    stepStatus,     \* Function: step name -> status
    currentStep,    \* Current executing step
    messages        \* In-flight messages between contexts

vars == <<stepStatus, currentStep, messages>>

Pending    == "pending"
Running    == "running"
Completed  == "completed"
Failed     == "failed"

StepNames == {"CranePick", "YardPlacement", "CustomsCheck", "HandoffDispatch"}

Init ==
    /\ stepStatus  = [s \in StepNames |-> Pending]
    /\ currentStep = "CranePick"
    /\ messages    = {}

\* Step: CranePick (context: CargoOperations)
CranePickExecute ==
    /\ currentStep = "CranePick"
    /\ stepStatus["CranePick"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["CranePick"] = Running]
    /\ messages' = messages \union {<<"CargoOperations", "PickContainer">>}
    /\ UNCHANGED <<currentStep>>

CranePickComplete ==
    /\ stepStatus["CranePick"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["CranePick"] = Completed]
    /\ currentStep' = "YardPlacement"
    /\ UNCHANGED <<messages>>

CranePickFail ==
    /\ stepStatus["CranePick"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["CranePick"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

\* Step: YardPlacement (context: CargoOperations)
YardPlacementExecute ==
    /\ currentStep = "YardPlacement"
    /\ stepStatus["YardPlacement"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["YardPlacement"] = Running]
    /\ messages' = messages \union {<<"CargoOperations", "PlaceContainer">>}
    /\ UNCHANGED <<currentStep>>

YardPlacementComplete ==
    /\ stepStatus["YardPlacement"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["YardPlacement"] = Completed]
    /\ currentStep' = "CustomsCheck"
    /\ UNCHANGED <<messages>>

YardPlacementFail ==
    /\ stepStatus["YardPlacement"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["YardPlacement"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

\* Step: CustomsCheck (context: HarbourControl)
CustomsCheckExecute ==
    /\ currentStep = "CustomsCheck"
    /\ stepStatus["CustomsCheck"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["CustomsCheck"] = Running]
    /\ messages' = messages \union {<<"HarbourControl", "CheckCustomsHold">>}
    /\ UNCHANGED <<currentStep>>

CustomsCheckComplete ==
    /\ stepStatus["CustomsCheck"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["CustomsCheck"] = Completed]
    /\ currentStep' = "HandoffDispatch"
    /\ UNCHANGED <<messages>>

CustomsCheckFail ==
    /\ stepStatus["CustomsCheck"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["CustomsCheck"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

\* Step: HandoffDispatch (context: IntermodalTransfer)
HandoffDispatchExecute ==
    /\ currentStep = "HandoffDispatch"
    /\ stepStatus["HandoffDispatch"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["HandoffDispatch"] = Running]
    /\ messages' = messages \union {<<"IntermodalTransfer", "ScheduleHandoff">>}
    /\ UNCHANGED <<currentStep>>

HandoffDispatchComplete ==
    /\ stepStatus["HandoffDispatch"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["HandoffDispatch"] = Completed]
    /\ UNCHANGED <<currentStep>>
    /\ UNCHANGED <<messages>>

HandoffDispatchFail ==
    /\ stepStatus["HandoffDispatch"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["HandoffDispatch"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

Next == CranePickExecute
    \/ CranePickComplete
    \/ CranePickFail
    \/ YardPlacementExecute
    \/ YardPlacementComplete
    \/ YardPlacementFail
    \/ CustomsCheckExecute
    \/ CustomsCheckComplete
    \/ CustomsCheckFail
    \/ HandoffDispatchExecute
    \/ HandoffDispatchComplete
    \/ HandoffDispatchFail

Spec     == Init /\ [][Next]_vars
FairSpec == Init /\ [][Next]_vars /\ WF_vars(Next)

\* Safety: At most one step is running at a time
AtMostOneRunning ==
    Cardinality({s \in StepNames : stepStatus[s] = Running}) <= 1

\* Liveness: All steps eventually reach terminal state
AllComplete == <>(\A s \in StepNames : stepStatus[s] \in {Completed, Failed})

====
