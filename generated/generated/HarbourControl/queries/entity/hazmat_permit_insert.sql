-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2d01ce1e8f967c8a
--  context: HarbourControl, entity: HazmatPermit, operation: insert

INSERT INTO harbour_control.hazmat_permit (id, permit_number, vessel_id, imo_class, quantity_kg, approved, valid_from, valid_until) VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING id