/*
 * Phase: 3 - Entity Classes
 *
 * Book Entity Contract
 * ===================
 *
 * Purpose:
 * - Represent one book record owned by the primary Linked List.
 *
 * Private data:
 * - int bookId
 * - std::string title
 * - std::string author
 * - std::string category
 * - double price
 * - int stockQuantity
 * - int supplierId
 * - bool active
 *
 * Suggested public ADT:
 * - Book(): create an inactive, validation-friendly default record.
 * - Book(int bookId, const std::string& title, const std::string& author,
 *        const std::string& category, double price, int stockQuantity,
 *        int supplierId, bool active)
 * - getBookId(), getTitle(), getAuthor(), getCategory(), getPrice(),
 *   getStockQuantity(), getSupplierId(), isActive()
 * - setBookId(int), setTitle(const std::string&), setAuthor(...),
 *   setCategory(...), setPrice(double), setStockQuantity(int),
 *   setSupplierId(int), setActive(bool)
 * - bool isValid() const
 * - bool hasStock(int quantity) const
 * - bool reduceStock(int quantity)
 * - bool increaseStock(int quantity)
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - ID and supplier ID must be positive.
 * - Title, author, and category must not be empty.
 * - Price must be greater than or equal to zero.
 * - Stock quantity must be greater than or equal to zero.
 * - Setters should reject invalid values or expose clear status; use one
 *   consistent convention throughout the project.
 * - reduceStock() succeeds only when quantity is positive and enough stock exists.
 * - increaseStock() succeeds only for a positive quantity.
 * - toCsvRow()/fromCsvRow() format: bookId,title,author,category,price,stockQuantity,supplierId,active (using comma delimiter without spaces).
 *
 * Relationships and ownership:
 * - A Book object is stored and owned by the Linked List.
 * - The BST and Hash Table store non-owning pointers/references to this object.
 * - This class must not own or destroy BST, Hash Table, or Linked List structures.
 */
