-- Deploy: vessel_traffic/indexes

BEGIN;

SET search_path TO vessel_traffic, public;

CREATE INDEX IF NOT EXISTS idx_voyages_voyage_id ON voyages (vessel_id);
CREATE INDEX IF NOT EXISTS idx_pilot_assignments_pilot_assignment_id ON pilot_assignments (voyage_id);
CREATE INDEX IF NOT EXISTS idx_tug_bookings_tug_booking_id ON tug_bookings (voyage_id);
CREATE INDEX IF NOT EXISTS idx_tide_windows_tide_window_id ON tide_windows (berth_id);
CREATE INDEX IF NOT EXISTS idx_outbox_unprocessed ON outbox (created_at);

COMMIT;
