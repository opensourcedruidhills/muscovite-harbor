-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:72f21e8efaf176b0
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: saga_complete

UPDATE intermodal_transfer.container_handoff_saga SET status = 'completed', version = version + 1, updated_at = NOW() WHERE id = $1 AND version = $2