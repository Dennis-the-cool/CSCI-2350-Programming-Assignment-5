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
    double totalPay;
    
    if(hiredDate == 1 && fired == false)
    {
        totalPay = payRate;
    }
    else
    {
        double dailyPay = payRate/30;
        totalPay = dailyPay * (dayFired - hiredDate + 1);
    }

    char* separate = ",";
    
    // I think that opening this file in append, rather than write, may help write on a newline each time.
    FILE* outputFile = fopen("outputFile.txt", "a");
    
    fwrite(&id, sizeof(int), 1, outputFile);
    fwrite(separate, sizeof(char), 1, outputFile);
    fwrite(&name, sizeof(string), 1, outputFile);
    fwrite(separate, sizeof(char), 1, outputFile);
    fwrite(&totalPay, sizeof(double), 1, outputFile);

    fclose(outputFile);    
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