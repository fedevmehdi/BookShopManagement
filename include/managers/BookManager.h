/*
 * Phase: 4 - Book Management
 *
 * Book Manager Contract
 * Responsibilities:
 * - Add, update, delete, search, and display books.
 * - Keep the primary Linked List and secondary BST/Hash Table consistent.
 * - Validate stock and references before changing records.
 * - Produce sorted temporary Book-pointer arrays for display.
 *
 * Required behavior:
 * - Add: insert once into list and both indexes.
 * - Update: preserve index IDs and keep indexes synchronized.
 * - Delete: remove from indexes and release the owned Book record safely.
 * - Search: support ID lookup and ID/title/other agreed keys.
 */
