# Type Mappings

**STRICT POLICY**: Unknown types cause generation to **FAIL**. No silent fallbacks.
Use only types listed below in `.ddd` field declarations.

## Complete Mapping Table

| DSL Type | PostgreSQL | C++ DBA | gRPC Proto | Qt Widget | Qt QML |
|----------|------------|---------|------------|-----------|--------|
| **Primitives** | | | | | |
| UUID | `UUID` | `boost::uuids::uuid` | `muscovite.common.UUID` | `QLineEdit` | `string` |
| String, TEXT | `TEXT` | `std::string` | `string` | `QLineEdit` | `string` |
| Integer, INT | `INTEGER` | `std::int32_t` | `int32` | `QSpinBox` | `int` |
| BigInteger, BIGINT | `BIGINT` | `std::int64_t` | `int64` | `QSpinBox` | `int` |
| Decimal, NUMERIC | `NUMERIC` | `muscovite::dba::Decimal` | `muscovite.common.Decimal` | `QLineEdit` | `string` |
| Boolean, BOOL | `BOOLEAN` | `bool` | `bool` | `QCheckBox` | `bool` |
| **Temporal** | | | | | |
| Date, DATE | `DATE` | `muscovite::dba::Date` | `muscovite.common.Date` | `QDateEdit` | `date` |
| Time, TIMETZ | `TIME` | `muscovite::dba::TimeOfDay` | `muscovite.common.TimeOfDay` | `QTimeEdit` | `var` |
| DateTime, TIMESTAMPTZ | `TIMESTAMPTZ` | `muscovite::dba::Timestamp` | `muscovite.common.Timestamp` | `QDateTimeEdit` | `date` |
| Interval | `INTERVAL` | `std::string` | `muscovite.common.Interval` | `QLineEdit` | `string` |
| **Strong Types** | | | | | |
| Email | `TEXT` (DOMAIN) | `std::string` | `muscovite.common.Email` | `QLineEdit` | `string` |
| Phone | `TEXT` (DOMAIN) | `std::string` | `muscovite.common.Phone` | `QLineEdit` | `string` |
| PostalCode | `TEXT` (DOMAIN) | `std::string` | `muscovite.common.PostalCode` | `QLineEdit` | `string` |
| URL | `TEXT` (DOMAIN) | `std::string` | `muscovite.common.Url` | `QLineEdit` | `string` |
| Code | `TEXT` (DOMAIN) | `std::string` | `string` | `QLineEdit` | `string` |
| NonEmptyString | `TEXT` (DOMAIN) | `std::string` | `string` | `QLineEdit` | `string` |
| CountryCode | `TEXT` (DOMAIN) | `std::string` | `string` | `QLineEdit` | `string` |
| LanguageCode | `TEXT` (DOMAIN) | `std::string` | `string` | `QLineEdit` | `string` |
| PositiveInteger | `INTEGER` (DOMAIN) | `std::int32_t` | `int32` | `QSpinBox` | `int` |
| PositiveDecimal | `NUMERIC` (DOMAIN) | `muscovite::dba::Decimal` | `muscovite.common.PositiveDecimal` | `QLineEdit` | `string` |
| Latitude | `NUMERIC(9,6)` (DOMAIN) | `muscovite::dba::Decimal` | `muscovite.common.Decimal` | `QLineEdit` | `double` |
| Longitude | `NUMERIC(10,6)` (DOMAIN) | `muscovite::dba::Decimal` | `muscovite.common.Decimal` | `QLineEdit` | `double` |
| **Spatial (PostGIS)** | | | | | |
| Point | `GEOGRAPHY(POINT, 4326)` | `std::string` (WKT) | `muscovite.common.Point` | `QLineEdit` | `string` |
| LineString | `GEOGRAPHY(LINESTRING, 4326)` | `std::string` (WKT) | `muscovite.common.LineString` | `QLineEdit` | `string` |
| Polygon | `GEOGRAPHY(POLYGON, 4326)` | `std::string` (WKT) | `muscovite.common.Polygon` | `QLineEdit` | `string` |
| Geography | `GEOGRAPHY` | `std::string` (WKT) | `string` | `QLineEdit` | `string` |
| **Special** | | | | | |
| JSON, JSONB | `JSONB` | `nlohmann::json` | `google.protobuf.Struct` | `QTextEdit` | `var` |

## Database Conventions (Mandatory)

| Rule | Detail |
|------|--------|
| All PKs named `id` | Type `UUID`, default `gen_random_uuid()` |
| All strings as `TEXT` | Never use `VARCHAR` |
| All datetime as `TIMESTAMPTZ` | Never use `TIMESTAMP` without timezone |
| No JSONB for domain fields | Use structured types instead |
| Lookup tables over CHECK enums | Use `LOOKUP_TABLE` DSL construct |
| Deploy via Sqitch only | Never hand-write `ALTER TABLE` |
| No `_id` inference | Foreign keys require explicit `RELATIONSHIPS {}` block |

## Proto Accessor Patterns

| Pattern | Types | Read | Write |
|---------|-------|------|-------|
| Direct | String, Integer, Boolean | `req.field_name()` | `req.set_field_name(val)` |
| Value wrapper | UUID, Decimal, Email, Phone | `req.field_name().value()` | `req.mutable_field_name()->set_value(val)` |
| Temporal | DateTime, Timestamp | `req.field_name().seconds()` | `req.mutable_field_name()->set_seconds(val)` |
| Date fields | Date | `.year()`, `.month()`, `.day()` | Set individual fields via mutable |
| Spatial | Point, LineString, Polygon | `wkt_to_spatial(req.field_name())` | WKT string conversion |
