#pragma once
#include <string>
using namespace std;

class Transaction
{
protected:
	string transactionType;
	int employeeID;
public:
	Transaction();
	~Transaction();
	void setTransactionType(string);
	string getTransactionType();
	void setEmployeeID(int);
	int getEmployeeID();
};
class HireTransaction : public Transaction
{
private:
	string name;
	string employeeType;
	double payRate;
public:
	HireTransaction();
	~HireTransaction();
	void setName(string);
	string getName();
	void setEmployeeType(string);
	string getEmployeeType();
	void setPayRate(double);
	double getPayRate();
};
class HoursTransaction : public Transaction
{
private:
	double hoursWorked;
public:
	HoursTransaction();
	~HoursTransaction();
	void setHoursWorked(double);
	double getHoursWorked();
};
class PiecesTransaction : public Transaction
{
private:
	int itemsProduced;
public:
	PiecesTransaction();
	~PiecesTransaction();
	void setItemsProduced(int);
	int getItemsProduced();
};
class SalesTransaction : public Transaction
{
private:
	double salesAmount;
public:
	SalesTransaction();
	~SalesTransaction();
	void setSalesAmount(double);
	double getSalesAmount();
};
class TerminationTransaction : public Transaction
{
public:
	TerminationTransaction();
	~TerminationTransaction();
};