/*
 * Phase: 2 - Data Structures
 *
 * Linked List ADT
 * ===============
 *
 * Purpose:
 * - Primary owner of Book records.
 * - May also be used for standalone integer data-structure tests.
 *
 * Implementation:
 * - Singly linked list.
 *
 * State:
 * - Node: stores data and a pointer to the next node.
 * - head: pointer to the first node; nullptr when the list is empty.
 * - size: number of nodes currently in the list.
 *
 * Operations:
 * - insertAtBeginning(data): insert a node at the head.
 * - insertAtEnd(data): insert a node after the last node.
 * - deleteNode(id): remove the first node matching id; return success/failure.
 *   (For integer tests: match data == id. For Book/entity records: match record ID == id).
 * - search(id): return a pointer to the matching element, or nullptr if not found.
 * - display(): display the elements from head to tail.
 * - isEmpty(): return true when the list contains no nodes.
 * - getSize(): return the number of nodes.
 *
 * Required behaviour:
 * - Insertion into an empty list must set head.
 * - End insertion must place the node after the final node.
 * - Deleting the head must advance head.
 * - Deleting a missing key must leave the list unchanged.
 * - Searching for a missing key must return nullptr.
 * - Display must clearly handle an empty list.
 * - The destructor must release every allocated node.
 *
 * Ownership:
 * - The Linked List owns dynamically allocated nodes.
 * - Book objects stored as data should remain owned by this primary collection.
 *
 * STL restriction:
 * - Do not use std::list, std::vector, or another STL container for the nodes.
 */