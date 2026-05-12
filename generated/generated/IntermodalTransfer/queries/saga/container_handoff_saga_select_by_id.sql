-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:4675187712ebde07
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: saga_select_by_id

SELECT id, status, current_step, payload, created_at, updated_at, version FROM intermodal_transfer.container_handoff_saga WHERE id = $1