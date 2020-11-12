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
	virtual void serialize() = 0;
	void deserialize();
	void payroll();
	void hire(int, string, string, double, int);
	void termination();
};

