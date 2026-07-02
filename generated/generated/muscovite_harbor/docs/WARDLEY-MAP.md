# Wardley Map

```wardley
title MuscoviteHarbor Value Chain
anchor Business [0.95, 0.63]
component VesselTraffic [0.30, 0.80]
component CargoOperations [0.60, 0.68]
component PassengerTerminal [0.60, 0.56]
component IntermodalTransfer [0.60, 0.44]
component CargoDecomposition [0.85, 0.32]
component HarbourControl [0.85, 0.20]
VesselTraffic -> CargoOperations
VesselTraffic -> PassengerTerminal
CargoOperations -> IntermodalTransfer
CargoOperations -> CargoDecomposition
IntermodalTransfer -> CargoDecomposition
HarbourControl -> VesselTraffic
HarbourControl -> CargoOperations
IntermodalTransfer -> HarbourControl
VesselTraffic -> CargoOperations
VesselTraffic -> PassengerTerminal
CargoOperations -> IntermodalTransfer
CargoOperations -> CargoDecomposition
IntermodalTransfer -> CargoDecomposition
HarbourControl -> VesselTraffic
HarbourControl -> CargoOperations
IntermodalTransfer -> HarbourControl
```
