-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f6246609456e3efa
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: step_log_update

UPDATE intermodal_transfer.container_handoff_step_log SET status = $2, result = $3, completed_at = NOW() WHERE saga_id = $1 AND step_name = $4 AND completed_at IS NULL