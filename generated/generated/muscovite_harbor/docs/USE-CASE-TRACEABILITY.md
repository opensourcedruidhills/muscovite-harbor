# Use Case Traceability Matrix

## PassengerTerminal

### Use Cases

| Use Case | Actors | Creates | Reads | Updates | Triggers |
|----------|--------|---------|-------|---------|----------|
| PassengerCheckIn | Ticket Agent | BoardingPass | — | Passenger | PassengerCheckedIn |

### use_case_chains[]

- use_case: PassengerCheckIn
  flows[]: []

### warnings[]

- use_case: PassengerCheckIn
  trigger: PassengerCheckedIn
  warning: No FLOW in context PassengerTerminal references trigger 'PassengerCheckedIn'

### Entity → Use Cases

| Entity | [AR] | Referenced By |
|--------|------|---------------|
| BoardingPass |  | PassengerCheckIn |
| Passenger | ✓ | PassengerCheckIn |

### User Stories

| Story | As a... | I want to... | So that... |
|-------|---------|-------------|------------|
| DepartureInfo | A passenger | See real-time departure information on terminal displays | I can plan my arrival at the correct gate |
| FastCheckIn | A ticket agent | Complete passenger check-in in under 60 seconds | Queues remain short during peak boarding times |

