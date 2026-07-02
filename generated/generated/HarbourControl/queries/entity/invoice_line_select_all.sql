-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:93f5aedb929e90d7
--  context: HarbourControl, entity: InvoiceLine, operation: select_all

SELECT id, vessel_id, service_type, amount, currency, issued_at FROM harbour_control.invoice_line ORDER BY id