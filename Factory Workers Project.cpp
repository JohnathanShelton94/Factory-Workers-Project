

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;      // Employee's name
    int number;       // Employee's ID number
    string hireDate;  // Employee's hire date

public:
    // Default constructor
    Employee() : name(""), number(0), hireDate("") {}

    // Parameterized constructor
    Employee(const string& empName, int empNumber, const string& empHireDate)
        : name(empName), number(empNumber), hireDate(empHireDate) {}

    // Accessor (getter) functions
    string getName() const { return name; }
    int getNumber() const { return number; }
    string getHireDate() const { return hireDate; }

    // Mutator (setter) functions
    void setName(const string& empName) { name = empName; }
    void setNumber(int empNumber) { number = empNumber; }
    void setHireDate(const string& empHireDate) { hireDate = empHireDate; }

    // Print function
    void print() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Number: " << number << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

int main() {
    // Creating an Employee object using the parameterized constructor
    Employee emp1("John Doe", 12345, "01/15/2020");

    // Displaying employee information
    emp1.print();

    // Modifying employee information
    emp1.setName("Jane Smith");
    emp1.setNumber(67890);
    emp1.setHireDate("03/10/2022");

    // Displaying updated employee information
    cout << endl << "Updated Employee Information:" << endl;
    emp1.print();

    return 0;
}
