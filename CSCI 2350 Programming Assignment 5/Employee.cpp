#include "Employee.h"

Employee::Employee() : id(0), name(""), employeeType(""), payRate(0.0), hiredDate(0), fired(false) {}

Employee::~Employee()
{
}

void Employee::hire(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired)
{
    id = employeeID;
    name = employeeName;
    employeeType = type;
    payRate = employeePayRate;
    hiredDate = employeeDateHired;
}

void Employee::termination()
{
    fired = true;
}

Salary::Salary() : dayFired(0) {}

Salary:: ~Salary()
{

}

void Salary::payroll()
{

}

void Salary::termination(int day)
{
    fired = true;
    dayFired = day;
}

Hourly::Hourly()
{

}

Hourly:: ~Hourly()
{

}

void Hourly::payroll()
{

}

Piecework::Piecework() : itemsProduced(0) {}

Piecework:: ~Piecework()
{

}

void Piecework::payroll()
{
    double pay = payRate * itemsProduced;
    
}

void Piecework::addPieces(int newItems)
{
    itemsProduced = itemsProduced + newItems;
}

Commission::Commission()
{

}

Commission:: ~Commission()
{

}

void Commission::payroll()
{

}

void Commission::addSales(double newSales)
{
    if (newSales > 100000)
    {
        newSales = newSales * 1.015;
    }
    else if (newSales > 10000)
    {
        newSales = newSales * 1.01;
    }
    salesAmount = salesAmount + newSales;
}
