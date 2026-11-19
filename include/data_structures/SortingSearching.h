/*
 * Phase: 2 - Data Structures
 *
 * Sorting and Searching Utility ADT
 * =================================
 *
 * Purpose:
 * - Provide manually implemented sorting and searching algorithms.
 *
 * Scope:
 * - Sort temporary arrays of Book pointers.
 * - Never alter the primary Linked List order merely for display.
 *
 * Selection Sort operations:
 * - selectionSortById(array, size): sort ascending by Book ID (prerequisite for binarySearch).
 * - selectionSortByTitle(array, size): sort ascending by title.
 * - selectionSortByPrice(array, size): sort ascending by price.
 *
 * Selection Sort requirements:
 * - Manual implementation.
 * - Handle empty and one-element arrays.
 * - Handle already sorted and reverse-ordered arrays.
 * - Swap equal values only as required; define tie behaviour consistently.
 *
 * Searching operations:
 * - linearSearch(collectionOrArray, key): sequential search.
 * - binarySearch(sortedArray, size, key): search sorted data.
 *
 * Searching requirements:
 * - Linear Search works on sorted or unsorted data.
 * - Binary Search requires data sorted by the same key.
 * - Binary Search may use a temporary array sorted by Book ID.
 * - Missing array indices should return -1.
 * - Pointer-based searches should return nullptr when no match exists.
 *
 * Restrictions:
 * - Do not perform Binary Search directly on a Linked List.
 * - Do not use std::sort or other STL sorting/algorithm substitutes.
 */