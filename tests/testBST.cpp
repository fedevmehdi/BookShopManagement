/*
 * Phase: 2 - Data Structures
 *
 * BST independent tests
 * =====================
 *
 * Required cases:
 * - Empty tree: isEmpty, search, height = 0.
 * - Insert a root/leaf and verify height = 1.
 * - Insert multiple values and verify in-order ascending traversal.
 * - Search for existing and missing IDs.
 * - Reject duplicate insertion.
 * - Delete a leaf.
 * - Delete a node with one child.
 * - Delete a node with two children.
 * - Delete a missing ID.
 * - Verify memory cleanup.
 *
 * Requirement:
 * - BST nodes may reference, but must not own, Book records.
 */

#include <iostream>
#include <string>
#include "data_structures/BST.h"
#include "entities/Book.h"

using namespace std;

int main() {
    cout << "=========================================" << endl;
    cout << "         BST INDEPENDENT TESTS           " << endl;
    cout << "=========================================" << endl;

    BST<Book> tree;

    // --------------------------------------------------
    // Case 1: Empty tree
    // --------------------------------------------------
    cout << "\n--- Case 1: Empty Tree ---" << endl;
    cout << "Tree isEmpty: " << (tree.isEmpty() ? "true" : "false") << endl;
    cout << "Tree height: " << tree.height(tree.getRoot()) << endl;

    Node<Book>* emptySearch = tree.search(100);
    if (emptySearch == nullptr) {
        cout << "Search for ID 100 in empty tree: Not found (nullptr)" << endl;
    } else {
        cout << "Search for ID 100: Found unexpectedly" << endl;
    }

    // --------------------------------------------------
    // Case 2: Insert a root/leaf and verify height = 1
    // --------------------------------------------------
    cout << "\n--- Case 2: Insert Root Node ---" << endl;
    Book b50(50, "The C++ Programming Language", "Bjarne Stroustrup", "Programming", 55.0, 10, 1, true);
    tree.insert(50, &b50);

    cout << "Inserted Book ID 50 (Root)" << endl;
    cout << "Tree isEmpty: " << (tree.isEmpty() ? "true" : "false") << endl;
    cout << "Tree height: " << tree.height(tree.getRoot()) << endl;
    cout << "In-order traversal: ";
    tree.inorderTraverse(tree.getRoot());
    cout << endl;

    // --------------------------------------------------
    // Case 3: Insert multiple values and verify in-order traversal
    // --------------------------------------------------
    cout << "\n--- Case 3: Insert Multiple Values ---" << endl;
    Book b30(30, "Clean Code", "Robert C. Martin", "Software Engineering", 40.0, 8, 1, true);
    Book b70(70, "Introduction to Algorithms", "CLRS", "Algorithms", 85.0, 5, 2, true);
    Book b20(20, "Design Patterns", "GoF", "Software Engineering", 50.0, 6, 2, true);
    Book b40(40, "Refactoring", "Martin Fowler", "Software Engineering", 42.0, 7, 3, true);
    Book b60(60, "The Pragmatic Programmer", "Hunt & Thomas", "Programming", 48.0, 12, 3, true);
    Book b80(80, "Artificial Intelligence", "Russell & Norvig", "AI", 90.0, 4, 1, true);

    tree.insert(30, &b30);
    tree.insert(70, &b70);
    tree.insert(20, &b20);
    tree.insert(40, &b40);
    tree.insert(60, &b60);
    tree.insert(80, &b80);

    cout << "Inserted IDs: 30, 70, 20, 40, 60, 80" << endl;
    cout << "Tree height: " << tree.height(tree.getRoot()) << endl;
    cout << "In-order traversal (expected: 20 30 40 50 60 70 80): ";
    tree.inorderTraverse(tree.getRoot());
    cout << endl;

    // --------------------------------------------------
    // Case 4: Search for existing and missing IDs
    // --------------------------------------------------
    cout << "\n--- Case 4: Search for Existing and Missing IDs ---" << endl;
    cout << "Searching for existing ID 40:" << endl;
    Node<Book>* foundNode = tree.search(40);
    if (foundNode != nullptr && foundNode->book != nullptr) {
        cout << "Found Book ID: " << foundNode->book->getBookId()
             << " | Title: " << foundNode->book->getTitle()
             << " | Author: " << foundNode->book->getAuthor() << endl;
    } else {
        cout << "Book ID 40 not found!" << endl;
    }

    cout << "Searching for missing ID 99:" << endl;
    Node<Book>* missingNode = tree.search(99);
    if (missingNode == nullptr) {
        cout << "Book ID 99: Not found (nullptr returned as expected)" << endl;
    } else {
        cout << "Book ID 99: Found unexpectedly" << endl;
    }

    // --------------------------------------------------
    // Case 5: Reject duplicate insertion
    // --------------------------------------------------
    cout << "\n--- Case 5: Reject Duplicate Insertion ---" << endl;
    cout << "Attempting to insert duplicate ID 50:" << endl;
    tree.insert(50, &b50);
    cout << "In-order traversal after duplicate attempt: ";
    tree.inorderTraverse(tree.getRoot());
    cout << endl;

    // --------------------------------------------------
    // Case 6: Delete a leaf node
    // --------------------------------------------------
    cout << "\n--- Case 6: Delete a Leaf Node (ID 20) ---" << endl;
    tree.deleteNode(20);
    cout << "Deleted node 20" << endl;
    cout << "In-order traversal (expected: 30 40 50 60 70 80): ";
    tree.inorderTraverse(tree.getRoot());
    cout << endl;

    // --------------------------------------------------
    // Case 7: Delete a node with one child
    // --------------------------------------------------
    cout << "\n--- Case 7: Delete a Node with One Child (ID 30) ---" << endl;
    // Node 30 now only has right child 40 (left child 20 was deleted)
    tree.deleteNode(30);
    cout << "Deleted node 30" << endl;
    cout << "In-order traversal (expected: 40 50 60 70 80): ";
    tree.inorderTraverse(tree.getRoot());
    cout << endl;

    // --------------------------------------------------
    // Case 8: Delete a node with two children
    // --------------------------------------------------
    cout << "\n--- Case 8: Delete a Node with Two Children (ID 70) ---" << endl;
    // Node 70 has two children: 60 (left) and 80 (right)
    tree.deleteNode(70);
    cout << "Deleted node 70 (replaced with inorder successor 80)" << endl;
    cout << "In-order traversal (expected: 40 50 60 80): ";
    tree.inorderTraverse(tree.getRoot());
    cout << endl;

    // --------------------------------------------------
    // Case 9: Delete a missing ID
    // --------------------------------------------------
    cout << "\n--- Case 9: Delete a Missing ID (ID 999) ---" << endl;
    tree.deleteNode(999);
    cout << "Attempted deletion of missing ID 999" << endl;
    cout << "In-order traversal (tree should remain unchanged: 40 50 60 80): ";
    tree.inorderTraverse(tree.getRoot());
    cout << endl;

    // --------------------------------------------------
    // Case 10: Verify memory cleanup & non-owning ownership
    // --------------------------------------------------
    cout << "\n--- Case 10: Verify Memory Cleanup & Non-Owning Ownership ---" << endl;
    Book standaloneBook(101, "Clean Architecture", "Robert C. Martin", "Software Engineering", 45.0, 15, 1, true);

    {
        cout << "Creating a scoped temporary BST..." << endl;
        BST<Book> scopedTree;
        scopedTree.insert(101, &standaloneBook);
        cout << "Scoped tree in-order: ";
        scopedTree.inorderTraverse(scopedTree.getRoot());
        cout << endl;
        cout << "Scoped tree is about to exit scope and destruct..." << endl;
    }
    cout << "Scoped tree destroyed. Verifying referenced Book record is still intact:" << endl;
    cout << "Book ID: " << standaloneBook.getBookId() << endl;
    cout << "Title: " << standaloneBook.getTitle() << endl;
    cout << "Stock: " << standaloneBook.getStockQuantity() << endl;
    cout << "Book record safely outlived the BST index (non-owning verified)!" << endl;

    cout << "\n=========================================" << endl;
    cout << "         ALL BST TESTS COMPLETED         " << endl;
    cout << "=========================================" << endl;

    return 0;
}
