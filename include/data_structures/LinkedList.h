/*
 * Phase: 2 - Data Structures
 *
 * Linked List ADT
 * ===============
 *
 * Purpose:
 * - Primary owner of Book records.
 *
 * Implementation:
 * - Singly linked list.
 *
 * State:
 * - BookNode: stores a Book and a pointer to the next node.
 * - head: pointer to the first node; nullptr when the list is empty.
 * - size: number of nodes currently in the list.
 *
 * Operations:
 * - insertAtBeginning(Book): insert a node at the head.
 * - insertAtEnd(Book): insert a node after the last node.
 * - deleteNode(id): remove the first node matching id; return success/failure.
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
 * - Book objects stored in the list should remain owned by this primary collection.
 *
 * STL restriction:
 * - Do not use std::list, std::vector, or another STL container for the nodes.
 */

#pragma once

#include <iostream>
#include "../entities/Book.h"

using namespace std;

class BookNode {
public:
    Book book;
    BookNode* next;

    BookNode(const Book& value): book(value), next(nullptr) {}
};

class LinkedList {
public:
    int size;
    BookNode* head;
    BookNode* tail;

    LinkedList(): head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void insertAtBeginning(const Book& book) {
        BookNode* newNode = new BookNode(book);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        size++;
    }

    void insertAtEnd(const Book& book) {
        BookNode* newNode = new BookNode(book);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    bool deleteNode(int bookId) {
        BookNode* previous = nullptr;
        BookNode* current = head;

        while (current != nullptr) {
            if (current->book.getBookId() == bookId) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }

                if (current == tail) {
                    tail = previous;
                }

                delete current;
                size--;
                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    Book* search(int bookId) {
        BookNode* current = head;

        while (current != nullptr) {
            if (current->book.getBookId() == bookId) {
                return &current->book;
            }
            current = current->next;
        }

        return nullptr;
    }

    void display() const {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        BookNode* current = head;
        while (current != nullptr) {
            current->book.display();
            cout << endl;
            current = current->next;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getSize() {
        return size;
    }

    void clear() {
        while (head != nullptr) {
            BookNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }

        tail = nullptr;
        size = 0;
    }
};