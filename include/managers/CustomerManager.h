/*
 * Phase: 5 - Other CRUD Managers
 *
 * Customer Manager Contract
 * =========================
 *
 * Internal Storage:
 * - Primary storage: Linked List owning Customer records (e.g. LinkedList<Customer>).
 *
 * Suggested public ADT:
 * - bool addCustomer(const Customer& customer)
 * - bool updateCustomer(int customerId, const Customer& updated)
 * - bool deleteCustomer(int customerId) // Deletion policy: set active = false (soft delete)
 * - Customer* searchCustomer(int customerId)
 * - void displayAll() const
 * - void displayActiveOnly() const
 * - int getCount() const
 *
 * Responsibilities:
 * - Validate customer fields (positive ID, non-empty name/address, valid phone) before insertion.
 * - Reject duplicate customer IDs.
 * - Preserve active/inactive state; active status controls whether new orders can be placed.
 * - Provide clean access for File Manager to save/load customer records.
 */
