#include "EmployeeRegister.h"

EmployeeRegister::EmployeeRegister()
{
}

EmployeeRegister::~EmployeeRegister()
{
}

bool EmployeeRegister::addEmployee(Employee* employee)
{
	Node* newNode = new Node();
	newNode->employee = employee;

	// If empty, add to list
	if (head == nullptr)
	{
		newNode->next = nullptr;
		head = newNode;
		return true;
	}

	Node* currentNode = head;

	//check head
	if (currentNode->employee->getID() > newNode->employee->getID())
	{
		newNode->next = head;
		head = newNode;
		return true;
	}

	if (currentNode->employee->getID() == newNode->employee->getID())
	{
		return false;
	}

	while (currentNode->next != nullptr)
	{
		if (currentNode->next->employee->getID() > newNode->employee->getID())
		{
			newNode->next = currentNode->next->next;
			currentNode->next->next = newNode;
			return true;
		}
		if (currentNode->next->employee->getID() == newNode->employee->getID())
		{
			return false;
		}
		currentNode = currentNode->next;
	}

	currentNode->next = newNode;
	newNode->next = nullptr;
	return true;
}

Employee* EmployeeRegister::getEmployee(int employeeID)
{
	Node* temp = head;
	while (temp->employee->getID() != employeeID && temp != nullptr)
	{
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		return nullptr;
	}
	return temp->employee;
}


