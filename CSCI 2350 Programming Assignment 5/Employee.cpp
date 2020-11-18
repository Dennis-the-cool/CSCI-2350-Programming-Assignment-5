#include "Employee.h"

Employee::Employee() : id(0), name(""), employeeType(""), payRate(0.0), hiredDate(0), dayFired(0) {}

Employee::Employee(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired)
{
    id = employeeID;
    name = employeeName;
    employeeType = type;
    payRate = employeePayRate;
    hiredDate = employeeDateHired;
}

Employee::~Employee()
{
}

void Employee::termination(int day)
{
    dayFired = day;
}

Salary::Salary() {}

Salary:: ~Salary()
{

}

string Salary::payroll()
{
    double totalPay;

    if (hiredDate == 1 && dayFired == 0)
    {
        totalPay = payRate;
    }
    else
    {
        double dailyPay = payRate / 30;
        totalPay = dailyPay * (dayFired - hiredDate + 1);
    }

    stringstream converter;

    string idString;
    converter << id;
    converter >> idString;

    string totalPayString;
    converter << totalPay;
    converter >> totalPayString;

    string payOutput = idString + "," + name + "," + totalPayString;

    return payOutput;
}

Hourly::Hourly() : lastDayWorked(0), daysInRowWorked(0), regularHours(0), overtimeHours(0), doubleHours(0), tripleHours(0){}

Hourly:: ~Hourly()
{

}

string Hourly::payroll()
{

}

void Hourly::addHours(int, double)
{

}

Piecework::Piecework() : itemsProduced(0) {}

Piecework:: ~Piecework()
{

}

string Piecework::payroll()
{
    double pay = payRate * itemsProduced;
    
    stringstream converter;

    string idString;
    converter << id;
    converter >> idString;

    string payNum;
    converter << pay;
    converter >> payNum;

    string output = id + "," + name + "," + payNum;
    
    return output;
}

void Piecework::addPieces(int newItems)
{
    itemsProduced = itemsProduced + newItems;
}

Commission::Commission() : salesAmount(0), mediumSalesAmount(0), largeSalesAmount(0) {}

Commission:: ~Commission()
{

}

string Commission::payroll()
{
    double baseSalesCommission = payRate * salesAmount;
    double mediumSalesCommission = (payRate + 0.01) * mediumSalesAmount;
    double largeSalesCommission = (payRate + 0.015) * largeSalesAmount;

    double totalCommission = baseSalesCommission + mediumSalesCommission + largeSalesCommission;

    stringstream converter;

    string idString;
    converter << id;
    converter >> idString;

    string totalPayString;
    converter << totalCommission;
    converter >> totalPayString;

    string payOutput = idString + "," + name + "," + totalPayString;
    return payOutput;
}

void Commission::addSales(double newSales)
{
    if (newSales > 100000)
    {
        largeSalesAmount = largeSalesAmount + newSales;
    }
    else if (newSales > 10000)
    {
        mediumSalesAmount = mediumSalesAmount + newSales;
    }
    else
    {
        salesAmount = salesAmount + newSales;
    }
}
