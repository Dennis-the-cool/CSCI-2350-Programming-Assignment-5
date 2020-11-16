<<<<<<< HEAD
// Test
=======
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Transaction.h"
#include "TransactionList.h"
using namespace std;

TransactionList transactionList;

void processLine(string line)
{
	if (line.find(",") < 0)
	{
		cout << "Error processing transaction: " << line << endl;
		return;
	}

	string transactionType = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);

	if (line.find(",") < 0)
	{
		cout << "Error processing transaction: " << transactionType << "," << line << endl;
		return;
	}

	string employeeIDString = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);

	Transaction* transaction;

	stringstream converter;

	if (transactionType.compare("hire") == 0)
	{
		// name, employee type, pay rate
		string name = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string employeeType = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string payRateString = line;

		HireTransaction* hireTransaction = new HireTransaction;
		hireTransaction->setName(name);
		hireTransaction->setEmployeeType(employeeType);
		converter << payRateString;
		double payRate;
		converter >> payRate;
		hireTransaction->setPayRate(payRate);
		transaction = hireTransaction;
	}
	else if (transactionType.compare("hours") == 0)
	{
		//hours worked
		string hoursWorkedString = line;

		HoursTransaction* hoursTransaction = new HoursTransaction;
		converter << hoursWorkedString;
		int hoursWorked;
		converter >> hoursWorked;
		hoursTransaction->setHoursWorked(hoursWorked);
		transaction = hoursTransaction;
	}
	else if (transactionType.compare("pieces") == 0)
	{
		//items produced
		string itemsProducedString = line;

		PiecesTransaction* piecesTransaction = new PiecesTransaction;
		converter << itemsProducedString;
		int itemsProduced;
		converter >> itemsProduced;
		piecesTransaction->setItemsProduced(itemsProduced);
		transaction = piecesTransaction;
	}
	else if (transactionType.compare("sales") == 0)
	{
		//sales amount
		string salesAmountString = line;

		SalesTransaction* salesTransaction = new SalesTransaction;
		converter << salesAmountString;
		double salesAmount;
		converter >> salesAmount;
		salesTransaction->setSalesAmount(salesAmount);
		transaction = salesTransaction;
	}
	else if (transactionType.compare("termination") == 0)
	{
		TerminationTransaction* terminationTransaction = new TerminationTransaction;
		transaction = terminationTransaction;
	}
	else
	{
		// TODO: Process error
		cout << "Error processing transaction: " << transactionType << "," << employeeIDString << "," << line << endl;
		return;
	}

	int employeeID;

	stringstream converterID;

	converterID << employeeIDString;
	converterID >> employeeID;
	
	transaction->setTransactionType(transactionType);
	transaction->setEmployeeID(employeeID);
	transactionList.addTransaction(transaction);
}

int main()
{
	ifstream file;
	file.open("TestTransactionFile.txt");
	string line;
	string day;
	getline(file, day);
	while (getline(file, line))
	{
		processLine(line);
	}
	while (!transactionList.isEmpty())
	{
		Transaction* t = transactionList.removeTransaction();
		cout << t->getEmployeeID() << endl;
		cout << t->getTransactionType() << endl;
		delete t;
	}
	file.close();
	return 0;
}
>>>>>>> eedf48fcb9a40799510720225d98dc3881a644b3
