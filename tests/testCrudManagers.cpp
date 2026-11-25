/*
 * Phase: 5 - Other CRUD Managers
 *
 * BookManager smoke test.
 * Customer, Supplier, and Employee manager tests can be added when those
 * managers are implemented.
 */

#include <iostream>
#include "managers/BookManager.h"

using namespace std;

int main() {
    BookManager manager;

    Book firstBook(10, "First Book", "Author One", "Fiction", 12.50, 5, 1, true);
    manager.add(firstBook);

    Book* found = manager.searchByID(10);
    if (found == nullptr || found->getTitle() != "First Book") {
        cerr << "FAIL: adding or searching for a book" << endl;
        return 1;
    }

    manager.add(Book(10, "Duplicate", "Author Two", "Fiction", 15.00, 3, 1, true));
    if (manager.searchByID(10) != found || found->getTitle() != "First Book") {
        cerr << "FAIL: duplicate book ID was added" << endl;
        return 1;
    }

    Book updatedBook(10, "Updated Book", "Author One", "Fiction", 14.00, 7, 1, true);
    if (!manager.update(10, updatedBook) ||
        manager.searchByID(10) != found ||
        found->getTitle() != "Updated Book") {
        cerr << "FAIL: updating a book" << endl;
        return 1;
    }

    Book wrongId(11, "Wrong ID", "Author One", "Fiction", 14.00, 7, 1, true);
    if (manager.update(10, wrongId) || found->getTitle() != "Updated Book") {
        cerr << "FAIL: update accepted a different book ID" << endl;
        return 1;
    }

    Book secondBook(20, "Second Book", "Author Two", "History", 20.00, 2, 1, true);
    manager.add(secondBook);

    manager.remove(10);
    if (manager.searchByID(10) != nullptr || manager.searchByID(20) == nullptr) {
        cerr << "FAIL: deleting a book or preserving another book" << endl;
        return 1;
    }

    if (manager.searchByID(999) != nullptr) {
        cerr << "FAIL: missing ID search should return nullptr" << endl;
        return 1;
    }

    cout << "BookManager smoke test passed." << endl;
    return 0;
}
