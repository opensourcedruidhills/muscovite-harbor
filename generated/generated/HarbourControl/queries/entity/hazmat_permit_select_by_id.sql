-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:4c9fc3ea7dcf1c8a
--  context: HarbourControl, entity: HazmatPermit, operation: select_by_id

SELECT id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until FROM harbour_control.hazmat_permit WHERE id = $1