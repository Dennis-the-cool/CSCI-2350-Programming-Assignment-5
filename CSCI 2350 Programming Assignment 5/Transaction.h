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
	virtual void updateValues() = 0;
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
	void updateValues();
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
	void updateValues();
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
	void updateValues();
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
	void updateValues();
};
class TerminationTransaction : public Transaction
{
public:
	TerminationTransaction();
	~TerminationTransaction();
	void updateValues();
};