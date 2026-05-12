-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:08f39e29001767c6
--  context: IntermodalTransfer, entity: TransferSlot, operation: insert

INSERT INTO intermodal_transfer.transfer_slot (id, id, reference, container_id, transport_mode, scheduled_at, status) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id