-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f7294d966980f0ee
--  context: IntermodalTransfer, entity: RailWagon, operation: select_by_id

SELECT id, wagon_number, max_weight_kg, slot_id FROM intermodal_transfer.rail_wagon WHERE id = $1