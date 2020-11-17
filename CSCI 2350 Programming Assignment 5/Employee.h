#pragma once
#include <string>
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
	virtual void payroll() = 0;
	virtual void hire(int, string, string, double, int) = 0;
	virtual void termination() = 0;
};

class Salary: public Employee
{
private:
   int dayFired;
public:
   Salary();
   ~Salary();
   void payroll();
   void hire(int, string, string, double, int);
   void termination();
};

class Piecework: public Employee
{
private: 
	int itemsProduced; 
public: 
	Piecework();
	~Piecework();
	void payroll();
	void hire(int, string, string, double, int);
	void termination();
};

class Commission: public Employee
{
private:
	double salesAmount;
public: 
	Commission();
	~Commission();
	void payroll();
	void hire(int, string, string, double, int);
	void termination();
};