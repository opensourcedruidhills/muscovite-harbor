-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:0164e129b8ec8e88
--  context: IntermodalTransfer, entity: TransferSlot, operation: update

UPDATE intermodal_transfer.transfer_slot SET reference = $2, container_id = $3, transport_mode = $4, scheduled_at = $5, status = $6 WHERE id = $1