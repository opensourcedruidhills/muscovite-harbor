-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:86c62c0a53a4c242
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: saga_advance

UPDATE intermodal_transfer.container_handoff_saga SET current_step = $2, status = 'in_progress', version = version + 1, updated_at = NOW() WHERE id = $1 AND version = $3