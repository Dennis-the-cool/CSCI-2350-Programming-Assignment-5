#include "Employee.h"
#include "Hourly.h"

Employee::Employee() : id(0), name(""), employeeType(""), payRate(0.0), hiredDate(0), fired(false) {}

Employee::~Employee()
{
}

void Employee::termination()
{
	fired = true;
}

Hourly::Hourly() : lastDayWorked(0), daysInRowWorked(0) {}

Hourly::~Hourly()
{
}
