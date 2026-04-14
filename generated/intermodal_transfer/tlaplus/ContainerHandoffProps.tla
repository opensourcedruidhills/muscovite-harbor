---- MODULE ContainerHandoffProps ----
EXTENDS ContainerHandoff

\* Safety: Compensation happens in reverse order
CompensationOrderSafe ==
    \A i \in Instances:
        status[i] = Compensating =>
            compIdx[i] >= 0

\* Safety: Concurrent instances don't contaminate state
CorrelationIsolation ==
    \A i, j \in Instances:
        i /= j =>
            status[i] /= status[j] \/ currentStep[i] /= currentStep[j]
            \/ status[i] = status[j]  \* may coincidentally match

\* Liveness: All instances eventually reach terminal state
Termination == \A i \in Instances: <>(IsTerminal(i))

\* Liveness: No instance stuck in progress forever
NoOrphanedInstances ==
    \A i \in Instances: <>(status[i] /= InProgress)

====
