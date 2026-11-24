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

#include "entities/Customer.h"
#include "entities/Employee.h"

int main() {
    const string row = "42,Amina,555-0100,1 Main St,1";
    Customer customer(42, "Amina", "555-0100", "1 Main St", true);
    if (customer.toCsvRow() != row) {
        return 1;
    }

    Customer loaded;
    if (!loaded.fromCsvRow(row) || loaded.toCsvRow() != row) {
        return 2;
    }

    if (loaded.fromCsvRow("42,Amina,555-0100,,1") || loaded.toCsvRow() != row) {
        return 3;
    }

    const string employeeRow = "19,Ada Lovelace,Manager,555-0101,1";
    Employee employee(19, "Ada Lovelace", "Manager", "555-0101", true);
    if (!employee.isValid() || employee.toCsvRow() != employeeRow) {
        return 4;
    }

    Employee loadedEmployee;
    if (!loadedEmployee.fromCsvRow(employeeRow) ||
        loadedEmployee.toCsvRow() != employeeRow) {
        return 5;
    }

    if (loadedEmployee.fromCsvRow("19,Ada Lovelace,,555-0101,1") ||
        loadedEmployee.toCsvRow() != employeeRow) {
        return 6;
    }

    return 0;
}
