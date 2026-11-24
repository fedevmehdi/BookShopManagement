/*
 * Phase: 3 - Entity Classes
 *
 * Employee Entity Contract
 * ========================
 *
 * Purpose:
 * - Represent one employee record.
 *
 * Private data:
 * - int employeeId
 * - std::string fullName
 * - std::string role
 * - std::string phone
 * - bool active
 *
 * Suggested public ADT:
 * - Employee()
 * - Employee(int employeeId, const std::string& fullName,
 *            const std::string& role, const std::string& phone,
 *            bool active)
 * - getEmployeeId(), getFullName(), getRole(), getPhone(), isActive()
 * - setEmployeeId(int), setFullName(...), setRole(...),
 *   setPhone(...), setActive(bool)
 * - bool isValid() const
 * - void display() const
 * - std::string toCsvRow() const
 * - bool fromCsvRow(const std::string& row)
 *
 * Required behaviour:
 * - Employee ID must be positive.
 * - Full name and role must not be empty.
 * - Phone must meet the team-approved validation format.
 * - isValid() must validate all required fields.
 * - Active status controls whether normal transaction workflows may use the employee.
 */

#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Employee {
private:
    int employeeId;
    string fullName;
    string role;
    string phone;
    bool active;

public:
    Employee(): employeeId(0), fullName(""), role(""), phone(""), active(false) {}
    Employee(int employeeId, string fullName, string role, string phone, bool active)
        : employeeId(employeeId), fullName(fullName), role(role), phone(phone), active(active) {}

    int getEmployeeId() const {
        return employeeId;
    }
    string getFullName() const {
        return fullName;
    }
    string getRole() const {
        return role;
    }
    string getPhone() const {
        return phone;
    }
    bool isActive() const {
        return active;
    }

    void setEmployeeId(int id) {
        if (id <= 0) {
            cout << "ID must be positive!" << endl;
            return;
        }
        employeeId = id;
    }
    void setFullName(string name) {
        if (name.empty()) {
            cout << "Name can not be empty" << endl;
            return;
        }
        fullName = name;
    }
    void setRole(string role) {
        if (role.empty()) {
            cout << "Role can not be empty" << endl;
            return;
        }
        this->role = role;
    }
    void setPhone(string phone) {
        if (phone.empty()) {
            cout << "Phone can not be empty" << endl;
            return;
        }
        this->phone = phone;
    }
    void setActive(bool active) {
        this->active = active;
    }

    bool isValid() const {
        return employeeId > 0 &&
            !fullName.empty() &&
            !role.empty() &&
            !phone.empty();
    }

    void display() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Role: " << role << endl;
        cout << "Phone: " << phone << endl;
        cout << "Active: " << (active ? "Yes" : "No") << endl;
    }

    string toCsvRow() const {
        return to_string(employeeId) + "," + fullName + "," + role + "," +
            phone + "," + (active ? "1" : "0");
    }

    bool fromCsvRow(const string& row) {
        stringstream ss(row);
        int parsedId;
        string parsedFullName, parsedRole, parsedPhone;
        bool parsedActive;

        string field;
        int fieldIndex = 0;
        while (getline(ss, field, ',')) {
            switch (fieldIndex) {
                case 0:
                    parsedId = stoi(field);
                    break;
                case 1:
                    parsedFullName = field;
                    break;
                case 2:
                    parsedRole = field;
                    break;
                case 3:
                    parsedPhone = field;
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

        Employee parsedEmployee(parsedId, parsedFullName, parsedRole,
                                parsedPhone, parsedActive);
        if (!parsedEmployee.isValid()) {
            return false;
        }

        *this = parsedEmployee;
        return true;
    }
};
