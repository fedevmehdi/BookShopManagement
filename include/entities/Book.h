/*
 * Phase: 3 - Entity Classes
 *
 * Book Entity Contract
 * ===================
 *
 * Purpose:
 * - Represent one book record owned by the primary Linked List.
 *
 * Private data:
 * - int bookId
 * - std::string title
 * - std::string author
 * - std::string category
 * - double price
 * - int stockQuantity
 * - int supplierId
 * - bool active
 *
 * Suggested public ADT:
 * - Book(): create an inactive, validation-friendly default record.
 * - Book(int bookId, const std::string& title, const std::string& author,
 *        const std::string& category, double price, int stockQuantity,
 *        int supplierId, bool active)
 * - getBookId(), getTitle(), getAuthor(), getCategory(), getPrice(),
 *   getStockQuantity(), getSupplierId(), isActive()
 * - setBookId(int), setTitle(const std::string&), setAuthor(...),
 *   setCategory(...), setPrice(double), setStockQuantity(int),
 *   setSupplierId(int), setActive(bool)
 * - bool isValid() const
 * - bool hasStock(int quantity) const
 * - bool reduceStock(int quantity)
 * - bool increaseStock(int quantity)
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - ID and supplier ID must be positive.
 * - Title, author, and category must not be empty.
 * - Price must be greater than or equal to zero.
 * - Stock quantity must be greater than or equal to zero.
 * - Setters should reject invalid values or expose clear status; use one
 *   consistent convention throughout the project.
 * - reduceStock() succeeds only when quantity is positive and enough stock exists.
 * - increaseStock() succeeds only for a positive quantity.
 * - toCsvRow()/fromCsvRow() format: bookId,title,author,category,price,stockQuantity,supplierId,active (using comma delimiter without spaces).
 *
 * Relationships and ownership:
 * - A Book object is stored and owned by the Linked List.
 * - The BST and Hash Table store non-owning pointers/references to this object.
 * - This class must not own or destroy BST, Hash Table, or Linked List structures.
 */
#pragma once
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    string category;
    double price;
    int stockQuantity;
    int supplierId;
    bool active;
public:
    Book()
    : bookId(-1), title(""), author(""), category(""),
    price(0), stockQuantity(0), supplierId(-1), active(false) {}

    Book(int bookId, string title, string author, string category,
    double price, int stockQuantity, int supplierId, bool active)
    : bookId(-1), title(""), author(""), category(""),
    price(0), stockQuantity(0), supplierId(-1), active(false)
    {
        setBookId(bookId);
        setTitle(title);
        setAuthor(author);
        setCategory(category);
        setPrice(price);
        setStockQuantity(stockQuantity);
        setSupplierId(supplierId);
        setActive(active);
    }

    // Getter functions
    int getBookId() const { return bookId; }
    string getTitle() const {return title; }
    string getAuthor() const {return author;}
    string getCategory() const {return category;}
    double getPrice() const {return price;}
    int getStockQuantity() const {return stockQuantity;}
    int getSupplierId() const {return supplierId;}
    bool isActive() const {return active;}

    // Setter functions
    bool setBookId(int id) {
        if(id <= 0) return false;
        this->bookId = id;
        return true;
    }
    bool setTitle(string title) {
        if(title.empty()) return false;
        this->title = title;
        return true;
    }
    bool setAuthor(string author) {
        if(author.empty()) return false;
        this->author = author;
        return true;
    }
    bool setCategory(string category) {
        if(category.empty()) return false;
        this->category = category;
        return true;
    }
    bool setPrice(double price) {
        if(price < 0) return false;
        this->price = price;
        return true;
    }
    bool setStockQuantity(int stockQuantity) {
        if(stockQuantity < 0) return false;
        this->stockQuantity = stockQuantity;
        return true;
    }
    bool setSupplierId(int supplierId) {
        if(supplierId <= 0) return false;
        this->supplierId = supplierId;
        return true;
    }
    bool setActive(bool active) {
        this->active = active;
        return true;
    }

    bool isValid() const {
        if(bookId <= 0) return false;
        if(title.empty()) return false;
        if(author.empty()) return false;
        if(category.empty()) return false;
        if(price < 0) return false;
        if(stockQuantity < 0) return false;
        if(supplierId <= 0) return false;
        return true;
    }
    bool hasStock(int quantity) const {
        if(quantity <= 0) return false;
        return stockQuantity >= quantity;
    }
    bool reduceStock(int quantity) {
        if(quantity <= 0) return false;
        if(!hasStock(quantity)) return false;
        stockQuantity -= quantity;
        return true;
    }
    bool increaseStock(int quantity) {
        if(quantity <= 0) return false;
        stockQuantity += quantity;
        return true;
    }
    // toCsvRow()/fromCsvRow() format: bookId,title,author,category,price,stockQuantity,supplierId,active
    string toCsvRow() const {
        return to_string(bookId) + "," + title + "," + author + "," + category + "," +
               to_string(price) + "," + to_string(stockQuantity) + "," +
               to_string(supplierId) + "," + (active ? "1" : "0");
    }
    bool fromCsvRow(const string& row) {
        // int bookId, string title, string author, string category, double price, int stockQuantity, int supplierId, bool active
        // Divide the string by comma
        // check if we have 8 fields or not


        stringstream ss(row);
        int bookId, stockQuantity, supplierId;
        string title, author, category;
        double price;
        bool active;

        string field;
        int itx = 0; // Keep track of which item we are on
        while(getline(ss, field, ',')){
            switch(itx) {
                case 0:
                bookId = stoi(field);
                break;
                case 1:
                title = field;
                break;
                case 2:
                author = field;
                break;
                case 3:
                category = field;
                break;
                case 4:
                price = stod(field);
                break;
                case 5:
                stockQuantity = stoi(field);
                break;
                case 6:
                supplierId = stoi(field);
                break;
                case 7:
                active = stoi(field) == 0 ? false : true;
                break; 
            }
            ++itx;
        }

        // Check if there are 8 fields or not
        if (itx != 8) {
            cout << "Number of fields mismatch!" << endl;
            return false;
        }
        
        // Implementation
        if (!setBookId(bookId)) return false;
        if (!setTitle(title)) return false;
        if (!setAuthor(author)) return false;
        if (!setCategory(category)) return false;
        if (!setPrice(price)) return false;
        if (!setStockQuantity(stockQuantity)) return false;
        if (!setSupplierId(supplierId)) return false;
        setActive(active);
        return true;
    }
    
    void display() const {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Category: " << category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock Quantity: " << stockQuantity << endl;
        cout << "Supplier ID: " << supplierId << endl;
        cout << "Active: " << (active ? "Yes" : "No") << endl;
    }
};