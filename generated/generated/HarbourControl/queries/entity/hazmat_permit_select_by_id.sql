-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:70d8760fd0a6eefb
--  context: HarbourControl, entity: HazmatPermit, operation: select_by_id

SELECT id, id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until FROM harbour_control.hazmat_permit WHERE id = $1