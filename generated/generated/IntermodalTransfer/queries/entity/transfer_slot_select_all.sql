-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d57f1301382a7b43
--  context: IntermodalTransfer, entity: TransferSlot, operation: select_all

SELECT id, reference, container_id, transport_mode, scheduled_at, status FROM intermodal_transfer.transfer_slot ORDER BY id