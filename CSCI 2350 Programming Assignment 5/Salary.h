#pragma once
#include <string>
using namespace std; 

class Salary
{
private:
    int dayFired;
public:
    Salary();
    ~Salary();
    void payroll();
    void hire(int, string, string, double, int);
    void termination();
};