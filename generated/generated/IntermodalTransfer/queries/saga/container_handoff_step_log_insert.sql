-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:11679f23c5c9f149
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: step_log_insert

INSERT INTO intermodal_transfer.container_handoff_step_log (saga_id, step_name, status, started_at) VALUES ($1, $2, 'pending', NOW())