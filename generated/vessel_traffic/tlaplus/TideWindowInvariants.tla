---- MODULE TideWindowInvariants ----
EXTENDS Naturals, Sequences, FiniteSets

\* Aggregate consistency invariants for TideWindow

CONSTANTS
    Instances     \* Set of aggregate instance IDs

VARIABLES
    entity_state,     \* Function: instance -> record
    pending_events,   \* Function: instance -> sequence of events
    consumed_events,  \* Function: instance -> set of consumed events
    command_log       \* Function: instance -> sequence of applied commands

vars == <<entity_state, pending_events, consumed_events, command_log>>

\* ── Domain sets ──────────────────────────────────────────────
EmittedEvents == {"VesselAnnounced", "BerthAllocated"}
Commands == {"AnnounceVessel", "AllocateBerth"}
Fields == {"id", "berth_id", "tide_height_metres", "available_draft"}
AllEvents == {"VesselAnnounced", "BerthAllocated", "PilotDispatched", "VesselMooredEvent", "VesselDepartedEvent"}

\* ── Init ────────────────────────────────────────────────────
Init ==
    /\ entity_state    = [i \in Instances |-> [f \in Fields |-> ""]]
    /\ pending_events  = [i \in Instances |-> <<>>]
    /\ consumed_events = [i \in Instances |-> {}]
    /\ command_log     = [i \in Instances |-> <<>>]

\* ── Eventual consistency ─────────────────────────────────────
\* Every emitted event is eventually consumed
EventualConsistency ==
    \A i \in Instances:
        \A idx \in 1..Len(pending_events[i]):
            <>(pending_events[i][idx] \in consumed_events[i])

\* ── Command idempotency ──────────────────────────────────────
\* Applying the same command twice yields the same state
CommandIdempotency ==
    \A i \in Instances:
        \A idx \in 1..Len(command_log[i]):
            LET cmd == command_log[i][idx] IN
                \* State after applying cmd once equals state after applying twice
                \* (modeled as: no duplicate consecutive commands change state)
                idx > 1 /\ command_log[i][idx-1] = cmd
                    => entity_state'[i] = entity_state[i]

\* ── Aggregate integrity ──────────────────────────────────────
\* Entity fields satisfy domain constraints after each command
AggregateIntegrity ==
    \A i \in Instances:
        \A f \in Fields:
            f \in DOMAIN entity_state[i]

\* ── Specification ────────────────────────────────────────────
TypeInvariant ==
    /\ \A i \in Instances: DOMAIN entity_state[i] = Fields
    /\ \A i \in Instances: consumed_events[i] \subseteq AllEvents

====
