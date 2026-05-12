-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:285fcba712649f3e
--  context: IntermodalTransfer, entity: RailWagon, operation: insert

INSERT INTO intermodal_transfer.rail_wagon (id, id, wagon_number, max_weight_kg, slot_id) VALUES ($1, $2, $3, $4, $5) RETURNING id