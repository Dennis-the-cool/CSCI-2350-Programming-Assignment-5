#include "Employee.h"

Employee::Employee() : id(0), name(""), employeeType(""), payRate(0.0), hiredDate(0), fired(false) {}

Employee::~Employee()
{
}

void Employee:: hire(int employeeID, string employeeName, string type, double employeePayRate, int employeeDateHired)
{
    id = employeeID;
    name = employeeName;
    employeeType = type;
    payRate = employeePayRate;
    hiredDate = employeeDateHired; 
}

void Employee:: termination()
{

}

Salary:: Salary()
{

}

Salary:: ~Salary()
{

}

void Salary:: payroll()
{

}

Hourly:: Hourly()
{

}

Hourly:: ~Hourly()
{

}

void Hourly:: payroll()
{

}

Piecework:: Piecework()
{

}

Piecework:: ~Piecework()
{

}

void Piecework:: payroll()
{

}

Commission:: Commission()
{

}

Commission:: ~Commission()
{

}

void Commission:: payroll()
{

}