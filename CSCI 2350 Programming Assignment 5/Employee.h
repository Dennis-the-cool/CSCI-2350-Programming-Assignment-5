#pragma once
#include <string>
#include <sstream>
using namespace std;

class Employee
{
protected:
    int id;
    string name;
    string type;
    double payRate;
    int hiredDate;
    int firedDate;
public:
    Employee(int, string, string, double, int);
    Employee(int, string, string, double, int, int);
    ~Employee();
    void termination(int);
    virtual string payroll() = 0;
    virtual string serialize() = 0;
    int getID();
};

class Salary : public Employee
{
public:
    Salary(int, string, string, double, int);
    Salary(int, string, string, double, int, int);
    ~Salary();
    string payroll();
    string serialize();
};

class Hourly : public Employee
{
private:
    int lastDayWorked;
    int daysInRowWorked;
    double regularHours;
    double overtimeHours;
    double doubleHours;
    double tripleHours;
public:
    Hourly(int, string, string, double, int);
    Hourly(int, string, string, double, int, int, int, int, double, double, double, double);
    ~Hourly();
    string payroll();
    void addHours(double, int);
    string serialize();
};

class Piecework : public Employee
{
private:
    int itemsProduced;
public:
    Piecework(int, string, string, double, int);
    Piecework(int, string, string, double, int, int, int);
    ~Piecework();
    string payroll();
    void addPieces(int);
    string serialize();
};

class Commission : public Employee
{
private:
    double salesAmount;
    double mediumSalesAmount;
    double largeSalesAmount;
public:
    Commission(int, string, string, double, int);
    Commission(int, string, string, double, int, int, double, double, double);
    ~Commission();
    string payroll();
    void addSales(double);
    string serialize();
};