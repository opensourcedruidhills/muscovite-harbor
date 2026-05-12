-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9fd510e8fb6bbfc5
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: saga_timed_out

SELECT id FROM intermodal_transfer.container_handoff_saga WHERE status = 'in_progress' AND created_at < NOW() - $1 * interval '1 second'