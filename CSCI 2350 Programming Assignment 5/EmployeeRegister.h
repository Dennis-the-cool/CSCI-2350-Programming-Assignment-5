#pragma once
#include "Employee.h"

class EmployeeRegister
{
	struct Node
	{
		Employee* employee;
		Node* next;
	};
private:
	Node* head;
public:
	EmployeeRegister();
	~EmployeeRegister();
	bool addEmployee(Employee*);
	Employee* getEmployee(int);
};