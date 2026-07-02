# API

## VesselTraffic

### Commands

#### AnnounceVessel

**Entity**: Voyage

#### AllocateBerth

**Entity**: Voyage

### Events

#### VesselAnnounced

#### BerthAllocated

#### PilotDispatched

#### VesselMooredEvent

#### VesselDepartedEvent


## CargoOperations

### Commands

#### PlaceContainer

**Entity**: Container

#### PickContainer

**Entity**: Container

### Events

#### ContainerPlaced (sourced)

#### ContainerPicked (sourced)

#### ContainerMoved (sourced)

#### ReeferAlarm (sourced)

#### DamageReported (sourced)


## PassengerTerminal

### Events

#### PassengerCheckedIn

#### BoardingPassIssued

#### GateStatusChanged


## IntermodalTransfer

### Events

#### YardExitReserved

#### GateCheckoutCompleted

#### TransportLoaded

#### DepartureConfirmed

#### HandoffFailed


## CargoDecomposition

### Events

#### ContainerUnpacked

#### PalletWeightVerified

#### ParcelDispatched


## HarbourControl

### Events

#### VesselPositionUpdated

#### HazmatPermitApproved


