# Flow Choreography Diagrams

## IntermodalTransfer

### YardToTruck

> Choreography: container from yard to truck

```mermaid
sequenceDiagram
    IntermodalTransfer->>IntermodalTransfer: ContainerAtGate
    IntermodalTransfer->>IntermodalTransfer: ContainerWeighed
    Note over IntermodalTransfer: GateRelease COMPLETES
```

### YardToRail

> Choreography: container from yard to rail wagon

```mermaid
sequenceDiagram
    IntermodalTransfer->>IntermodalTransfer: ContainerAtRailHead
    IntermodalTransfer->>IntermodalTransfer: ContainerOnWagon
    Note over IntermodalTransfer: TrainDepart COMPLETES
```

