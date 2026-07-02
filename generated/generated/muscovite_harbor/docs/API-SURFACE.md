# API Surface

## VesselTraffic

### Public API
- AnnounceVessel (command)
- AllocateBerth (command)
- VesselAnnounced (event)
- BerthAllocated (event)
- PilotDispatched (event)
- VesselMooredEvent (event)
- VesselDepartedEvent (event)

### Internal API
_None_

## CargoOperations

### Public API
- PlaceContainer (command)
- PickContainer (command)
- ContainerPlaced (event)
- ContainerPicked (event)
- ContainerMoved (event)
- ReeferAlarm (event)
- DamageReported (event)

### Internal API
_None_

## PassengerTerminal

### Public API
- PassengerCheckedIn (event)
- BoardingPassIssued (event)
- GateStatusChanged (event)

### Internal API
_None_

## IntermodalTransfer

### Public API
- YardExitReserved (event)
- GateCheckoutCompleted (event)
- TransportLoaded (event)
- DepartureConfirmed (event)
- HandoffFailed (event)

### Internal API
_None_

## CargoDecomposition

### Public API
- ContainerUnpacked (event)
- PalletWeightVerified (event)
- ParcelDispatched (event)

### Internal API
_None_

## HarbourControl

### Public API
- VesselPositionUpdated (event)
- HazmatPermitApproved (event)

### Internal API
_None_

