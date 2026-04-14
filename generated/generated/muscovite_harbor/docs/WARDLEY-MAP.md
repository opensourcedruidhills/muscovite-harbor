# Wardley Map

## Context Evolution Stages

| Stage | Contexts |
|-------|----------|
| CUSTOM | VesselTraffic |
| PRODUCT | CargoOperations, PassengerTerminal, IntermodalTransfer |
| COMMODITY | CargoDecomposition, HarbourControl |

## Context Map with Evolution

```mermaid
graph LR
    VesselTraffic["VesselTraffic\n(CUSTOM)"]
    CargoOperations["CargoOperations\n(PRODUCT)"]
    PassengerTerminal["PassengerTerminal\n(PRODUCT)"]
    IntermodalTransfer["IntermodalTransfer\n(PRODUCT)"]
    CargoDecomposition["CargoDecomposition\n(COMMODITY)"]
    HarbourControl["HarbourControl\n(COMMODITY)"]
    VesselTraffic -->|customer-supplier| CargoOperations
    VesselTraffic -->|customer-supplier| PassengerTerminal
    CargoOperations -->|partnership| IntermodalTransfer
    CargoOperations -->|customer-supplier| CargoDecomposition
    IntermodalTransfer -->|open-host-service| CargoDecomposition
    HarbourControl -->|anticorruption-layer| VesselTraffic
    HarbourControl -->|conformist| CargoOperations
    IntermodalTransfer -->|shared-kernel| HarbourControl
    VesselTraffic -->|customer-supplier| CargoOperations
    VesselTraffic -->|customer-supplier| PassengerTerminal
    CargoOperations -->|partnership| IntermodalTransfer
    CargoOperations -->|customer-supplier| CargoDecomposition
    IntermodalTransfer -->|open-host-service| CargoDecomposition
    HarbourControl -->|anticorruption-layer| VesselTraffic
    HarbourControl -->|conformist| CargoOperations
    IntermodalTransfer -->|customer-supplier| HarbourControl
```
