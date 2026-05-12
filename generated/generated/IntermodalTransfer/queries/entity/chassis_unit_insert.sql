-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:58c758bc6ff15ac5
--  context: IntermodalTransfer, entity: ChassisUnit, operation: insert

INSERT INTO intermodal_transfer.chassis_unit (id, id, chassis_number, chassis_type, is_available) VALUES ($1, $2, $3, $4, $5) RETURNING id