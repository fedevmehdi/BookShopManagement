/*
 * Phase: 3 - Entity Classes
 *
 * Implement the Transaction ADT from include/entities/Transaction.h.
 *
 * Implementation order:
 * 1. Define fields and constructors.
 * 2. Implement read-only getters.
 * 3. Implement isValid().
 * 4. Implement calculateAndVerifyTotal().
 * 5. Implement display().
 * 6. Implement CSV conversion.
 *
 * Required invariant:
 * - Sale/restock history records remain separate from mutable book/order state.
 *
 * Independent tests:
 * - Default and full construction.
 * - Sale record with customer/employee/order IDs.
 * - Restock record with supplier ID.
 * - Invalid quantity, price, ID, type, or date.
 * - Incorrect and correctly calculated totals.
 * - Optional-ID handling.
 * - CSV row conversion and malformed row handling.
 */
