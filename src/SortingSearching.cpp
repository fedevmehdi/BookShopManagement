/*
 * Phase: 2 - Data Structures
 *
 * Sorting and Searching implementation
 * =====================================
 *
 * Implement the declarations/prototypes agreed in SortingSearching.h.
 *
 * Planned code:
 * - selectionSortById:
 *   1. Traverse each array position.
 *   2. Find the smallest Book ID from the remaining unsorted positions.
 *   3. Swap the selected Book pointer into the current position.
 *
 * - selectionSortByTitle:
 *   1. Traverse each array position.
 *   2. Find the smallest title from the remaining unsorted positions.
 *   3. Swap the selected Book pointer into the current position.
 *
 * - selectionSortByPrice:
 *   1. Traverse each array position.
 *   2. Find the smallest price from the remaining unsorted positions.
 *   3. Swap the selected Book pointer into the current position.
 *
 * - linearSearch:
 *   1. Inspect elements in order.
 *   2. Return the matching index/pointer.
 *   3. Return -1 or nullptr when absent.
 *
 * - binarySearch:
 *   1. Require the input array to be sorted by the requested key.
 *   2. Repeatedly divide the remaining search range.
 *   3. Return the matching index or -1.
 *
 * Testing:
 * - Empty and one-element arrays.
 * - Sorted and reverse-ordered arrays.
 * - Equal values and missing keys.
 * - Binary Search only on correctly sorted arrays.
 *
 * Restrictions:
 * - Implement sorting and searching manually.
 * - Do not alter the primary Linked List order.
 * - Do not use std::sort or prohibited container algorithms.
 */
