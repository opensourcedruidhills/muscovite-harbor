# Strategic Narrative

## Overview

MuscoviteHarbor operates across 6 bounded contexts: VesselTraffic, CargoOperations, PassengerTerminal, IntermodalTransfer, CargoDecomposition, HarbourControl.

The core domain comprises 28 entities and 23 domain events,
organized into 7 aggregates.

## Key Architectural Decisions

- Domain boundaries enforce 6 separation-of-concerns boundaries
- 4 commands coordinate state transitions
- 23 events propagate domain changes asynchronously
