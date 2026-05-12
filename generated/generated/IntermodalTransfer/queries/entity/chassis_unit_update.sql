-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:4a51e8a0cb79dbee
--  context: IntermodalTransfer, entity: ChassisUnit, operation: update

UPDATE intermodal_transfer.chassis_unit SET id = $2, chassis_number = $3, chassis_type = $4, is_available = $5 WHERE id = $1