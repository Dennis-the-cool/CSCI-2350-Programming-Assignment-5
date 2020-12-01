#include "Employee.h"

Employee::Employee(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired)
    : id(employeeID), name(employeeName), type(employeeType), payRate(employeePayRate), hiredDate(employeeDateHired), firedDate(0)
{}

Employee::Employee(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired, int employeeDateFired)
    : id(employeeID), name(employeeName), type(employeeType), payRate(employeePayRate), hiredDate(employeeDateHired), firedDate(employeeDateFired)
{}

Employee:: ~Employee() {}

void Employee::termination(int date)
{
    firedDate = date;
}

int Employee::getID()
{
    return id;
}

Salary::Salary(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired)
    : Employee(employeeID, employeeName, employeeType, employeePayRate, employeeDateHired)
{}

Salary::Salary(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired, int employeeDateFired)
    : Employee(employeeID, employeeName, employeeType, employeePayRate, employeeDateHired, employeeDateFired)
{}

Salary:: ~Salary() {}

string Salary::payroll()
{
    double totalPay;

    if (hiredDate == 1 && firedDate == 0)
    {
        totalPay = payRate;
    }
    else
    {
        double dailyPay = payRate / 30;
        totalPay = dailyPay * (firedDate - hiredDate + 1);
    }

    string payOutput = to_string(id) + "," + name + "," + to_string(totalPay);

    return payOutput;
}

string Salary::serialize()
{
    string serialized = "";
    serialized.append(to_string(id));
    serialized.append(",");
    serialized.append(name);
    serialized.append(",");
    serialized.append(type);
    serialized.append(",");
    serialized.append(to_string(payRate));
    serialized.append(",");
    serialized.append(to_string(hiredDate));
    serialized.append(",");
    serialized.append(to_string(firedDate));

    return serialized;
}

Hourly::Hourly(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired)
    : Employee(employeeID, employeeName, employeeType, employeePayRate, employeeDateHired),
    lastDayWorked(-1), daysInRowWorked(0), regularHours(0), overtimeHours(0), doubleHours(0), tripleHours(0)
{}

Hourly::Hourly(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired, int employeeDateFired, int lastDay, int inRow, double regular, double overtime, double doubleH, double triple)
    : Employee(employeeID, employeeName, employeeType, employeePayRate, employeeDateHired, employeeDateFired),
    lastDayWorked(lastDay), daysInRowWorked(inRow), regularHours(regular), overtimeHours(overtime), doubleHours(doubleH), tripleHours(triple)
{}

Hourly:: ~Hourly() {}

string Hourly::payroll()
{
    double regularHoursPay = regularHours * payRate;
    double overtimeHoursPay = overtimeHours * payRate * 1.5;
    double doubleHoursPay = doubleHours * payRate * 2.0;
    double tripleHoursPay = tripleHours * payRate * 3.0;

    double totalPay = regularHoursPay + overtimeHoursPay + doubleHoursPay + tripleHoursPay;

    string output = to_string(id) + "," + name + "," + to_string(totalPay);

    return output;
}

void Hourly::addHours(double hoursAdd, int day)
{
    if (day == (lastDayWorked + 1))
    {
        daysInRowWorked++;
    }
    else
    {
        daysInRowWorked = 1;
    }

    lastDayWorked = day;

    if (hoursAdd > 8 && daysInRowWorked < 6)
    {
        overtimeHours += hoursAdd - 8;
        regularHours += 8;
    }
    else if (hoursAdd <= 8 && daysInRowWorked >= 6)
    {
        doubleHours += hoursAdd;
    }
    else if (hoursAdd > 8 && daysInRowWorked >= 6)
    {
        tripleHours = hoursAdd - 8;
        doubleHours += 8;
    }
    else
    {
        regularHours += hoursAdd;
    }
}

