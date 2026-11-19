/*
 * Phase: 5 - Other CRUD Managers
 *
 * Implement Customer CRUD and validation here.
 *
 * Implementation order:
 * 1. Initialize internal LinkedList of Customer records.
 * 2. Implement addCustomer: check for duplicate customerId before inserting into list.
 * 3. Implement searchCustomer: linear traversal over customer list matching ID.
 * 4. Implement updateCustomer: locate record and update fields while keeping ID intact.
 * 5. Implement deleteCustomer: locate customer and set active = false (soft delete) to preserve order history.
 * 6. Implement displayAll() and displayActiveOnly().
 */
