//This is the start of the productionworker class project

#include <iostream>
#include <string>
#include <iomanip>  // For formatting pay rate output

using namespace std;

// Base Employee class
class Employee {
private:
    string name;        // Employee's name
    int number;         // Employee's ID number
    string hireDate;    // Employee's hire date

public:
            // Default constructor
    Employee() : name(""), number(0), hireDate("") {}

    Employee(const string& empName, int empNumber, const string& empHireDate)
        : name(empName), number(empNumber), hireDate(empHireDate) {}

            // Accessor functions
    string getName() const { return name; }
    int getNumber() const { return number; }
    string getHireDate() const { return hireDate; }

            // Mutator functions
    void setName(const string& empName) { name = empName; }
    void setNumber(int empNumber) { number = empNumber; }
    void setHireDate(const string& empHireDate) { hireDate = empHireDate; }

            // Virtual print function
    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << number << endl;
        cout << "Hire Date: " << hireDate << endl;
    }

            // Virtual destructor
    virtual ~Employee() {}
};

// Derived ProductionWorker class
class ProductionWorker : public Employee {
private:
    int shift;              // Shift (1 for Day, 2 for Night)
    double hourlyPay;       // Hourly pay rate

public:
    // Default constructor
    ProductionWorker() : Employee(), shift(0), hourlyPay(0.0) {}

    ProductionWorker(const string& empName, int empNumber, const string& empHireDate, int empShift, double empHourlyPay)
        : Employee(empName, empNumber, empHireDate), shift(empShift), hourlyPay(empHourlyPay) {}

            // Accessor functions
    int getShift() const { return shift; }
    double getHourlyPay() const { return hourlyPay; }

            // Mutator functions
    void setShift(int empShift) {
        if (empShift == 1 || empShift == 2)
            shift = empShift;
        else
            cout << "Error: Shift must be 1 (Day) or 2 (Night)." << endl;
    }

    void setHourlyPay(double empHourlyPay) {
        if (empHourlyPay >= 0.0)
            hourlyPay = empHourlyPay;
        else
            cout << "Error: Hourly pay must be non-negative." << endl;
    }

            // Overridden print function
    void print() const override {
        Employee::print();      // Call base class print
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << fixed << setprecision(2);       // Format pay rate to 2 decimal places
        cout << "Hourly Pay Rate: $" << hourlyPay << endl;
    }
};

// Derived ShiftSupervisor class
class ShiftSupervisor : public Employee {
private:
    double annualSalary;      // Annual salary
    double annualBonus;       // Annual production bonus

public:
    // Default constructor
    ShiftSupervisor() : Employee(), annualSalary(0.0), annualBonus(0.0) {}

    ShiftSupervisor(const string& empName, int empNumber, const string& empHireDate, double empAnnualSalary, double empAnnualBonus)
        : Employee(empName, empNumber, empHireDate), annualSalary(empAnnualSalary), annualBonus(empAnnualBonus) {}

    // Accessor functions
    double getAnnualSalary() const { return annualSalary; }
    double getAnnualBonus() const { return annualBonus; }

    // Mutator functions
    void setAnnualSalary(double empAnnualSalary) {
        if (empAnnualSalary >= 0.0)
            annualSalary = empAnnualSalary;
        else
            cout << "Error: Salary must be non-negative." << endl;
    }

    void setAnnualBonus(double empAnnualBonus) {
        if (empAnnualBonus >= 0.0)
            annualBonus = empAnnualBonus;
        else
            cout << "Error: Bonus must be non-negative." << endl;
    }

    // Overridden print function
    void print() const override {
        Employee::print();  // Call base class print
        cout << fixed << setprecision(2);   // Format salary and bonus to 2 decimal places
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Annual Bonus: $" << annualBonus << endl;
    }
};

int main() {
            // Create first ProductionWorker object
    ProductionWorker worker1("Paul Jones", 12345, "10/28/2024", 1, 20.25);

            // Create second ProductionWorker object
    ProductionWorker worker2("Harriet Smith", 54321, "6/15/2024", 2, 25.50);

            // Display worker details
    cout << "Production Worker 1:" << endl;
    worker1.print();
    cout << endl;

    cout << "Production Worker 2:" << endl;
    worker2.print();
    cout << endl;

            // Create a ShiftSupervisor object
    ShiftSupervisor supervisor("Elmer Velasquez", 100325, "1/17/2024", 70000.00, 1000.00);

            // Display supervisor details
    cout << "Shift Supervisor:" << endl;
    supervisor.print();

    return 0;
}
