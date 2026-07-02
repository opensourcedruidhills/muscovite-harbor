-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:1024ab2a353b1b2a
--  context: HarbourControl, entity: HazmatPermit, operation: select_all

SELECT id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until FROM harbour_control.hazmat_permit ORDER BY id