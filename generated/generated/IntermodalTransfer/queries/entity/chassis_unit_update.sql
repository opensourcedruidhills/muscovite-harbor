-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b46da29553ef6ff1
--  context: IntermodalTransfer, entity: ChassisUnit, operation: update

UPDATE intermodal_transfer.chassis_unit SET chassis_number = $2, chassis_type = $3, is_available = $4 WHERE id = $1