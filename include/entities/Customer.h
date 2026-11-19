/*
 * Phase: 3 - Entity Classes
 *
 * Customer Entity Contract
 * ========================
 *
 * Purpose:
 * - Represent one customer record.
 *
 * Private data:
 * - int customerId
 * - std::string fullName
 * - std::string phone
 * - std::string address
 * - bool active
 *
 * Suggested public ADT:
 * - Customer()
 * - Customer(int customerId, const std::string& fullName,
 *            const std::string& phone, const std::string& address,
 *            bool active)
 * - getCustomerId(), getFullName(), getPhone(), getAddress(), isActive()
 * - setCustomerId(int), setFullName(...), setPhone(...),
 *   setAddress(...), setActive(bool)
 * - bool isValid() const
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - Customer ID must be positive.
 * - Full name and address must not be empty.
 * - Phone must meet the team-approved validation format.
 * - isValid() must validate all required fields.
 * - Active status controls whether normal CRUD workflows may use the customer.
 *
 * Persistence boundary:
 * - This class performs field conversion and validation only.
 * - File I/O is owned by the File Manager in Phase 7.
 */
