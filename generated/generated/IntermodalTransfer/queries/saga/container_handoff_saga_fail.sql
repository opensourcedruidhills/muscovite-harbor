-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c235bb628a4535dd
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: saga_fail

UPDATE intermodal_transfer.container_handoff_saga SET status = 'failed', failure_reason = $2, version = version + 1, updated_at = NOW() WHERE id = $1 AND version = $3