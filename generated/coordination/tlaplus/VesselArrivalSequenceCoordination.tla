---- MODULE VesselArrivalSequenceCoordination ----
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

StepNames == {"OrderPilot", "AssignTugs", "AllocateBerth", "ActivateCargoPlan", "OpenGates"}

Init ==
    /\ stepStatus  = [s \in StepNames |-> Pending]
    /\ currentStep = "OrderPilot"
    /\ messages    = {}

\* Step: OrderPilot (context: VesselTraffic)
OrderPilotExecute ==
    /\ currentStep = "OrderPilot"
    /\ stepStatus["OrderPilot"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["OrderPilot"] = Running]
    /\ messages' = messages \union {<<"VesselTraffic", "DispatchPilot">>}
    /\ UNCHANGED <<currentStep>>

OrderPilotComplete ==
    /\ stepStatus["OrderPilot"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["OrderPilot"] = Completed]
    /\ currentStep' = "AssignTugs"
    /\ UNCHANGED <<messages>>

OrderPilotFail ==
    /\ stepStatus["OrderPilot"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["OrderPilot"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

\* Step: AssignTugs (context: VesselTraffic)
AssignTugsExecute ==
    /\ currentStep = "AssignTugs"
    /\ stepStatus["AssignTugs"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["AssignTugs"] = Running]
    /\ messages' = messages \union {<<"VesselTraffic", "BookTugs">>}
    /\ UNCHANGED <<currentStep>>

AssignTugsComplete ==
    /\ stepStatus["AssignTugs"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["AssignTugs"] = Completed]
    /\ currentStep' = "AllocateBerth"
    /\ UNCHANGED <<messages>>

AssignTugsFail ==
    /\ stepStatus["AssignTugs"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["AssignTugs"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

\* Step: AllocateBerth (context: VesselTraffic)
AllocateBerthExecute ==
    /\ currentStep = "AllocateBerth"
    /\ stepStatus["AllocateBerth"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["AllocateBerth"] = Running]
    /\ messages' = messages \union {<<"VesselTraffic", "AllocateBerth">>}
    /\ UNCHANGED <<currentStep>>

AllocateBerthComplete ==
    /\ stepStatus["AllocateBerth"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["AllocateBerth"] = Completed]
    /\ currentStep' = "ActivateCargoPlan"
    /\ UNCHANGED <<messages>>

AllocateBerthFail ==
    /\ stepStatus["AllocateBerth"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["AllocateBerth"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

\* Step: ActivateCargoPlan (context: CargoOperations)
ActivateCargoPlanExecute ==
    /\ currentStep = "ActivateCargoPlan"
    /\ stepStatus["ActivateCargoPlan"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["ActivateCargoPlan"] = Running]
    /\ messages' = messages \union {<<"CargoOperations", "ActivateLoadPlan">>}
    /\ UNCHANGED <<currentStep>>

ActivateCargoPlanComplete ==
    /\ stepStatus["ActivateCargoPlan"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["ActivateCargoPlan"] = Completed]
    /\ currentStep' = "OpenGates"
    /\ UNCHANGED <<messages>>

ActivateCargoPlanFail ==
    /\ stepStatus["ActivateCargoPlan"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["ActivateCargoPlan"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

\* Step: OpenGates (context: PassengerTerminal)
OpenGatesExecute ==
    /\ currentStep = "OpenGates"
    /\ stepStatus["OpenGates"] = Pending
    /\ stepStatus' = [stepStatus EXCEPT !["OpenGates"] = Running]
    /\ messages' = messages \union {<<"PassengerTerminal", "PrepareEmbarkation">>}
    /\ UNCHANGED <<currentStep>>

OpenGatesComplete ==
    /\ stepStatus["OpenGates"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["OpenGates"] = Completed]
    /\ UNCHANGED <<currentStep>>
    /\ UNCHANGED <<messages>>

OpenGatesFail ==
    /\ stepStatus["OpenGates"] = Running
    /\ stepStatus' = [stepStatus EXCEPT !["OpenGates"] = Failed]
    /\ UNCHANGED <<currentStep, messages>>

Next == OrderPilotExecute
    \/ OrderPilotComplete
    \/ OrderPilotFail
    \/ AssignTugsExecute
    \/ AssignTugsComplete
    \/ AssignTugsFail
    \/ AllocateBerthExecute
    \/ AllocateBerthComplete
    \/ AllocateBerthFail
    \/ ActivateCargoPlanExecute
    \/ ActivateCargoPlanComplete
    \/ ActivateCargoPlanFail
    \/ OpenGatesExecute
    \/ OpenGatesComplete
    \/ OpenGatesFail

Spec     == Init /\ [][Next]_vars
FairSpec == Init /\ [][Next]_vars /\ WF_vars(Next)

\* Safety: At most one step is running at a time
AtMostOneRunning ==
    Cardinality({s \in StepNames : stepStatus[s] = Running}) <= 1

\* Liveness: All steps eventually reach terminal state
AllComplete == <>(\A s \in StepNames : stepStatus[s] \in {Completed, Failed})

====
