/*
 * Phase: 7 - Persistence and Integration
 *
 * File Manager Contract
 * =====================
 * Responsibilities:
 * - Load and save entities and pending order IDs using approved text/CSV format.
 * - Rebuild BST and Hash Table indexes after books are loaded.
 * - Restore Queue order consistently (oldest order enqueued first).
 * - Handle missing, unreadable, or malformed files without silent failure.
 * - Report whether each load/save operation succeeded.
 *
 * Confirmed File & Data Format Decisions:
 * - Delimiter: Standard comma (','). Text inputs must disallow or sanitize literal commas.
 * - Date format: YYYY-MM-DD (e.g. 2026-12-07).
 * - Optional IDs: 0 denotes not applicable (e.g. customerId = 0 in restock transaction).
 * - Save timing: Save on every state-mutating operation (CRUD, sale, restock) and upon clean exit.
 *
 * Exact CSV Column Schemas:
 * - data/books.csv:
 *   bookId,title,author,category,price,stockQuantity,supplierId,active
 * - data/customers.csv:
 *   customerId,fullName,phone,address,active
 * - data/suppliers.csv:
 *   supplierId,name,phone,address,active
 * - data/employees.csv:
 *   employeeId,fullName,role,phone,active
 * - data/orders.csv:
 *   orderId,customerId,bookId,quantity,date,status
 * - data/transactions.csv:
 *   transactionId,transactionType,date,bookId,customerId,supplierId,employeeId,quantity,unitPrice,totalAmount,orderId
 * - data/pending_queue.csv:
 *   orderId (one per row, preserving FIFO enqueue order)
 *
 * Startup Rebuild Sequence:
 * 1. Load books into primary Linked List; for each node, insert its pointer into BST and HashTable.
 * 2. Load customers, suppliers, and employees into their respective Manager lists.
 * 3. Load orders into OrderManager.
 * 4. Load transactions and push onto Stack (file stored chronologically so top of Stack is newest).
 * 5. Load pending order IDs and enqueue into pending Queue in original order.
 */
