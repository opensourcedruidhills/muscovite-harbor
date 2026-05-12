-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f3d96416807ffa32
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: step_log_select

SELECT saga_id, step_name, status, result, started_at, completed_at FROM intermodal_transfer.container_handoff_step_log WHERE saga_id = $1 ORDER BY started_at