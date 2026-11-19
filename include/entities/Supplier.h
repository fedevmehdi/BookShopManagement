/*
 * Phase: 3 - Entity Classes
 *
 * Supplier Entity Contract
 * ========================
 *
 * Purpose:
 * - Represent one supplier record.
 *
 * Private data:
 * - int supplierId
 * - std::string name
 * - std::string phone
 * - std::string address
 * - bool active
 *
 * Suggested public ADT:
 * - Supplier()
 * - Supplier(int supplierId, const std::string& name,
 *            const std::string& phone, const std::string& address,
 *            bool active)
 * - getSupplierId(), getName(), getPhone(), getAddress(), isActive()
 * - setSupplierId(int), setName(...), setPhone(...),
 *   setAddress(...), setActive(bool)
 * - bool isValid() const
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - Supplier ID must be positive.
 * - Name and address must not be empty.
 * - Phone must meet the team-approved validation format.
 * - isValid() must validate all required fields.
 * - Active status controls whether normal restocking workflows may use the supplier.
 */
