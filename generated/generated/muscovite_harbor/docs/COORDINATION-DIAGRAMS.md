# Cross-Context Coordination Diagrams

> Auto-generated from COORDINATION definitions (FTR-869)

## VesselArrivalSequence

Full vessel arrival: pilot → tug → berth → gangway → cargo plan

```mermaid
sequenceDiagram
    participant Coordinator
    participant VesselTraffic
    participant CargoOperations
    participant PassengerTerminal

    Coordinator->>VesselTraffic: DispatchPilot
    VesselTraffic->>Coordinator: PilotDispatched
    VesselTraffic->>Coordinator: PilotDispatched
    Coordinator->>VesselTraffic: BookTugs
    VesselTraffic->>Coordinator: TugsAssigned
    VesselTraffic->>Coordinator: TugsAssigned
    Coordinator->>VesselTraffic: AllocateBerth
    VesselTraffic->>Coordinator: BerthAllocated
    CargoOperations->>Coordinator: BerthAllocated
    Coordinator->>CargoOperations: ActivateLoadPlan
    CargoOperations->>Coordinator: CargoPlanActivated
    PassengerTerminal->>Coordinator: BerthAllocated
    Coordinator->>PassengerTerminal: PrepareEmbarkation
    Note over Coordinator,PassengerTerminal: OpenGates COMPLETES
```

## ContainerDischargeSequence

Container discharge: crane → yard → customs → intermodal

```mermaid
sequenceDiagram
    participant Coordinator
    participant CargoOperations
    participant HarbourControl
    participant IntermodalTransfer

    Coordinator->>CargoOperations: PickContainer
    CargoOperations->>Coordinator: ContainerPicked
    CargoOperations->>Coordinator: ContainerPicked
    Coordinator->>CargoOperations: PlaceContainer
    CargoOperations->>Coordinator: ContainerPlaced
    HarbourControl->>Coordinator: ContainerPlaced
    Coordinator->>HarbourControl: CheckCustomsHold
    HarbourControl->>Coordinator: CustomsCleared
    IntermodalTransfer->>Coordinator: CustomsCleared
    Coordinator->>IntermodalTransfer: ScheduleHandoff
    Note over Coordinator,IntermodalTransfer: HandoffDispatch COMPLETES
```

