#pragma once
#include <iostream>
using namespace std;

class Employee
{
private:
    int employee_code;
    string employee_name;
    string employee_dateOfJoining;
    string employee_status;
public:
    Employee();
    Employee(int, string, string, string);
    void set_status(string);

    int getEmployee_code();
    string getemployee_name();
    string getemployee_dateOfJoining();
    string getemployee_status();
};



