/*
 * Phase: 5 - Other CRUD Managers
 *
 * Implement Supplier CRUD and validation here.
 *
 * Implementation order:
 * 1. Initialize internal LinkedList of Supplier records.
 * 2. Implement addSupplier: check for duplicate supplierId before inserting into list.
 * 3. Implement searchSupplier: linear traversal over supplier list matching ID.
 * 4. Implement updateSupplier: locate record and update fields while keeping ID intact.
 * 5. Implement deleteSupplier: locate supplier and set active = false (soft delete) to preserve restocking history.
 * 6. Implement displayAll() and displayActiveOnly().
 */
