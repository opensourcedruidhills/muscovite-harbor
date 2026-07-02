-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8d2dd93a3a679000
--  context: IntermodalTransfer, entity: RailWagon, operation: insert

INSERT INTO intermodal_transfer.rail_wagon (id, wagon_number, max_weight_kg, slot_id) VALUES ($1, $2, $3, $4) RETURNING id