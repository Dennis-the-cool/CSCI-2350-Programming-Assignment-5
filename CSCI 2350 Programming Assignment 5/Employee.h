#pragma once
#include <string>
#include <sstream>
using namespace std;

class Employee
{
protected:
	int id;
	string name;
	string employeeType;
	double payRate;
	int hiredDate;
	int dayFired;
public:
	Employee();
	~Employee();
	void termination(int);
	virtual string payroll() = 0;
};

class Salary: public Employee
{
public:
   Salary(int, string, string, double, int);
   ~Salary();
   string payroll();
};

class Hourly: public Employee
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
	~Hourly();
	string payroll();
    void addHours(double, int);
};

class Piecework: public Employee
{
private:
    int itemsProduced;
public:
    Piecework(int, string, string, double, int);
    ~Piecework();
    string payroll();
    void addPieces(int);
};

class Commission: public Employee
{
private:
    double salesAmount;
    double mediumSalesAmount;
    double largeSalesAmount;
public:
    Commission(int, string, string, double, int);
    ~Commission();
    string payroll();
    void addSales(double);
};