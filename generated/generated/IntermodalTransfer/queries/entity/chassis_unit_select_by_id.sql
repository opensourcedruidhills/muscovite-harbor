-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ca15e9bbaa13fb54
--  context: IntermodalTransfer, entity: ChassisUnit, operation: select_by_id

SELECT id, id, chassis_number, chassis_type, is_available FROM intermodal_transfer.chassis_unit WHERE id = $1