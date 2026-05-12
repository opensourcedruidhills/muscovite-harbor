-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:aaec3a399dc366cb
--  context: IntermodalTransfer, entity: RailWagon, operation: select_by_id

SELECT id, id, wagon_number, max_weight_kg, slot_id FROM intermodal_transfer.rail_wagon WHERE id = $1