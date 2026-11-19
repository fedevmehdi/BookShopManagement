/*
 * Phase: 3 - Entity Classes
 *
 * Employee Entity Contract
 * ========================
 *
 * Purpose:
 * - Represent one employee record.
 *
 * Private data:
 * - int employeeId
 * - std::string fullName
 * - std::string role
 * - std::string phone
 * - bool active
 *
 * Suggested public ADT:
 * - Employee()
 * - Employee(int employeeId, const std::string& fullName,
 *            const std::string& role, const std::string& phone,
 *            bool active)
 * - getEmployeeId(), getFullName(), getRole(), getPhone(), isActive()
 * - setEmployeeId(int), setFullName(...), setRole(...),
 *   setPhone(...), setActive(bool)
 * - bool isValid() const
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - Employee ID must be positive.
 * - Full name and role must not be empty.
 * - Phone must meet the team-approved validation format.
 * - isValid() must validate all required fields.
 * - Active status controls whether normal transaction workflows may use the employee.
 */