string Hourly::serialize()
{
    string serialized = "";
    serialized.append(to_string(id));
    serialized.append(",");
    serialized.append(name);
    serialized.append(",");
    serialized.append(type);
    serialized.append(",");
    serialized.append(to_string(payRate));
    serialized.append(",");
    serialized.append(to_string(hiredDate));
    serialized.append(",");
    serialized.append(to_string(firedDate));

    serialized.append(",");
    serialized.append(to_string(lastDayWorked));
    serialized.append(",");
    serialized.append(to_string(daysInRowWorked));
    serialized.append(",");
    serialized.append(to_string(regularHours));
    serialized.append(",");
    serialized.append(to_string(overtimeHours));
    serialized.append(",");
    serialized.append(to_string(doubleHours));
    serialized.append(",");
    serialized.append(to_string(tripleHours));

    return serialized;
}

Piecework::Piecework(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired)
    : Employee(employeeID, employeeName, employeeType, employeePayRate, employeeDateHired),
    itemsProduced(0)
{}

Piecework::Piecework(int employeeID, string employeeName, string employeeType, double employeePayRate, int employeeDateHired, int employeeDateFired, int employeeItemsProduced)
    : Employee(employeeID, employeeName, employeeType, employeePayRate, employeeDateHired, employeeDateFired),
    itemsProduced(employeeItemsProduced)
{}

Piecework:: ~Piecework() {}

string Piecework::payroll()
{
    double pay = payRate * itemsProduced;

    string output = to_string(id) + "," + name + "," + to_string(pay);
    return output;
}

void Piecework::addPieces(int newItems)
{
    itemsProduced = itemsProduced + newItems;
}

string Piecework::serialize()
{
    string serialized = "";
    serialized.append(to_string(id));
    serialized.append(",");
    serialized.append(name);
    serialized.append(",");
    serialized.append(type);
    serialized.append(",");
    serialized.append(to_string(payRate));
    serialized.append(",");
    serialized.append(to_string(hiredDate));
    serialized.append(",");
    serialized.append(to_string(firedDate));

    serialized.append(",");
    serialized.append(to_string(itemsProduced));

    return serialized;
}

Commission::Commission(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired)
    : Employee(employeeID, employeeName, type, employeePayRate, employeeDateHired),
    salesAmount(0), mediumSalesAmount(0), largeSalesAmount(0)
{}

Commission::Commission(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired, int employeeDateFired, double sales, double mediumSales, double largeSales)
    : Employee(employeeID, employeeName, type, employeePayRate, employeeDateHired, employeeDateFired),
    salesAmount(sales), mediumSalesAmount(mediumSales), largeSalesAmount(largeSales)
{}

Commission:: ~Commission() {}

string Commission::payroll()
{
    double baseSalesCommission = payRate * salesAmount;
    double mediumSalesCommission = (payRate + 0.01) * mediumSalesAmount;
    double largeSalesCommission = (payRate + 0.015) * largeSalesAmount;

    double totalCommission = baseSalesCommission + mediumSalesCommission + largeSalesCommission;

    string payOutput = to_string(id) + "," + name + "," + to_string(totalCommission);
    return payOutput;
}

void Commission::addSales(double newSales)
{
    if (newSales > 100000)
    {
        largeSalesAmount += newSales;
    }
    else if (newSales > 10000)
    {
        mediumSalesAmount += newSales;
    }
    else
    {
        salesAmount += newSales;
    }
}

string Commission::serialize()
{
    string serialized = "";
    serialized.append(to_string(id));
    serialized.append(",");
    serialized.append(name);
    serialized.append(",");
    serialized.append(type);
    serialized.append(",");
    serialized.append(to_string(payRate));
    serialized.append(",");
    serialized.append(to_string(hiredDate));
    serialized.append(",");
    serialized.append(to_string(firedDate));

    serialized.append(",");
    serialized.append(to_string(salesAmount));
    serialized.append(",");
    serialized.append(to_string(mediumSalesAmount));
    serialized.append(",");
    serialized.append(to_string(largeSalesAmount));

    return serialized;
}
