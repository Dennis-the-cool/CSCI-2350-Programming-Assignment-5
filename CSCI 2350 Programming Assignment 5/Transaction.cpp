#include "Transaction.h"

Transaction::Transaction() : transactionType(), employeeID()
{
}

Transaction::~Transaction()
{
}

void Transaction::setTransactionType(string newTransactionType)
{
	transactionType = newTransactionType;
}

string Transaction::getTransactionType()
{
	return transactionType;
}

void Transaction::setEmployeeID(int newEmployeeID)
{
	employeeID = newEmployeeID;

}

int Transaction::getEmployeeID()
{
	return employeeID;
}

HireTransaction::HireTransaction() : name(), employeeType(), payRate()
{
}

HireTransaction::~HireTransaction()
{
}

void HireTransaction::setName(string newName)
{
	name = newName;
}

string HireTransaction::getName()
{
	return name;
}

void HireTransaction::setEmployeeType(string newEmployeeType)
{
	employeeType = newEmployeeType;
}

string HireTransaction::getEmployeeType()
{
	return employeeType;
}

void HireTransaction::setPayRate(double newPayRate)
{
	payRate = newPayRate;
}

double HireTransaction::getPayRate()
{
	return payRate;
}

HoursTransaction::HoursTransaction() : hoursWorked()
{
}

HoursTransaction::~HoursTransaction()
{
}

void HoursTransaction::setHoursWorked(double newHoursWorked)
{
	hoursWorked = newHoursWorked;
}

double HoursTransaction::getHoursWorked()
{
	return hoursWorked;
}

PiecesTransaction::PiecesTransaction() : itemsProduced()
{
}

PiecesTransaction::~PiecesTransaction()
{
}

void PiecesTransaction::setItemsProduced(int newItemsProduced)
{
	itemsProduced = newItemsProduced;
}

int PiecesTransaction::getItemsProduced()
{
	return itemsProduced;
}

SalesTransaction::SalesTransaction() : salesAmount()
{
}

SalesTransaction::~SalesTransaction()
{
}

void SalesTransaction::setSalesAmount(double newSalesAmount)
{
	salesAmount = newSalesAmount;
}

double SalesTransaction::getSalesAmount()
{
	return salesAmount;
}

TerminationTransaction::TerminationTransaction()
{
}

TerminationTransaction::~TerminationTransaction()
{
}
