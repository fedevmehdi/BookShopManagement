/*
 * Phase: 3 - Entity Classes
 *
 * Order Entity Contract
 * =====================
 *
 * Purpose:
 * - Represent one customer order.
 *
 * Private data:
 * - int orderId
 * - int customerId
 * - int bookId
 * - int quantity
 * - std::string date
 * - enum or std::string status
 *
 * Suggested public ADT:
 * - Order()
 * - Order(int orderId, int customerId, int bookId, int quantity,
 *         const std::string& date, const std::string& status)
 * - getOrderId(), getCustomerId(), getBookId(), getQuantity(),
 *   getDate(), getStatus()
 * - setOrderId(int), setCustomerId(int), setBookId(int), setQuantity(int),
 *   setDate(...), setStatus(...)
 * - bool isValid() const
 * - bool canBeFulfilled() const
 * - bool markPending(), markCompleted(), markCancelled()
 * - bool isPending() const
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - Order ID, customer ID, and book ID must be positive.
 * - Quantity must be positive.
 * - Date must use the agreed project date format.
 * - Status must be one of the agreed values: Pending, Completed, or Cancelled.
 * - Valid status transitions must be explicit:
 *   Pending -> Completed or Cancelled; Completed/Cancelled -> no normal change.
 * - canBeFulfilled() must be decided in combination with current stock.
 * - The Order class must not modify stock or the pending Queue directly.
 */
