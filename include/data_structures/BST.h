/*
 * Phase: 2 - Data Structures
 *
 * Binary Search Tree (BST) ADT
 * =============================
 *
 * Purpose:
 * - Secondary index for unique Book IDs.
 * - Supports lookup and ascending ID traversal.
 *
 * Implementation:
 * - Standard unbalanced BST.
 *
 * State:
 * - BSTNode: stores key (int id), non-owning value pointer (Book* or generic value),
 *   left child pointer, and right child pointer.
 * - root: pointer to the root node; nullptr for an empty tree.
 *
 * Operations:
 * - insert(key, value): insert a key and non-owning value pointer; reject duplicate IDs.
 * - search(key): return the matching value pointer, or nullptr if not found.
 * - deleteNode(key): remove a matching node and report success/failure.
 * - inorderTraversal(): visit IDs in ascending order.
 * - isEmpty(): return true when root is nullptr.
 * - getHeight(): return tree height.
 * - getRoot(): optionally expose the root for traversals or tests.
 *
 * Required behaviour:
 * - IDs smaller than the current node go left.
 * - IDs larger than the current node go right.
 * - Duplicate IDs are rejected.
 * - Empty search and deletion must be safe.
 * - Deletion must handle a leaf, one child, and two children (replace with inorder successor: smallest in right subtree).
 * - In-order traversal must display ascending IDs.
 * - Height convention: empty tree = -1; leaf = 0.
 *
 * Ownership:
 * - The BST owns its nodes, not the Book records they reference.
 * - Its destructor must release nodes but must not delete Book objects.
 *
 * Restrictions:
 * - This is not an AVL tree.
 * - Do not implement rotations or balancing unless the project requirement changes.
 * - Do not use std::map or other prohibited STL containers.
 */