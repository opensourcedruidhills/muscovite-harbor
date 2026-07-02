-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:567e41ed058edfaf
--  context: IntermodalTransfer, entity: ChassisUnit, operation: insert

INSERT INTO intermodal_transfer.chassis_unit (id, chassis_number, chassis_type, is_available) VALUES ($1, $2, $3, $4) RETURNING id