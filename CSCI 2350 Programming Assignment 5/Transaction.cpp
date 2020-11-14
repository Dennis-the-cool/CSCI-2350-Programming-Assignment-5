#include "Transaction.h"

Transaction::Transaction()
{
}

Transaction::~Transaction()
{
}

void Transaction::setTransactionType(string)
{
}

string Transaction::getTransactionType()
{
	return string();
}

void Transaction::setID(int)
{
}

int Transaction::getID()
{
	return 0;
}

HireTransaction::HireTransaction()
{
}

HireTransaction::~HireTransaction()
{
}

void HireTransaction::setName(string)
{
}

string HireTransaction::getName()
{
	return string();
}

void HireTransaction::setEmployeeType(string)
{
}

string HireTransaction::getEmployeeType()
{
	return string();
}

void HireTransaction::setPayRate(double)
{
}

double HireTransaction::getPayRate()
{
	return 0.0;
}

HoursTransaction::HoursTransaction()
{
}

HoursTransaction::~HoursTransaction()
{
}

void HoursTransaction::setHoursWorked(double)
{
}

double HoursTransaction::getHoursWorked()
{
	return 0.0;
}

PiecesTransaction::PiecesTransaction()
{
}

PiecesTransaction::~PiecesTransaction()
{
}

void PiecesTransaction::setItemsProduced(int)
{
}

SalesTransaction::SalesTransaction()
{
}

SalesTransaction::~SalesTransaction()
{
}

void SalesTransaction::setSalesAmount(double)
{
}

double SalesTransaction::getSalesAmount()
{
	return 0.0;
}

TerminationTransaction::TerminationTransaction()
{
}

TerminationTransaction::~TerminationTransaction()
{
}
