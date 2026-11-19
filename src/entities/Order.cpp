/*
 * Phase: 3 - Entity Classes
 *
 * Implement the Order ADT from include/entities/Order.h.
 *
 * Implementation order:
 * 1. Define fields and constructor/status representation.
 * 2. Implement getters/setters.
 * 3. Implement isValid().
 * 4. Implement explicit Pending/Completed/Cancelled transitions.
 * 5. Implement isPending() and canBeFulfilled().
 * 6. Implement display() and CSV conversion.
 *
 * Required invariant:
 * - This class does not change stock or directly mutate the pending Queue.
 *
 * Independent tests:
 * - Default and full construction.
 * - Invalid IDs, quantity, date, and status.
 * - Every allowed status transition.
 * - Rejected transitions from Completed or Cancelled.
 * - CSV row conversion and malformed row handling.
 */
