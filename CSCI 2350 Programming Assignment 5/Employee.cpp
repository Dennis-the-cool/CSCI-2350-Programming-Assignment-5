#include "Employee.h"

Employee::Employee() : id(0), name(""), employeeType(""), payRate(0.0), hiredDate(0), dayFired(0) {}

Employee:: ~Employee() {}

void Employee:: termination(int date)
{
    dayFired = date;
}

Salary:: Salary(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired)
{
    id = employeeID;
    name = employeeName;
    employeeType = type;
    payRate = employeePayRate;
    hiredDate = employeeDateHired;
}

Salary:: ~Salary() {}

string Salary:: payroll()
{
    double totalPay;
    
    if(hiredDate == 1 && dayFired == 0)
    {
        totalPay = payRate;
    }
    else
    {
        double dailyPay = payRate/30;
        totalPay = dailyPay * (dayFired - hiredDate + 1);
    }

    stringstream converter;
    
    converter << id;
    string idString = converter.str();

    converter.str(string());

    converter << totalPay;
    string totalPayString = converter.str();

    string payOutput = idString + "," + name + "," + totalPayString;

    return payOutput;
}

Hourly:: Hourly(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired): lastDayWorked(0), daysInRowWorked(0), regularHours(0), overtimeHours(0), doubleHours(0), tripleHours(0) 
{
    id = employeeID;
    name = employeeName;
    employeeType = type;
    payRate = employeePayRate;
    hiredDate = employeeDateHired;
}

Hourly:: ~Hourly() {}

string Hourly:: payroll()
{
  double regularHoursPay = regularHours * payRate;
  double overtimeHoursPay = overtimeHours * payRate * 1.5;
  double doubleHoursPay = doubleHours * payRate * 2.0;
  double tripleHoursPay = tripleHours * payRate * 3.0;
  
  double totalPay = regularHoursPay + overtimeHoursPay + doubleHoursPay + tripleHoursPay;

  stringstream convertTotalPay;
  
  string output;

  convertTotalPay << totalPay;
  convertTotalPay >> output;

  return output;
}

void Hourly:: addHours(double hoursAdd, int day)
{
    if(day == (lastDayWorked + 1))
    {
        daysInRowWorked++;
    }    
    else
    {
        daysInRowWorked = 1;
    }
    
    lastDayWorked = day;

    if(hoursAdd > 8 && daysInRowWorked < 6)
    {
        overtimeHours += hoursAdd - 8;
        regularHours += 8;
    }
    else if(hoursAdd <= 8 && daysInRowWorked >= 6)
    {
        doubleHours += hoursAdd;
    }
    else if(hoursAdd > 8 && daysInRowWorked >= 6)
    {
        tripleHours = hoursAdd - 8;
        doubleHours += 8;
    }
    else
    {
        regularHours += hoursAdd;
    }
}

Piecework:: Piecework(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired): itemsProduced(0) 
{
    id = employeeID;
    name = employeeName;
    employeeType = type;
    payRate = employeePayRate;
    hiredDate = employeeDateHired;    
}

Piecework:: ~Piecework() {}

string Piecework::payroll()
{
    double pay = payRate * itemsProduced;

    stringstream converter;

    converter << id;
    string idString = converter.str();
    
    converter.str(string());

    converter << pay;
    string payNum = converter.str();

    string output = idString + "," + name + "," + payNum;
    return output;
}

void Piecework::addPieces(int newItems)
{
    itemsProduced = itemsProduced + newItems;
}

Commission:: Commission(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired): salesAmount(0), mediumSalesAmount(0), largeSalesAmount(0) 
{
    id = employeeID;
    name = employeeName;
    employeeType = type;
    payRate = employeePayRate;
    hiredDate = employeeDateHired;
}

Commission:: ~Commission() {}

string Commission:: payroll()
{
    double baseSalesCommission = payRate * salesAmount;
    double mediumSalesCommission = (payRate + 0.01) * mediumSalesAmount;
    double largeSalesCommission = (payRate + 0.015) * largeSalesAmount;

    double totalCommission = baseSalesCommission + mediumSalesCommission + largeSalesCommission;

    stringstream converter; 
    
    converter << id;
    string idString = converter.str();

    converter.str(string());

    converter << totalCommission;
    string totalPayString = converter.str();

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