/*
 * Phase: 3 - Entity Classes
 *
 * Customer Entity Contract
 * ========================
 *
 * Purpose:
 * - Represent one customer record.
 *
 * Private data:
 * - int customerId
 * - std::string fullName
 * - std::string phone
 * - std::string address
 * - bool active
 *
 * Suggested public ADT:
 * - Customer()
 * - Customer(int customerId, const std::string& fullName,
 *            const std::string& phone, const std::string& address,
 *            bool active)
 * - getCustomerId(), getFullName(), getPhone(), getAddress(), isActive()
 * - setCustomerId(int), setFullName(...), setPhone(...),
 *   setAddress(...), setActive(bool)
 * - bool isValid() const
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - Customer ID must be positive.
 * - Full name and address must not be empty.
 * - Phone must meet the team-approved validation format.
 * - isValid() must validate all required fields.
 * - Active status controls whether normal CRUD workflows may use the customer.
 *
 * Persistence boundary:
 * - This class performs field conversion and validation only.
 * - File I/O is owned by the File Manager in Phase 7.
 */

#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Customer {
private:
    int customerId;
    string fullname;
    string phone;
    string address;
    bool active;

public:
    Customer(): customerId(0), fullname(""), phone(""), address(""), active(false) {}
    Customer(int customerId, string fullName, string phone, string address, bool active)
        : customerId(customerId), fullname(fullName), phone(phone), address(address), active(active) {}

    bool isValid() const {
        return customerId > 0 &&
            !fullname.empty() &&
            !phone.empty() &&
            !address.empty();
    }

    string toCsvRow() const {
        return to_string(customerId) + "," + fullname + "," + phone + "," +
            address + "," + (active ? "1" : "0");
    }

    bool fromCsvRow(const string& row) {
        stringstream ss(row);
        int parsedId;
        string parsedFullname, parsedPhone, parsedAddress;
        bool parsedActive;

        string field;
        int fieldIndex = 0;
        while (getline(ss, field, ',')) {
            switch (fieldIndex) {
                case 0:
                    parsedId = stoi(field);
                    break;
                case 1:
                    parsedFullname = field;
                    break;
                case 2:
                    parsedPhone = field;
                    break;
                case 3:
                    parsedAddress = field;
                    break;
                case 4:
                    parsedActive = stoi(field) != 0;
                    break;
            }
            ++fieldIndex;
        }

        if (fieldIndex != 5) {
            cout << "Number of fields mismatch!" << endl;
            return false;
        }

        Customer parsedCustomer(parsedId, parsedFullname, parsedPhone,
                                parsedAddress, parsedActive);
        if (!parsedCustomer.isValid()) {
            return false;
        }

        *this = parsedCustomer;
        return true;
    }

    int getCustomerId() const {
        return customerId;
    }
    string getFullName() const {
        return fullname;
    }
    string getPhone() const {
        return phone;
    }
    bool getActive() const {
        return active;
    }

    void setCustomerId(int id) {
        if(id <= 0) {
            cout << "ID must be positive!" << endl;
            return;
        }
        customerId = id;
    }
    void setFullname(string name) {
        if(name.empty()) {
            cout << "Name can not be empty" << endl;
            return;
        }
        fullname = name;
    }
    void setPhone(string phone) {
        if(phone.empty()) {
            cout << "Phone not be empty" << endl;
            return;
        }
        this->phone = phone;
    }

    void setAddress(string address) {
        if(address.empty()) {
            cout << "Address can not be empty" << endl;
            return;
        }
        this->address = address;
    }

    void setActive(bool active) {
        this->active = active;
    }
};