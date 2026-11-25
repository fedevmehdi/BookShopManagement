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
#pragma once
#include <iostream>
#include "../data_structures/LinkedList.h"
#include "../data_structures/BST.h"
using namespace std;

class BookManager {
private:
    LinkedList books;
    BST<Book> bst;
public:
    BookManager(){};
    void add(Book book) {
        if(book.isValid() && bst.search(book.getBookId()) == nullptr) {
            books.insertAtEnd(book);
            Book* storedBook = books.search(book.getBookId());
            bst.insert(book.getBookId(), storedBook);
            return;
        } else {
            cout << "Failed to validate book format" << endl;
        }
    }
    Book* searchByID(int id) {
        auto node = bst.search(id);
        if(node==nullptr) {
            return nullptr;
        }
        return node->book;
    }
    bool update(int id, Book updated) {
        Book* existing = books.search(id);
        if (existing == nullptr || !updated.isValid()) {
            return false;
        }
        if(updated.getBookId() != id) {
            return false;
        }

        *existing = updated;
        return true;
    }

    void remove(int id) {
        if(bst.search(id) != nullptr) {
            bst.deleteNode(id);
            books.deleteNode(id);
        } else {
            cout << "ID does not exists!" << endl;
        }
    }
    void display() const {
        books.display();
    }
};