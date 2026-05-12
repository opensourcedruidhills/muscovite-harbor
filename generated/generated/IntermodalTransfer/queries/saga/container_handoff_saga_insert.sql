-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:23a4355e1220ad2b
--  context: IntermodalTransfer, saga: ContainerHandoff, operation: saga_insert

INSERT INTO intermodal_transfer.container_handoff_saga (id, status, current_step, payload, created_at, updated_at, version) VALUES ($1, 'pending', $2, $3, NOW(), NOW(), 0)