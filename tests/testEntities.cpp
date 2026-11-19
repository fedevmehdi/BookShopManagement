/*
 * Phase: 3 - Entity Classes
 *
 * Independent tests for every entity:
 *
 * Book:
 * - Default/full construction and all getters/setters.
 * - Positive/invalid ID, price, stock, title, author, category, and supplier ID.
 * - hasStock(), reduceStock(), and increaseStock().
 * - CSV serialization and malformed CSV handling.
 *
 * Customer:
 * - Construction, getters/setters, validation, active status, and CSV conversion.
 *
 * Supplier:
 * - Construction, getters/setters, validation, active status, and CSV conversion.
 *
 * Employee:
 * - Construction, getters/setters, validation, active status, and CSV conversion.
 *
 * Order:
 * - Construction, validation, all status transitions, and CSV conversion.
 * - Verify the entity itself never mutates stock or Queue state.
 *
 * Transaction:
 * - Sale and restock construction.
 * - Required and optional IDs.
 * - Total calculation and precision handling.
 * - CSV conversion and malformed row handling.
 *
 * Test convention:
 * - This test file must compile independently of manager, menu, and persistence code.
 * - Use clear pass/fail output or assertions.
 */
