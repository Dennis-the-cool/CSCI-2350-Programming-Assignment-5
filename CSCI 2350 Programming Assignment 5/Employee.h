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
	bool fired;
public:
	Employee();
	~Employee();
	void termination();
	void hire(int, string, string, double, int);
	virtual void payroll() = 0;
};

class Salary : public Employee
{
private:
	int dayFired;
public:
	Salary();
	~Salary();
	void payroll();
	void termination(int);
};

class Hourly
{
private:
	int lastDayWorked;
	int daysInRowWorked;
public:
	Hourly();
	~Hourly();
	void payroll();
};

class Piecework : public Employee
{
private:
	int itemsProduced;
public:
	Piecework();
	~Piecework();
	void payroll();
	void addPieces(int);
};

class Commission : public Employee
{
private:
	double salesAmount;
public:
	Commission();
	~Commission();
	void payroll();
	void addSales(double);
};
