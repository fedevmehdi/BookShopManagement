/*
 * Phase: 2 - Data Structures
 *
 * Hash Table ADT
 * ==============
 *
 * Purpose:
 * - Secondary index for fast Book ID lookup.
 *
 * Implementation:
 * - Array of buckets using separate chaining.
 * - Collision chains must be manually implemented.
 *
 * State:
 * - HashNode: stores key (int id), non-owning value pointer (Book* or generic value),
 *   and next pointer for separate chaining.
 * - buckets: dynamically allocated array of HashNode* (size = capacity), initialized to nullptr.
 * - capacity: fixed prime number (recommended: 11) to minimize collisions without dynamic rehashing.
 * - size: number of stored entries.
 *
 * Operations:
 * - hashFunction(key): calculate a valid bucket index using: abs(key) % capacity.
 * - insert(key, value): insert a unique key and non-owning value pointer; reject duplicate IDs.
 * - search(key): return the matching value pointer, or nullptr if not found.
 * - remove(key): remove one matching entry from its collision chain and report success/failure.
 * - display(): display each bucket index and its collision chain.
 * - isEmpty(): return true when size == 0.
 *
 * Required behaviour:
 * - Collisions must remain in separate chains at the same bucket.
 * - Removing a key must not remove unrelated chain entries.
 * - Empty buckets and missing keys must be handled safely.
 * - Duplicate IDs must be rejected.
 *
 * Confirmed design decisions:
 * - Initial capacity: 11 (fixed prime).
 * - Exact hash formula: abs(key) % 11.
 * - Resizing: Fixed capacity; no dynamic rehashing required for project scope.
 *
 * Ownership:
 * - The table owns chain nodes, but not the Book records they reference.
 * - Removing or destroying table entries must not delete owned Book objects.
 *
 * STL restriction:
 * - Do not use std::unordered_map or std::vector for buckets or chains.
 */