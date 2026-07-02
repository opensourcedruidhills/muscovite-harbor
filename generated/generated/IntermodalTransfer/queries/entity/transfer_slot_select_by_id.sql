-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2c2872fdaa6dee93
--  context: IntermodalTransfer, entity: TransferSlot, operation: select_by_id

SELECT id, reference, container_id, transport_mode, scheduled_at, status FROM intermodal_transfer.transfer_slot WHERE id = $1