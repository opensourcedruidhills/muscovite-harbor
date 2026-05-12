-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:baf366a784220081
--  context: IntermodalTransfer, entity: TransferSlot, operation: update

UPDATE intermodal_transfer.transfer_slot SET id = $2, reference = $3, container_id = $4, transport_mode = $5, scheduled_at = $6, status = $7 WHERE id = $1