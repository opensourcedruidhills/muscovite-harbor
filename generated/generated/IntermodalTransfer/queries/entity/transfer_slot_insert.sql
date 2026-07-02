-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:5808b79b384a6294
--  context: IntermodalTransfer, entity: TransferSlot, operation: insert

INSERT INTO intermodal_transfer.transfer_slot (id, reference, container_id, transport_mode, scheduled_at, status) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id