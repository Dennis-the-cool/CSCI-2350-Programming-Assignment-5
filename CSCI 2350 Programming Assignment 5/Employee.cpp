#include "Employee.h"
#include "Hourly.h"

Employee::Employee() : id(0), name(""), employeeType(""), payRate(0.0), hiredDate(0), fired(false) {}

Employee::~Employee()
{
}

Hourly::Hourly() : lastDayWorked(0), daysInRowWorked(0) {}

Hourly::~Hourly()
{
}
