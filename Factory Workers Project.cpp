//This is the code for the TeamLeader class

#include <iostream>
#include <string>
#include <iomanip> // For formatting output

using namespace std;

// Assuming the ProductionWorker class is already implemented
// ProductionWorker inherits from Employee
class ProductionWorker {
private:
    string name;      // Employee's name
    int number;       // Employee's ID number
    string hireDate;  // Employee's hire date
    int shift;        // Shift (1 for Day, 2 for Night)
    double hourlyPay; // Hourly pay rate

public:
    // Default constructor
    ProductionWorker() : name(""), number(0), hireDate(""), shift(0), hourlyPay(0.0) {}

    // Parameterized constructor
    ProductionWorker(const string& empName, int empNumber, const string& empHireDate, int empShift, double empHourlyPay)
        : name(empName), number(empNumber), hireDate(empHireDate), shift(empShift), hourlyPay(empHourlyPay) {}

    // Accessors
    string getName() const { return name; }
    int getNumber() const { return number; }
    string getHireDate() const { return hireDate; }
    int getShift() const { return shift; }
    double getHourlyPay() const { return hourlyPay; }

    // Mutators
    void setName(const string& empName) { name = empName; }
    void setNumber(int empNumber) { number = empNumber; }
    void setHireDate(const string& empHireDate) { hireDate = empHireDate; }
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

    // Print function
    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << number << endl;
        cout << "Hire Date: " << hireDate << endl;
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << fixed << setprecision(2);
        cout << "Hourly Pay Rate: $" << hourlyPay << endl;
    }

    // Virtual destructor
    virtual ~ProductionWorker() {}
};

// TeamLeader class derived from ProductionWorker
class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;        // Monthly bonus amount
    int requiredTrainingHours;  // Number of required training hours
    int attendedTrainingHours;  // Number of attended training hours

public:
    // Default constructor
    TeamLeader() : ProductionWorker(), monthlyBonus(0.0), requiredTrainingHours(0), attendedTrainingHours(0) {}

    // Parameterized constructor
    TeamLeader(const string& empName, int empNumber, const string& empHireDate, int empShift, double empHourlyPay,
        double empMonthlyBonus, int empRequiredHours, int empAttendedHours)
        : ProductionWorker(empName, empNumber, empHireDate, empShift, empHourlyPay),
        monthlyBonus(empMonthlyBonus),
        requiredTrainingHours(empRequiredHours),
        attendedTrainingHours(empAttendedHours) {}

    // Accessors
    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredTrainingHours() const { return requiredTrainingHours; }
    int getAttendedTrainingHours() const { return attendedTrainingHours; }

    // Mutators
    void setMonthlyBonus(double empMonthlyBonus) {
        if (empMonthlyBonus >= 0.0)
            monthlyBonus = empMonthlyBonus;
        else
            cout << "Error: Monthly bonus must be non-negative." << endl;
    }

    void setRequiredTrainingHours(int empRequiredHours) {
        if (empRequiredHours >= 0)
            requiredTrainingHours = empRequiredHours;
        else
            cout << "Error: Required training hours must be non-negative." << endl;
    }

    void setAttendedTrainingHours(int empAttendedHours) {
        if (empAttendedHours >= 0)
            attendedTrainingHours = empAttendedHours;
        else
            cout << "Error: Attended training hours must be non-negative." << endl;
    }

    // Overridden print function
    void print() const override {
        ProductionWorker::print(); // Call base class print method
        cout << "Monthly Bonus: $" << fixed << setprecision(2) << monthlyBonus << endl;
        cout << "Required Training Hours: " << requiredTrainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    }
};

int main() {
    // Create a TeamLeader object
    TeamLeader leader("Mike Rogers", 64327, "2/7/2024", 2, 25.50, 150.00, 20, 10);

    // Print TeamLeader details
    cout << "Team Leader:" << endl;
    leader.print();

    return 0;
}
