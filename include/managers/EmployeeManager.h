/*
 * Phase: 5 - Other CRUD Managers
 *
 * Employee Manager Contract
 * =========================
 *
 * Internal Storage:
 * - Primary storage: Linked List owning Employee records (e.g. LinkedList<Employee>).
 *
 * Suggested public ADT:
 * - bool addEmployee(const Employee& employee)
 * - bool updateEmployee(int employeeId, const Employee& updated)
 * - bool deleteEmployee(int employeeId) // Deletion policy: set active = false (soft delete)
 * - Employee* searchEmployee(int employeeId)
 * - void displayAll() const
 * - void displayActiveOnly() const
 * - int getCount() const
 *
 * Responsibilities:
 * - Validate employee fields (positive ID, non-empty fullName/role, valid phone) before insertion.
 * - Reject duplicate employee IDs.
 * - Preserve active/inactive state; active status controls whether an employee can handle transactions.
 * - Provide clean access for File Manager to save/load employee records.
 */
