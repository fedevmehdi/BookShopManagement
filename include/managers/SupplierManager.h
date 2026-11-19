/*
 * Phase: 5 - Other CRUD Managers
 *
 * Supplier Manager Contract
 * =========================
 *
 * Internal Storage:
 * - Primary storage: Linked List owning Supplier records (e.g. LinkedList<Supplier>).
 *
 * Suggested public ADT:
 * - bool addSupplier(const Supplier& supplier)
 * - bool updateSupplier(int supplierId, const Supplier& updated)
 * - bool deleteSupplier(int supplierId) // Deletion policy: set active = false (soft delete)
 * - Supplier* searchSupplier(int supplierId)
 * - void displayAll() const
 * - void displayActiveOnly() const
 * - int getCount() const
 *
 * Responsibilities:
 * - Validate supplier fields (positive ID, non-empty name/address, valid phone) before insertion.
 * - Reject duplicate supplier IDs.
 * - Preserve active/inactive state; active status controls whether restocking can use this supplier.
 * - Provide clean access for File Manager to save/load supplier records.
 */
