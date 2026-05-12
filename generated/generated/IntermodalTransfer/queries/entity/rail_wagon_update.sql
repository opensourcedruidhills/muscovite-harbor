-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6722b33ee50b20bb
--  context: IntermodalTransfer, entity: RailWagon, operation: update

UPDATE intermodal_transfer.rail_wagon SET id = $2, wagon_number = $3, max_weight_kg = $4, slot_id = $5 WHERE id = $1