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
private:
	Employee();
	~Employee();
	virtual void payroll() = 0;
	virtual void hire(int, string, string, double, int) = 0;
	virtual void termination() = 0;
};

