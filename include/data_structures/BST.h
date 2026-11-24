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
 * - Height convention: We are using nodes to count height.
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

#pragma once
#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    int id;
    T* book;
    Node<T>* left;
    Node<T>* right;

    Node(int id, T* book)
        : id(id), book(book), left(nullptr), right(nullptr) {};
};

template <class T>
class BST {
public:
    Node<T>* root;

    BST() : root(nullptr) {}

    Node<T>* insert(int id, T* book) {
        root = insert(root, id, book);
        return root;
    }

    Node<T>* insert(Node<T>* current, int id, T* book) {
        if (current == nullptr) {
            return new Node<T>(id, book);
        }

        // If there is a matching id, do nothing
        if (current->id == id) {
            return current;
        }

        // If ID is less than the root, insert it in the left subtree
        if (id < current->id) {
            current->left = insert(current->left, id, book);
        }
        else {
            current->right = insert(current->right, id, book);
        }

        return current;
    }

    Node<T>* search(int key) {
        Node<T>* current = root;

        while (current != nullptr) {
            if (current->id == key) {
                return current;
            }

            if (key < current->id) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        return nullptr;
    }

    void inorderTraverse(Node<T>* root) {
        if (root != nullptr) {
            inorderTraverse(root->left);
            cout << root->id << " ";
            inorderTraverse(root->right);
        }
    }

    Node<T>* inorderSuccessor(Node<T>* root) {
        while (root != nullptr && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    bool deleteNode(int key) {
        root = deleteNode(root, key);
        if(root == nullptr) return false;
        else return true;
    }

    Node<T>* deleteNode(Node<T>* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        // If the data is in left subtree
        if (key < root->id) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->id) {
            root->right = deleteNode(root->right, key);
        }

        // Incase the root data is same as the key
        else {
            // Case with only one child or leaf
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            // Case with two children
            Node<T>* temp = inorderSuccessor(root->right);
            root->id = temp->id;
            root->book = temp->book;
            root->right = deleteNode(root->right, temp->id);
        }

        return root;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    int height(Node<T>* current) {
        if (current == nullptr) {
            return 0;
        }

        int left = height(current->left);
        int right = height(current->right);

        return 1 + max(left, right);
    }

    Node<T>* getRoot() {
        return root;
    }

    void clear(Node<T>* current) {
        if (current != nullptr) {
            clear(current->left);
            clear(current->right);
            delete current;
        }
    }

    ~BST() {
        clear(root);
        root = nullptr;
    }
};