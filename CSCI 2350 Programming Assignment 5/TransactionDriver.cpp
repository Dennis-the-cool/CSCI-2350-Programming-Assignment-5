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

		HireTransaction* hireTransaction = new HireTransaction();
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
		if (payRate >= 4000.0)
		{
			employee = new Salary(employeeID, employeeName, employeeType, payRate, dateHired);
		}
		else
		{
			cout << "Illegal payrate.";
			throw - 1;
		}
	}
	else if (employeeType.compare("hourly") == 0)
	{
		// TODO: Write file initialization of hourly employee
		// lastDayWorked(0), daysInRowWorked(0), regularHours(0), overtimeHours(0), doubleHours(0), tripleHours(0)
		string lastDayWorkedString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string daysInRowWorkedString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string regularHoursString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string overtimeHoursString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string doubleHoursString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string tripleHoursString = line;

		int lastDayWorked;
		stringstream convertLastDayWorked;
		convertLastDayWorked << lastDayWorkedString;
		convertLastDayWorked >> lastDayWorked;

		int daysInRowWorked;
		stringstream convertDaysInRowWorked;
		convertDaysInRowWorked << daysInRowWorkedString;
		convertDaysInRowWorked >> daysInRowWorked;

		double regularHours;
		stringstream convertRegularHours;
		convertRegularHours << regularHoursString;
		convertRegularHours >> regularHours;

		double overtimeHours;
		stringstream convertOvertimeHours;
		convertOvertimeHours << overtimeHoursString;
		convertOvertimeHours >> overtimeHours;

		double doubleHours;
		stringstream convertDoubleHours;
		convertDoubleHours << doubleHoursString;
		convertDoubleHours >> doubleHours;

		double tripleHours;
		stringstream convertTripleHours;
		convertTripleHours << tripleHoursString;
		convertTripleHours >> tripleHours;

		if (payRate >= 10.0 && payRate <= 26.0)
		{
			employee = new Hourly(employeeID, employeeName, employeeType, payRate, dateHired, lastDayWorked, daysInRowWorked, regularHours, overtimeHours, doubleHours, tripleHours);
		}
		else
		{
			cout << "Illegal payrate.";
			throw - 1;
		}
	}
	else if (employeeType.compare("piecework") == 0)
	{
		// itemsProduced(0)
		string itemsProducedString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);

		int itemsProduced;
		stringstream convertItemsProduced;
		convertItemsProduced << itemsProducedString;
		convertItemsProduced >> itemsProduced;

		if (payRate >= 0.0 && payRate <= 1.0)
		{
			employee = new Piecework(employeeID, employeeName, employeeType, payRate, dateHired, itemsProduced);
		}
		else
		{
			cout << "Illegal payrate.";
			throw - 1;
		}
	}
	else if (employeeType.compare("commission") == 0)
	{
		// TODO: Write file initialization of commission employee
		// salesAmount(0), mediumSalesAmount(0), largeSalesAmount(0)
		string salesAmountString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string mediumSalesAmountString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);
		string largeSalesAmountString = line.substr(0, line.find(","));
		line = line.substr(line.find(",") + 1);

		double salesAmount;
		stringstream convertSalesAmount;
		convertSalesAmount << salesAmountString;
		convertSalesAmount >> salesAmount;

		double mediumSalesAmount;
		stringstream convertMediumSalesAmount;
		convertMediumSalesAmount << mediumSalesAmountString;
		convertMediumSalesAmount >> mediumSalesAmount;

		double largeSalesAmount;
		stringstream convertLargeSalesAmount;
		convertLargeSalesAmount << largeSalesAmountString;
		convertLargeSalesAmount >> largeSalesAmount;

		if (payRate >= 0.03 && payRate <= 0.05)
		{
			employee = new Commission(employeeID, employeeName, employeeType, payRate, dateHired, salesAmount, mediumSalesAmount, largeSalesAmount);
		}
		else
		{
			cout << "Illegal payrate.";
			throw - 1;
		}
	}
	else
	{
		cout << "Illegal employee.";
		throw - 1;
	}

	return employee;
}

void processTransaction(Transaction* transaction, Employee* employee, int day)
{
	if (HoursTransaction* t = dynamic_cast<HoursTransaction*>(transaction))
	{
		Hourly* h = dynamic_cast<Hourly*>(employee);
		h->addHours(t->getHoursWorked(), day);
	}
	else if (PiecesTransaction* t = dynamic_cast<PiecesTransaction*>(transaction))
	{
		Piecework* p = dynamic_cast<Piecework*>(employee);
		p->addPieces(t->getItemsProduced());
	}
	else if (SalesTransaction* t = dynamic_cast<SalesTransaction*>(transaction))
	{
		Commission* c = dynamic_cast<Commission*>(employee);
		c->addSales(t->getSalesAmount());
	}
	else if (TerminationTransaction* t = dynamic_cast<TerminationTransaction*>(transaction))
	{
		employee->termination(day);
	}
	else
	{
		// TODO: Process error
		cout << "Error processing transaction" << endl;
		throw - 1;
	}
}

