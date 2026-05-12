-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:87ce3a71fe054880
--  context: HarbourControl, entity: InvoiceLine, operation: insert

INSERT INTO harbour_control.invoice_line (id, id, vessel_id, service_type, amount, currency, issued_at) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id