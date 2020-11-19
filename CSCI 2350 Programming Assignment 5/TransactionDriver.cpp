#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Transaction.h"
#include "TransactionList.h"
#include "Employee.h"
using namespace std;

Transaction* processTransactionLine(string line)
{
	string transactionType = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);
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
		throw - 1;
	}

	int employeeID;

	stringstream converterID;

	converterID << employeeIDString;
	converterID >> employeeID;

	transaction->setTransactionType(transactionType);
	transaction->setEmployeeID(employeeID);
	return transaction;
}

Employee* processEmployeeLine(string line)
{
	// int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired
	string employeeIDString = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);
	string employeeName = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);
	string employeeType = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);
	string employeePayRate = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);
	string employeeDateHired = line.substr(0, line.find(","));
	line = line.substr(line.find(",") + 1);

	int employeeID;

	stringstream converterID;

	converterID << employeeIDString;
	converterID >> employeeID;

	stringstream converterPayRate;
	
	double payRate; 
	converterPayRate << employeePayRate;
	converterPayRate >> payRate;

	stringstream converterDateHired;
	int dateHired;
	converterDateHired << employeeDateHired;
    converterDateHired >> dateHired;

	Employee* employee;

	stringstream converter;

	if (employeeType.compare("salary") == 0)
	{
		// TODO: Write file initialization of salary employee
		if(payRate >= 4000.0)
		{	
			employee = new Salary(employeeID, employeeName, employeeType, payRate, dateHired);
		}
		else
		{
			cout << "Illegal payrate.";
			throw -1;
		}
	}
	else if (employeeType.compare("hourly") == 0)
	{
		// TODO: Write file initialization of hourly employee
		// lastDayWorked(0), daysInRowWorked(0), regularHours(0), overtimeHours(0), doubleHours(0), tripleHours(0)
		employee = new Hourly(employeeID, employeeName, employeeType, payRate, dateHired);
	}
	else if (employeeType.compare("piecework") == 0)
	{
		// itemsProduced(0)
		employee = new Piecework(employeeID, employeeName, employeeType, payRate, dateHired);
	}
	else if (employeeType.compare("commission") == 0)
	{
		// TODO: Write file initialization of commission employee
		// salesAmount(0), mediumSalesAmount(0), largeSalesAmount(0)
		employee = new Commission(employeeID, employeeName, employeeType, payRate, dateHired);
	}
	else
	{
		cout << "Illegal employee.";
		throw - 1;
	}

	return employee;
}

void processTransactionFile(string transactionFileString, string employeeFileString)
{
	// TODO: Process transaction file
}

void sortTransactionFile(string transactionInputFileString, string transactionOutputFileString)
{
	ifstream transactionInputFile;
	string day;
	getline(transactionInputFile, day);
	string transaction;

	TransactionList transactionList;

	while (getline(transactionInputFile, transaction))
	{
		Transaction* t = processTransactionLine(transaction);
		transactionList.addTransaction(t);
	}

	ofstream transactionOutputFile;
	transactionOutputFile << day;

	while (!transactionList.isEmpty())
	{
		transactionOutputFile << endl << transaction;
	}

	// TODO: Finish transaction sorting
}

void printPayroll(string employeeFile, string payrollOutputFile)
{
	ifstream inputFile;
	inputFile.open(employeeFile);
	ofstream outputFile;
	outputFile.open(payrollOutputFile);
	string line;
	while (getline(inputFile, line))
	{
		Employee* employee = processEmployeeLine(line);
		string payrollOutput = employee->payroll();
		outputFile << payrollOutput << endl;
	}
}

int main()
{
	cout << "This is the transaction processing driver. Enter a number to choose an option." << endl;
	cout << "(1) Process transaction file." << endl;
	cout << "(2) Sort transaction file." << endl;
	cout << "(3) Output employee paycheck information." << endl;

	int input;

	cin >> input;

	if (input == 1)
	{
		cout << "Enter the name and directory of the transaction file." << endl;
		string transactionFile;
		cin >> transactionFile;

		cout << "Enter the name and directory of the employee file." << endl;
		string employeeFile;
		cin >> employeeFile;

		processTransactionFile(transactionFile, employeeFile);
	}
	else if (input == 2)
	{
		cout << "Enter the name and directory of the input transaction file." << endl;
		string transactionInputFile;
		cin >> transactionInputFile;

		cout << "Enter the name and directory of the output transaction file." << endl;
		string transactionOutputFile;
		cin >> transactionOutputFile;

		sortTransactionFile(transactionInputFile, transactionOutputFile);
	}
	else if (input == 3)
	{
		cout << "Enter the name and directory of the employee file." << endl;
		string employeeFile;
		cin >> employeeFile;

		cout << "Enter the name and directory of the payroll output file." << endl;
		string payrollFile;
		cin >> payrollFile;

		printPayroll(employeeFile, payrollFile);
	}
}