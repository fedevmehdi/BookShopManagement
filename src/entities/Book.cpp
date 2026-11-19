/*
 * Phase: 3 - Entity Classes
 *
 * Implement the methods declared for the Book class in include/entities/Book.h.
 *
 * Implementation order:
 * 1. Define private fields and include the needed standard headers.
 * 2. Implement the default constructor and full constructor.
 * 3. Implement getters and setters.
 * 4. Implement isValid(), hasStock(), reduceStock(), and increaseStock().
 * 5. Implement display().
 * 6. Implement toCsvRow() and fromCsvRow() using the approved CSV format.
 *
 * Required invariants:
 * - ID and supplier ID remain positive.
 * - Price is never negative.
 * - Stock quantity is never negative.
 * - Setters reject invalid input consistently.
 *
 * Independent tests:
 * - Default construction.
 * - Valid and invalid full construction.
 * - Stock check, reduction, and increase.
 * - Attempted negative or excessive stock change.
 * - Empty title/author/category.
 * - CSV row conversion.
 */
