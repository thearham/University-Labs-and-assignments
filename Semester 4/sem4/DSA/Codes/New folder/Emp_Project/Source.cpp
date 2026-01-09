#include "interfaces.h"
using namespace std;

int main() {
    Admin& admin = Admin::getInstance();
    admin.set_name("");
    admin.set_password("");
    admin.read_departments();
    admin.read_managers_for_each_dept();
    admin.read_employees_for_each_manager();
    system("CLS");
    choose_interface(admin);

    system("pause");
}