-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f1c00e7a7ff8242d
--  context: IntermodalTransfer, entity: ChassisUnit, operation: select_by_id

SELECT id, chassis_number, chassis_type, is_available FROM intermodal_transfer.chassis_unit WHERE id = $1