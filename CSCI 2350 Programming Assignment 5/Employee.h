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
	Employee(int, string, string, double, int);
	~Employee();
	void termination(int);
	virtual string payroll() = 0;
};

class Salary : public Employee
{
private:
	
public:
	Salary();
	~Salary();
	string payroll();
};

class Hourly
{
private:
	int lastDayWorked;
	int daysInRowWorked;
	double regularHours;
	double overtimeHours;
	double doubleHours;
	double tripleHours;
public:
	Hourly();
	~Hourly();
	string payroll();
	void addHours(int, double);
};

class Piecework : public Employee
{
private:
	int itemsProduced;
public:
	Piecework();
	~Piecework();
	string payroll();
	void addPieces(int);
};

class Commission : public Employee
{
private:
	double salesAmount;
	double mediumSalesAmount;
	double largeSalesAmount;
public:
	Commission();
	~Commission();
	string payroll();
	void addSales(double);
};
