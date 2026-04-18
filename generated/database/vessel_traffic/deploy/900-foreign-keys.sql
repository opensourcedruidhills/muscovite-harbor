-- Deploy: vessel_traffic/foreign-keys

BEGIN;

SET search_path TO vessel_traffic, public;

ALTER TABLE voyages ADD CONSTRAINT fk_voyages_voyage_id FOREIGN KEY (vessel_id) REFERENCES vessel_traffic.vessels (id);
ALTER TABLE pilot_assignments ADD CONSTRAINT fk_pilot_assignments_pilot_assignment_id FOREIGN KEY (voyage_id) REFERENCES vessel_traffic.voyages (id);
ALTER TABLE tug_bookings ADD CONSTRAINT fk_tug_bookings_tug_booking_id FOREIGN KEY (voyage_id) REFERENCES vessel_traffic.voyages (id);
ALTER TABLE tide_windows ADD CONSTRAINT fk_tide_windows_tide_window_id FOREIGN KEY (berth_id) REFERENCES vessel_traffic.berths (id);

COMMIT;
