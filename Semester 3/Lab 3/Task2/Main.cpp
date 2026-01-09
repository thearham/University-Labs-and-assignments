#include "Employee.h"
#include "Function_definitions.h"

int main(){
    Employee employee1(1, "arham", "01/01/2023", "Joined");
    Employee employee2(2, "ali", "02/02/2023", "Joined");
    Employee employee3(3, "zayn", "03/03/2023", "Left");
    Employee employee4(4, "ryan", "04/04/2023", "Joined");

    Employee employees[] = {employee1, employee2, employee3,employee4};

    for (int i = 0; i < 4; i++) {
        cout << "Employee code: " << employees[i].getEmployee_code() << endl;
        cout << "Employee name: " << employees[i].getemployee_name() << endl;
        cout << "Date of joining: " << employees[i].getemployee_dateOfJoining() << endl;
        cout << "Employee status: " << employees[i].getemployee_status() << endl;
        cout << endl;
    }

    
    employee1.set_status("Left");
    employee2.set_status("Left");

    cout << "Updated employee status:" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Employee code: " << employees[i].getEmployee_code() << endl;
        cout << "Employee name: " << employees[i].getemployee_name() << endl;
        cout << "Date of joining: " << employees[i].getemployee_dateOfJoining() << endl;
        cout << "Employee status: " << employees[i].getemployee_status() << endl;
        cout << endl;
    }

    return 0;
}