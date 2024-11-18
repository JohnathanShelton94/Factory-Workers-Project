//This is the start of the employee class project


#include <iostream>
#include <string>
#include <limits> // For numeric limits
#include <regex>  // For validating hire date

using namespace std;

class Employee {
private:
    string name;            // Employee's name
    int number;             // Employee's ID number
    string hireDate;        // Employee's hire date (format: MM/DD/YYYY)

public:
    // Default constructor
    Employee() : name(""), number(0), hireDate("") {}

    
    Employee(const string& empName, int empNumber, const string& empHireDate)
        : name(empName), number(empNumber), hireDate(empHireDate) {}

                // Accessor functions
    string getName() const { return name; }
    int getNumber() const { return number; }
    string getHireDate() const { return hireDate; }

                // Mutator functions with validation
    bool setName(const string& empName) {
        if (empName.empty()) {
            cout << "Error: Name cannot be empty." << endl;
            return false;
        }
        name = empName;
        return true;
    }

    bool setNumber(int empNumber) {
        if (empNumber <= 0) {
            cout << "Error: Employee number must be a positive integer." << endl;
            return false;
        }
        number = empNumber;
        return true;
    }

    bool setHireDate(const string& empHireDate) {
                    // Validate the hire date format (MM/DD/YYYY)
        regex datePattern(R"(\d{2}/\d{2}/\d{4})");
        if (!regex_match(empHireDate, datePattern)) {
            cout << "Error: Hire date must be in the format MM/DD/YYYY." << endl;
            return false;
        }
        hireDate = empHireDate;
        return true;
    }

                // Print function
    void print() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Number: " << number << endl;
        cout << "Hire Date: " << hireDate << endl;
    }

                // Function to input employee details
    void inputDetails() {
        string tempName, tempDate;
        int tempNumber;

                // Input and validate name
        do {
            cout << "Enter employee name: ";
            getline(cin, tempName);
        } while (!setName(tempName));

                // Input and validate employee number
        do {
            cout << "Enter employee number (positive integer): ";
            cin >> tempNumber;

                // Clear input buffer if invalid input is detected
            if (cin.fail()) {
                cout << "Error: Invalid input. Please enter a positive integer." << endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue;
            }

        } while (!setNumber(tempNumber));

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

                // Input and validate hire date
        do {
            cout << "Enter hire date (MM/DD/YYYY): ";
            getline(cin, tempDate);
        } while (!setHireDate(tempDate));
    }
};

int main() {
    Employee emp;

    cout << "Enter employee details:" << endl;
    emp.inputDetails();

    cout << "\nEmployee Information:" << endl;
    emp.print();

    return 0;
}
