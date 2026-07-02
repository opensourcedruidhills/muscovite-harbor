-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:53175a6330cc9cfe
--  context: IntermodalTransfer, entity: RailWagon, operation: update

UPDATE intermodal_transfer.rail_wagon SET wagon_number = $2, max_weight_kg = $3, slot_id = $4 WHERE id = $1