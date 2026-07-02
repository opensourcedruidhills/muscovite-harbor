-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:aa1ea4d87e371bb4
--  context: HarbourControl, entity: InvoiceLine, operation: insert

INSERT INTO harbour_control.invoice_line (id, vessel_id, service_type, amount, currency, issued_at) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id