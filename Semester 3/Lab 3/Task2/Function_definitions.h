#pragma once
#include "Employee.h"

Employee::Employee(){
    employee_code = 123;
    employee_dateOfJoining = "01/01/2023";
    employee_name =   " ";
    employee_status = "None";
}

//setters: 
Employee::Employee(int employeeCode, string employeeName, string DateOfJoining, string employeeStatus){
    employee_code = employeeCode;
    employee_dateOfJoining = DateOfJoining;
    employee_name = employeeName;
    employee_status = employeeStatus;
}
void Employee::set_status(string Status){
    if (Status == "Joined" || Status == "Left"){
        employee_status = Status;
    } else {
        cout << "Invalid status. Please enter either Joined or Left." << endl;
    }
}

//getters:
int Employee::getEmployee_code(){
    return employee_code;
}
string Employee::getemployee_name(){
    return employee_name;
}
string Employee::getemployee_dateOfJoining(){
    return employee_dateOfJoining;
}
string Employee::getemployee_status(){
    return employee_status;
}