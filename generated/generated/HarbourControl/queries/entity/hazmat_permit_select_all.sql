-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:daec286934aff5cb
--  context: HarbourControl, entity: HazmatPermit, operation: select_all

SELECT id, id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until FROM harbour_control.hazmat_permit ORDER BY id