Employee* processHire(HireTransaction* transaction, int day)
{
	int id = transaction->getEmployeeID();
	string name = transaction->getName();
	string type = transaction->getEmployeeType();
	double pay = transaction->getPayRate();

	if (type.compare("salary") == 0)
	{
		return new Salary(id, name, type, pay, day);
	}
	else if (type.compare("hourly") == 0)
	{
		return new Hourly(id, name, type, pay, day);
	}
	else if (type.compare("piecework") == 0)
	{
		return new Piecework(id, name, type, pay, day);
	}
	else if (type.compare("commission") == 0)
	{
		return new Commission(id, name, type, pay, day);
	}

	return nullptr;
}

void processTransactionFile(string transactionFileString, string employeeFileString)
{
	ifstream transactionFile(transactionFileString);
	string dayString;
	getline(transactionFile, dayString);

	stringstream dayConverter;
	dayConverter << dayString;
	int day;
	dayConverter >> day;

	ifstream employeeFile(employeeFileString);
	string currentTransaction;
	string currentEmployee;
	string finalOutput = "";

	getline(transactionFile, currentTransaction);
	Employee* employee = nullptr;
	if (getline(employeeFile, currentEmployee))
	{
		employee = processEmployeeLine(currentEmployee);
	}
	Transaction* transaction = processTransactionLine(currentTransaction);

	while (true)
	{
		if (HireTransaction* t = dynamic_cast<HireTransaction*>(transaction))
		{
			// Hired employees currently can't have any other transactions within the same day
			if (employee != nullptr)
			{
				finalOutput.append(employee->serialize());
				finalOutput.append("\n");
				delete employee;
			}
			employee = processHire(t, day);
			if (!getline(transactionFile, currentTransaction))
			{
				finalOutput.append(employee->serialize());
				finalOutput.append("\n");
				delete employee;
				break;
			}
			delete transaction;
			transaction = processTransactionLine(currentTransaction);
		}
		else if (employee->getID() == transaction->getEmployeeID())
		{
			processTransaction(transaction, employee, day);
			if (!getline(transactionFile, currentTransaction))
			{
				break;
			}
			delete transaction;
			transaction = processTransactionLine(currentTransaction);
			continue;
		}
		else if (employee->getID() < transaction->getEmployeeID())
		{
			getline(employeeFile, currentEmployee);
			finalOutput.append(employee->serialize());
			finalOutput.append("\n");
			delete employee;
			employee = processEmployeeLine(currentEmployee);
			continue;
		}
		else
		{
			cout << "Error processing transaction" << endl;
			throw - 1;
		}
	}

	employeeFile.close();
	transactionFile.close();
	ofstream employeeRewriteFile(employeeFileString);
	employeeRewriteFile << finalOutput;

}

void sortTransactionFile(string transactionInputFileString, string transactionOutputFileString)
{
	ifstream transactionInputFile(transactionInputFileString);
	string day;
	getline(transactionInputFile, day);
	string transactionString;

	TransactionList transactionList;

	while (getline(transactionInputFile, transactionString))
	{
		Transaction* t = processTransactionLine(transactionString);
		transactionList.addTransaction(t);
	}

	ofstream transactionOutputFile(transactionOutputFileString);
	transactionOutputFile << day;

	while (!transactionList.isEmpty())
	{
		Transaction* transaction = transactionList.removeTransaction();
		transactionString = transaction->getTransactionType();
		transactionString.append(",");
		transactionString.append(to_string(transaction->getEmployeeID()));

		if (HireTransaction* t = dynamic_cast<HireTransaction*>(transaction))
		{

			transactionString.append(",");
			// name, employee type, pay rate
			transactionString.append(t->getName());
			transactionString.append(",");
			transactionString.append(t->getEmployeeType());
			transactionString.append(",");
			transactionString.append(to_string(t->getPayRate()));
		}
		else if (HoursTransaction* t = dynamic_cast<HoursTransaction*>(transaction))
		{
			transactionString.append(",");
			transactionString.append(to_string(t->getHoursWorked()));
		}
		else if (PiecesTransaction* t = dynamic_cast<PiecesTransaction*>(transaction))
		{
			transactionString.append(",");
			transactionString.append(to_string(t->getItemsProduced()));
		}
		else if (SalesTransaction* t = dynamic_cast<SalesTransaction*>(transaction))
		{
			transactionString.append(",");
			transactionString.append(to_string(t->getSalesAmount()));
		}
		else if (TerminationTransaction* t = dynamic_cast<TerminationTransaction*>(transaction))
		{
			// No other append necessary
		}
		else
		{
			// TODO: Process error
			cout << "Error processing transaction" << endl;
			throw - 1;
		}

		transactionOutputFile << endl << transactionString;

		cout << "Done processing file";
	}

	transactionInputFile.close();
	transactionOutputFile.close();
}

void printPayroll(string employeeFile, string payrollOutputFile)
{
	ifstream inputFile(employeeFile);
	ofstream outputFile(payrollOutputFile);
	string line;
	while (getline(inputFile, line))
	{
		Employee* employee = processEmployeeLine(line);
		string payrollOutput = employee->payroll();
		outputFile << payrollOutput << endl;
	}

	inputFile.close();
	outputFile.close();
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

	cout << "Finished";

	return 0;
}