# Domain Index

> Auto-generated from doc::DomainIndex. Do not edit manually.

## VesselTraffic

- [Vessel](#vessel-traffic-vessel) — Entity
- [Berth](#vessel-traffic-berth) — Entity
- [Voyage](#vessel-traffic-voyage) — Entity
- [PilotAssignment](#vessel-traffic-pilot-assignment) — Entity
- [TugBooking](#vessel-traffic-tug-booking) — Entity
- [TideWindow](#vessel-traffic-tide-window) — Entity
- [Dimensions](#vessel-traffic-dimensions) — ValueObject
- [GeoPosition](#vessel-traffic-geo-position) — ValueObject
- [TimeWindow](#vessel-traffic-time-window) — ValueObject
- [VesselAnnounced](#vessel-traffic-vessel-announced) — DomainEvent
- [BerthAllocated](#vessel-traffic-berth-allocated) — DomainEvent
- [PilotDispatched](#vessel-traffic-pilot-dispatched) — DomainEvent
- [VesselMooredEvent](#vessel-traffic-vessel-moored-event) — DomainEvent
- [VesselDepartedEvent](#vessel-traffic-vessel-departed-event) — DomainEvent
- [BerthOccupancyBoard](#vessel-traffic-berth-occupancy-board) — Projection
- [VesselMovementLog](#vessel-traffic-vessel-movement-log) — Projection

### VesselTraffic.Vessel {#vessel-traffic-vessel}

- Kind: Entity
- Fields: 9
- Definition: A registered vessel in the harbour traffic system

### VesselTraffic.Berth {#vessel-traffic-berth}

- Kind: Entity
- Fields: 10
- Definition: A physical berth where vessels moor

### VesselTraffic.Voyage {#vessel-traffic-voyage}

- Kind: Entity
- Fields: 11
- Definition: A single vessel call at the harbour

### VesselTraffic.PilotAssignment {#vessel-traffic-pilot-assignment}

- Kind: Entity
- Fields: 7
- Definition: Assignment of a pilot to a voyage

### VesselTraffic.TugBooking {#vessel-traffic-tug-booking}

- Kind: Entity
- Fields: 6
- Definition: Booking of a tug for vessel manoeuvring

### VesselTraffic.TideWindow {#vessel-traffic-tide-window}

- Kind: Entity
- Fields: 5
- Definition: A tidal window with navigable draft at a specific berth

### VesselTraffic.Dimensions {#vessel-traffic-dimensions}

- Kind: ValueObject
- Fields: 3

### VesselTraffic.GeoPosition {#vessel-traffic-geo-position}

- Kind: ValueObject
- Fields: 2

### VesselTraffic.TimeWindow {#vessel-traffic-time-window}

- Kind: ValueObject
- Fields: 2

### VesselTraffic.VesselAnnounced {#vessel-traffic-vessel-announced}

- Kind: DomainEvent
- Fields: 3
- Definition: A vessel has announced its arrival

### VesselTraffic.BerthAllocated {#vessel-traffic-berth-allocated}

- Kind: DomainEvent
- Fields: 2
- Definition: A berth has been allocated to a voyage

### VesselTraffic.PilotDispatched {#vessel-traffic-pilot-dispatched}

- Kind: DomainEvent
- Fields: 2
- Definition: Pilot dispatched to meet inbound vessel

### VesselTraffic.VesselMooredEvent {#vessel-traffic-vessel-moored-event}

- Kind: DomainEvent
- Fields: 3
- Definition: Vessel has been moored at berth

### VesselTraffic.VesselDepartedEvent {#vessel-traffic-vessel-departed-event}

- Kind: DomainEvent
- Fields: 2
- Definition: Vessel has departed harbour

### VesselTraffic.BerthOccupancyBoard {#vessel-traffic-berth-occupancy-board}

- Kind: Projection
- Fields: 7
- Definition: Real-time berth occupancy display for harbour control room

### VesselTraffic.VesselMovementLog {#vessel-traffic-vessel-movement-log}

- Kind: Projection
- Fields: 5
- Definition: Audit log of all vessel movements (maritime law compliance)

## CargoOperations

- [Container](#cargo-operations-container) — Entity
- [YardSlot](#cargo-operations-yard-slot) — Entity
- [Crane](#cargo-operations-crane) — Entity
- [ReeferUnit](#cargo-operations-reefer-unit) — Entity
- [LoadPlan](#cargo-operations-load-plan) — Entity
- [DischargeSequence](#cargo-operations-discharge-sequence) — Entity
- [ContainerDimensions](#cargo-operations-container-dimensions) — ValueObject

### CargoOperations.Container {#cargo-operations-container}

- Kind: Entity
- Fields: 8
- Definition: A shipping container in terminal operations

### CargoOperations.YardSlot {#cargo-operations-yard-slot}

- Kind: Entity
- Fields: 7
- Definition: A position in the container yard (bay-row-tier)

### CargoOperations.Crane {#cargo-operations-crane}

- Kind: Entity
- Fields: 6
- Definition: A crane for container handling

### CargoOperations.ReeferUnit {#cargo-operations-reefer-unit}

- Kind: Entity
- Fields: 6
- Definition: Refrigeration monitoring unit for a reefer container

### CargoOperations.LoadPlan {#cargo-operations-load-plan}

- Kind: Entity
- Fields: 5
- Definition: Plan for loading/discharging containers for a voyage

### CargoOperations.DischargeSequence {#cargo-operations-discharge-sequence}

- Kind: Entity
- Fields: 6
- Definition: Ordered sequence for container discharge

### CargoOperations.ContainerDimensions {#cargo-operations-container-dimensions}

- Kind: ValueObject
- Fields: 3

## PassengerTerminal

- [Passenger](#passenger-terminal-passenger) — Entity
- [Gate](#passenger-terminal-gate) — Entity
- [BoardingPass](#passenger-terminal-boarding-pass) — Entity
- [PassengerName](#passenger-terminal-passenger-name) — ValueObject
- [PassengerCheckedIn](#passenger-terminal-passenger-checked-in) — DomainEvent
- [BoardingPassIssued](#passenger-terminal-boarding-pass-issued) — DomainEvent
- [GateStatusChanged](#passenger-terminal-gate-status-changed) — DomainEvent
- [DepartureBoard](#passenger-terminal-departure-board) — Projection
- [ArrivalBoard](#passenger-terminal-arrival-board) — Projection

### PassengerTerminal.Passenger {#passenger-terminal-passenger}

- Kind: Entity
- Fields: 6
- Definition: A passenger travelling on a voyage

### PassengerTerminal.Gate {#passenger-terminal-gate}

- Kind: Entity
- Fields: 7
- Definition: A physical gate in the passenger terminal

### PassengerTerminal.BoardingPass {#passenger-terminal-boarding-pass}

- Kind: Entity
- Fields: 8
- Definition: Issued boarding pass for a passenger

### PassengerTerminal.PassengerName {#passenger-terminal-passenger-name}

- Kind: ValueObject
- Fields: 2

### PassengerTerminal.PassengerCheckedIn {#passenger-terminal-passenger-checked-in}

- Kind: DomainEvent
- Fields: 3
- Definition: Passenger completed check-in

### PassengerTerminal.BoardingPassIssued {#passenger-terminal-boarding-pass-issued}

- Kind: DomainEvent
- Fields: 3
- Definition: Boarding pass issued to passenger

### PassengerTerminal.GateStatusChanged {#passenger-terminal-gate-status-changed}

- Kind: DomainEvent
- Fields: 2
- Definition: Gate status transition

### PassengerTerminal.DepartureBoard {#passenger-terminal-departure-board}

- Kind: Projection
- Fields: 6
- Definition: Departure display board — updated on gate status change

### PassengerTerminal.ArrivalBoard {#passenger-terminal-arrival-board}

- Kind: Projection
- Fields: 5
- Definition: Real-time arrival board — updated on check-in and boarding events

## IntermodalTransfer

- [TransferSlot](#intermodal-transfer-transfer-slot) — Entity
- [TruckVisit](#intermodal-transfer-truck-visit) — Entity
- [RailWagon](#intermodal-transfer-rail-wagon) — Entity
- [BargeBooking](#intermodal-transfer-barge-booking) — Entity
- [ChassisUnit](#intermodal-transfer-chassis-unit) — Entity
- [YardExitReserved](#intermodal-transfer-yard-exit-reserved) — DomainEvent
- [GateCheckoutCompleted](#intermodal-transfer-gate-checkout-completed) — DomainEvent
- [TransportLoaded](#intermodal-transfer-transport-loaded) — DomainEvent
- [DepartureConfirmed](#intermodal-transfer-departure-confirmed) — DomainEvent
- [HandoffFailed](#intermodal-transfer-handoff-failed) — DomainEvent

### IntermodalTransfer.TransferSlot {#intermodal-transfer-transfer-slot}

- Kind: Entity
- Fields: 7
- Definition: A time slot for container transfer to outbound transport

### IntermodalTransfer.TruckVisit {#intermodal-transfer-truck-visit}

- Kind: Entity
- Fields: 7
- Definition: A truck arriving for container pickup

### IntermodalTransfer.RailWagon {#intermodal-transfer-rail-wagon}

- Kind: Entity
- Fields: 5
- Definition: A rail wagon for container transport

### IntermodalTransfer.BargeBooking {#intermodal-transfer-barge-booking}

- Kind: Entity
- Fields: 6
- Definition: Booking for barge transport of containers

### IntermodalTransfer.ChassisUnit {#intermodal-transfer-chassis-unit}

- Kind: Entity
- Fields: 5
- Definition: Chassis for container road transport

### IntermodalTransfer.YardExitReserved {#intermodal-transfer-yard-exit-reserved}

- Kind: DomainEvent
- Fields: 2
- Definition: Yard exit slot reserved for container

### IntermodalTransfer.GateCheckoutCompleted {#intermodal-transfer-gate-checkout-completed}

- Kind: DomainEvent
- Fields: 2
- Definition: Container cleared gate checkout

### IntermodalTransfer.TransportLoaded {#intermodal-transfer-transport-loaded}

- Kind: DomainEvent
- Fields: 2
- Definition: Container loaded onto outbound transport

### IntermodalTransfer.DepartureConfirmed {#intermodal-transfer-departure-confirmed}

- Kind: DomainEvent
- Fields: 2
- Definition: Outbound transport has departed

### IntermodalTransfer.HandoffFailed {#intermodal-transfer-handoff-failed}

- Kind: DomainEvent
- Fields: 2
- Definition: Handoff failed — requires compensation

## CargoDecomposition

- [Pallet](#cargo-decomposition-pallet) — Entity
- [Parcel](#cargo-decomposition-parcel) — Entity
- [DeliveryUnit](#cargo-decomposition-delivery-unit) — Entity
- [BreakBulkItem](#cargo-decomposition-break-bulk-item) — Entity
- [Dimensions](#cargo-decomposition-dimensions) — ValueObject
- [Weight](#cargo-decomposition-weight) — ValueObject
- [ContainerUnpacked](#cargo-decomposition-container-unpacked) — DomainEvent
- [PalletWeightVerified](#cargo-decomposition-pallet-weight-verified) — DomainEvent
- [ParcelDispatched](#cargo-decomposition-parcel-dispatched) — DomainEvent

### CargoDecomposition.Pallet {#cargo-decomposition-pallet}

- Kind: Entity
- Fields: 9
- Definition: A pallet extracted from a container

### CargoDecomposition.Parcel {#cargo-decomposition-parcel}

- Kind: Entity
- Fields: 7
- Definition: An individual parcel within a pallet

### CargoDecomposition.DeliveryUnit {#cargo-decomposition-delivery-unit}

- Kind: Entity
- Fields: 6
- Definition: Last-mile delivery unit dispatched from terminal

### CargoDecomposition.BreakBulkItem {#cargo-decomposition-break-bulk-item}

- Kind: Entity
- Fields: 6
- Definition: Non-containerised cargo item requiring special handling

### CargoDecomposition.Dimensions {#cargo-decomposition-dimensions}

- Kind: ValueObject
- Fields: 3

### CargoDecomposition.Weight {#cargo-decomposition-weight}

- Kind: ValueObject
- Fields: 1

### CargoDecomposition.ContainerUnpacked {#cargo-decomposition-container-unpacked}

- Kind: DomainEvent
- Fields: 2
- Definition: Container has been fully unpacked into pallets

### CargoDecomposition.PalletWeightVerified {#cargo-decomposition-pallet-weight-verified}

- Kind: DomainEvent
- Fields: 2
- Definition: Pallet weight verified against manifest

### CargoDecomposition.ParcelDispatched {#cargo-decomposition-parcel-dispatched}

- Kind: DomainEvent
- Fields: 2
- Definition: Parcel dispatched for last-mile delivery

## HarbourControl

- [SafetyZone](#harbour-control-safety-zone) — Entity
- [HazmatPermit](#harbour-control-hazmat-permit) — Entity
- [InvoiceLine](#harbour-control-invoice-line) — Entity
- [PortCall](#harbour-control-port-call) — Entity
- [VesselPositionUpdated](#harbour-control-vessel-position-updated) — DomainEvent
- [HazmatPermitApproved](#harbour-control-hazmat-permit-approved) — DomainEvent

### HarbourControl.SafetyZone {#harbour-control-safety-zone}

- Kind: Entity
- Fields: 7
- Definition: Designated safety zone within the port area

### HarbourControl.HazmatPermit {#harbour-control-hazmat-permit}

- Kind: Entity
- Fields: 9
- Definition: Hazmat handling permit issued by port authority

### HarbourControl.InvoiceLine {#harbour-control-invoice-line}

- Kind: Entity
- Fields: 7
- Definition: Port services invoice line item

### HarbourControl.PortCall {#harbour-control-port-call}

- Kind: Entity
- Fields: 10
- Definition: Read-only aggregation across VesselTraffic, CargoOps, and billing

### HarbourControl.VesselPositionUpdated {#harbour-control-vessel-position-updated}

- Kind: DomainEvent
- Fields: 3
- Definition: Vessel position update from radar translation

### HarbourControl.HazmatPermitApproved {#harbour-control-hazmat-permit-approved}

- Kind: DomainEvent
- Fields: 2
- Definition: Hazmat permit approved by port authority

