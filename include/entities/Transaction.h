/*
 * Phase: 3 - Entity Classes
 *
 * Transaction Entity Contract
 * ===========================
 *
 * Purpose:
 * - Represent an immutable-style history record in the Transaction Stack.
 *
 * Private data:
 * - int transactionId
 * - std::string transactionType
 * - std::string date
 * - int bookId
 * - int customerId (0 means not applicable)
 * - int supplierId (0 means not applicable)
 * - int employeeId (0 means not applicable)
 * - int quantity
 * - double unitPrice
 * - double totalAmount
 * - int orderId (0 means not applicable)
 *
 * Suggested public ADT:
 * - Transaction()
 * - Transaction(int transactionId, const std::string& transactionType,
 *               const std::string& date, int bookId, int customerId,
 *               int supplierId, int employeeId, int quantity,
 *               double unitPrice, double totalAmount, int orderId)
 * - getTransactionId(), getTransactionType(), getDate(), getBookId(),
 *   getCustomerId(), getSupplierId(), getEmployeeId(), getQuantity(),
 *   getUnitPrice(), getTotalAmount(), getOrderId()
 * - set input methods may exist only if the project allows editing; history
 *   records should otherwise be created with a constructor and read through getters.
 * - bool isValid() const
 * - bool calculateAndVerifyTotal()
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - Transaction ID and book ID must be positive.
 * - Type must be one of the approved values, such as Sale or Restock.
 * - Date must use the agreed project date format.
 * - Quantity must be positive.
 * - Unit price must be greater than or equal to zero.
 * - Total must equal quantity * unitPrice within an agreed precision tolerance.
 * - Sale records should identify a customer and may identify an employee/order.
 * - Restock records should identify a supplier and must not require a customer.
 * - Optional IDs use 0 to mean not applicable.
 *
 * Ownership and history:
 * - The Stack owns Transaction nodes; records may be objects or pointers.
 * - Transaction objects do not modify books, stock, orders, or persistence files.
 */
