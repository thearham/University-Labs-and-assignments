#pragma once
#include "data.h"
#include <conio.h>
#include <limits>

void choose_interface(Admin& admin);
void admin_login(Admin& admin);
void manager_login(Department* departments);
void employee_login(Department* departments);

void employee_interface(Employee* employee);
void manager_interface(Manager* manager);
void admin_interface(Admin& admin);

void admin_login(Admin& admin) {
    string name;
    string password;
    do {
        system("CLS");
        std::cout << "ADMIN LOGIN" << endl;
        password = "";
        std::cout << "Enter name(-1 to return): ";
        getline(std::cin >> ws, name);
        if (name == "-1") {
            system("CLS");
            std::cout << "Invalid Login!" << endl;
            return;
        }
        std::cout << "Enter Password: ";
        char ch;
        while ((ch = _getch()) != '\r') {
            std::cout << '*';
            password += ch;
        }
        std::cout << endl;
    } while (name != admin.get_name() || password != admin.get_password());
    std::cout << "Logged in!" << endl;
    admin_interface(admin);
}

void manager_login(Department* departments) {
    std::cout << "MANAGER LOGIN" << endl;
    while (true) {
        string dept_name;
        std::cout << "Your Department Name(-1 to return): ";
        getline(std::cin >> ws, dept_name);
        if (dept_name == "-1") {
            system("CLS");
            return;
        }
        Department* dept = departments;
        if (dept == nullptr) {
            std::cout << "Department does not exist!" << endl;
        }
        else {
            bool dept_found = false;
            while (dept != nullptr) {
                if (dept->get_name() == dept_name) {
                    dept_found = true;
                    break;
                }
                dept = dept->get_next();
            }

            if (dept_found) {
                string name;
                int id;
                std::cout << "Enter Name(-1 to return): ";
                getline(std::cin >> ws, name);
                if (name == "-1") {
                    system("CLS");
                    return;
                }
                std::cout << "Enter ID: ";
                std::cin >> id;
                if (std::cin.fail()) {
                    system("CLS");
                    cerr << "Invalid ID input!" << endl;
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                bool manager_found = false;
                Manager* manager = dept->get_managers();
                if (manager == nullptr) {
                    system("CLS");
                    std::cout << "Manager Not Found!" << endl;
                }
                else {
                    while (manager != nullptr) {
                        if (manager->get_name() == name && manager->get_id() == id) {
                            manager_found = true;
                            std::cout << "Manager Found" << endl;
                            break;
                        }
                        manager = manager->get_next();
                    }
                }

                if (manager_found) {
                    system("CLS");
                    std::cout << "Logged in!" << endl;
                    manager_interface(manager);
                    return;
                }
                else {
                    system("CLS");
                    std::cout << "Manager not found in department!" << endl;
                }
            }
            else {
                system("CLS");
                std::cout << "Department does not exist!" << endl;
            }
        }
    }
}


void employee_login(Department* departments) {
    std::cout << "EMPLOYEE LOGIN" << endl;
    while (true) {
        string dept_name;
        std::cout << "Your Department Name(-1 to return): ";
        getline(std::cin >> ws, dept_name);
        if (dept_name == "-1") {
            system("CLS");
            return;
        }
        Department* dept = departments;
        if (dept == nullptr) {
            std::cout << "Department does not exist!" << endl;
        }
        else {
            bool dept_found = false;
            while (dept != nullptr) {
                if (dept->get_name() == dept_name) {
                    dept_found = true;
                    break;
                }
                dept = dept->get_next();
            }

            if (dept_found) {
                int man_id;
                std::cout << "Enter ID of your Manager(-1 to return): ";
                std::cin >> man_id;
                if (std::cin.fail()) {
                    system("CLS");
                    cerr << "Invalid ID input!" << endl;
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (man_id == -1) {
                    system("CLS");
                    return;
                }
                bool manager_found = false;
                Manager* manager = dept->get_managers();
                if (manager == nullptr) {
                    std::cout << "No Managers in this Department!" << endl;
                }
                else {
                    while (manager != nullptr) {
                        if (manager->get_id() == man_id) {
                            manager_found = true;
                            std::cout << "Manager Found" << endl;
                            break;
                        }
                        manager = manager->get_next();
                    }
                }

                if (manager_found) {
                    string emp_name;
                    int emp_id;
                    bool emp_found = false;
                    std::cout << "Enter Your Name(-1 to return): ";
                    getline(std::cin >> ws, emp_name);
                    if (emp_name == "-1") {
                        system("CLS");
                        return;
                    }
                    std::cout << "Enter Your ID: ";
                    std::cin >> emp_id;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    Employee* employee = manager->get_employees();
                    while (employee != nullptr) {
                        if (employee->get_id() == emp_id && employee->get_name() == emp_name) {
                            emp_found = true;
                            std::cout << "Emp found!" << endl;
                            break;
                        }
                        employee = employee->get_next();
                    }

                    if (emp_found) {
                        system("CLS");
                        std::cout << "Logged in!" << endl;
                        std::cout << "Department Name: " << dept->get_name() << endl;
                        std::cout << "Department ID: " << dept->get_id() << endl;
                        std::cout << " - Manager Name: " << manager->get_name() << endl;
                        std::cout << " - Manager ID: " << manager->get_id() << endl;
                        employee_interface(employee);
                        return;
                    }
                    else {
                        system("CLS");
                        std::cout << "Employee not found under this manager!" << endl;
                    }
                }
                else {
                    system("CLS");
                    std::cout << "Manager not found in department!" << endl;
                }
            }
            else {
                system("CLS");
                std::cout << "Department does not exist!" << endl;
            }
        }
    }
}

void employee_interface(Employee* employee) {
    system("CLS");
    char choice;
    std::cout << "EMPLOYEE INTERFACE" << endl;
    employee->display();
    std::cout << "Press any key to return...";
    std::cin >> choice;
}

void manager_interface(Manager* manager) {
    system("CLS");
    char choice, wait;
    int ID;
    string name;
    double salary;
    do {
        std::cout << "Name: " << manager->get_name() << endl;
        std::cout << "ID: " << manager->get_id() << endl;
        std::cout << "Salary: " << manager->get_salary() << endl << endl;

        std::cout << "MANAGER INTERFACE" << endl;
        std::cout << "1. Add Employee " << endl;
        std::cout << "2. Remove Employee " << endl;
        std::cout << "3. Search Employee " << endl;
        std::cout << "4. Sort Employees " << endl;
        std::cout << "5. Update Employee " << endl;
        std::cout << "6. Display Employees " << endl;
        std::cout << "Press - to return..." << endl << endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            system("CLS");
            std::cout << "ADDING EMPLOYEE" << endl;
            std::cout << "Enter Name of new Employee: ";
            getline(std::cin >> ws, name);
            std::cout << "Enter ID of new Employee: ";
            std::cin >> ID;
            if (std::cin.fail()) {
                system("CLS");
                cerr << "Invalid ID input!" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            std::cout << "Enter Salary of new Employee: ";
            std::cin >> salary;
            if (std::cin.fail()) {
                system("CLS");
                cerr << "Invalid Salary input!" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            manager->add_employee(name, ID, salary);
            std::cout << "Press any key to continue...";
            std::cin >> wait;
            system("CLS");
            break;
        case '2':
            system("CLS");
            std::cout << "REMOVING EMPLOYEE" << endl;
            std::cout << "Enter Name of Employee: ";
            getline(std::cin >> ws, name);
            std::cout << "Enter ID of Employee: ";
            std::cin >> ID;
            if (std::cin.fail()) {
                system("CLS");
                cerr << "Invalid ID input!" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            manager->delete_employee(name, ID);
            std::cout << "Press any key to continue...";
            std::cin >> wait;
            system("CLS");
            break;
        case '3':
            system("CLS");
            std::cout << "SEARCHING EMPLOYEE" << endl;
            std::cout << "Enter Name of Employee: ";
            getline(std::cin >> ws, name);
            std::cout << "Enter ID of Employee: ";
            std::cin >> ID;
            if (std::cin.fail()) {
                system("CLS");
                cerr << "Invalid ID input!" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            manager->search_employee(name, ID);
            std::cout << "Press any key to continue...";
            std::cin >> wait;
            system("CLS");
            break;
        case '4':
            system("CLS");
            char option;
            std::cout << "SORT EMPLOYEES" << endl;
            std::cout << "1. According to Name" << endl;
            std::cout << "2. According to ID" << endl;
            std::cout << "3. According to Salary" << endl;
            std::cin >> option;
            switch (option) {
            case '1':
                manager->sort_by_name();
                std::cout << "Sorted Successfully!" << endl;
                break;
            case '2':
                manager->sort_by_id();
                std::cout << "Sorted Successfully!" << endl;
                break;
            case '3':
                manager->sort_by_salary();
                std::cout << "Sorted Successfully!" << endl;
                break;
            default:
                std::cout << "Invalid choice!" << endl;
                break;
            }
            std::cout << "Press any key to continue...";
            std::cin >> wait;
            system("CLS");
            break;
        case '5':
            system("CLS");
            std::cout << "Update EMPLOYEE" << endl;
            std::cout << "Enter Name of Employee: ";
            getline(std::cin >> ws, name);
            std::cout << "Enter ID of Employee: ";
            std::cin >> ID;
            if (std::cin.fail()) {
                system("CLS");
                cerr << "Invalid ID input!" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            manager->update_employee(name, ID);
            std::cout << "Press any key to continue...";
            std::cin >> wait;
            system("CLS");
            break;
        case '6':
            system("CLS");
            manager->display_employees();
            std::cout << "Press any key to continue...";
            std::cin >> wait;
            system("CLS");
            break;
        case '-':
            system("CLS");
            return;
            break;
        default:
            system("CLS");
            std::cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != '-');
}

void admin_interface(Admin& admin) {
    system("CLS");
    char option;
    char wait;
    do {
        std::cout << "ADMIN INTERFACE" << endl;
        std::cout << "1. Manage Departments" << endl;
        std::cout << "2. Manage Managers" << endl;
        std::cout << "3. Manage Employees" << endl;
        std::cout << "Press - to return..." << endl << endl;
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
        case '1': // Manage Departments
        {
            system("CLS");
            char deptChoice;
            do {
                std::cout << "DEPARTMENT MANAGEMENT" << endl;
                std::cout << "1. Add Department" << endl;
                std::cout << "2. Remove Department" << endl;
                std::cout << "3. Search Department" << endl;
                std::cout << "4. Update Departments" << endl;
                std::cout << "5. Sort Department" << endl;
                std::cout << "6. Display Departments" << endl;
                std::cout << "Press - to return..." << endl << endl;
                std::cout << "Enter your choice: ";
                std::cin >> deptChoice;

                switch (deptChoice) {
                case '1': // Add Department
                {
                    system("CLS");
                    std::cout << "ADD DEPARMENT" << endl;
                    string deptName;
                    int deptID;
                    std::cout << "Enter Department Name(-1 to return): ";
                    getline(std::cin >> ws, deptName);
                    if (deptName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Department ID: ";
                    std::cin >> deptID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    if (admin.departmentExists(deptName, deptID)) {
                        std::cout << "Department with the same name or ID already exists!" << endl;
                        std::cout << "Press any key to continue...";
                        std::cin >> wait;
                        break;
                    }
                    admin.add_department(deptName, deptID);
                    std::cout << "Department added successfully!" << endl;
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '2': // Remove Department
                {
                    system("CLS");
                    std::cout << "REMOVE DEPARMENT" << endl;
                    string deptName;
                    int deptID;
                    std::cout << "Enter Department Name(-1 to return): ";
                    getline(std::cin >> ws, deptName);
                    if (deptName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Department ID: ";
                    std::cin >> deptID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    if (admin.departmentExists(deptName, deptID)) {
                        admin.delete_department(deptName, deptID);
                        std::cout << "Department removed successfully!" << endl;
                    }
                    else {
                        std::cout << "Department does not exist!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '3': // Search Department
                {
                    system("CLS");
                    std::cout << "SEARCH DEPARMENT" << endl;
                    string deptName;
                    int deptID;
                    bool found = false;
                    std::cout << "Enter Department Name(-1 to return): ";
                    getline(std::cin >> ws, deptName);
                    if (deptName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Department ID: ";
                    std::cin >> deptID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    Department* node = admin.get_departments();
                    while (node != nullptr) {
                        if (node->get_name() == deptName && node->get_id() == deptID) {
                            found = true;
                            break;
                        }
                        node = node->get_next();
                    }

                    if (found) {
                        node->display();
                        node->display_managers();
                    }
                    else {
                        cout << "Department does not exist!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '4': // Update Department
                {
                    system("CLS");
                    std::cout << "UPDATE DEPARMENT" << endl;
                    string deptName;
                    int deptID;
                    bool found = false;
                    std::cout << "Enter Department Name(-1 to return): ";
                    getline(std::cin >> ws, deptName);
                    if (deptName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Department ID: ";
                    std::cin >> deptID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    Department* node = admin.get_departments();
                    while (node != nullptr) {
                        if (node->get_name() == deptName && node->get_id() == deptID) {
                            found = true;
                            break;
                        }
                        node = node->get_next();
                    }

                    if (found) {
                        node->display();
                        cout << "Enter new Name for department: ";
                        getline(std::cin >> ws, deptName);
                        cout << "Enter new ID: ";
                        cin >> deptID;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid ID input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        admin.delete_dept_from_file(node);
                        node->set_name(deptName);
                        node->set_id(deptID);
                        Manager* manager = node->get_managers();
                        while (manager != nullptr) {
                            node->delete_manager_from_file(manager);
                            manager->set_department_id(deptID);
                            node->write_manager(manager);
                            manager = manager->get_next();
                        }
                        admin.write_department(node);
                    }
                    else {
                        cout << "Department does not exist!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '5': // Sort Department
                {
                    system("CLS");
                    char option;
                    do {
                        std::cout << "SORT DEPARMENTS" << endl;
                        std::cout << "1. According to Name" << endl;
                        std::cout << "2. According to ID" << endl;
                        std::cout << "Press - to return..." << endl;
                        std::cin >> option;
                        switch (option) {
                        case '1':
                            admin.sort_depts_by_name();
                            std::cout << "Sorted by Name Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '2':
                            admin.sort_depts_by_id();
                            std::cout << "Sorted by ID Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '-':
                            system("CLS");
                            break;
                        default:
                            system("CLS");
                            std::cout << "Invalid choice!" << endl;
                            break;
                        }
                    } while (option != '-');
                    break;
                }
                case '6': // Display Departments
                {
                    system("CLS");
                    admin.display_departments();
                    int input; bool found = false;
                    do {

                        cout << "Enter ID of department to inspect managers(-1 to return): ";
                        cin >> input;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid ID input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        if (input == -1) {
                            system("CLS");
                            break;
                        }
                        Department* node = admin.get_departments();
                        while (node != nullptr) {
                            if (node->get_id() == input) {
                                found = true;
                                break;
                            }
                            node = node->get_next();
                        }

                        if (found) {
                            node->display_managers();
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        }
                        else {
                            cout << "Invalid ID!" << endl << endl;
                        }
                    } while (input != -1);
                    break;
                }
                case '-':
                {
                    system("CLS");
                    break;
                }
                default:
                {    system("CLS");
                std::cout << "Invalid Choice!" << endl;
                break;
                }
                }
            } while (deptChoice != '-');
            break;
        }
        case '2': // Manage Managers
        {
            system("CLS");
            string deptName;
            int deptID;
            cout << "Enter Department's name to manage its Managers : ";
            if (deptName == "-1") {
                system("CLS");
                break;
            }
            getline(std::cin >> ws, deptName);
            cout << "Enter Department's ID: ";
            cin >> deptID;
            if (std::cin.fail()) {
                system("CLS");
                cerr << "Invalid ID input!" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            char managerChoice;
            if (!admin.departmentExists(deptName, deptID)) {
                cout << "Department Does not exist!" << endl;
                cout << "Press any key to return...";
                cin >> wait;
                system("CLS");
                break;
            }

            Department* department = admin.get_departments();
            while (department != nullptr) {
                if (department->get_id() == deptID && department->get_name() == deptName) {
                    system("CLS");
                    cout << "Department Found!" << endl << endl;
                    department->display();
                    cout << endl;
                    break;
                }
                department = department->get_next();
            }

            do {
                std::cout << "MANAGER MANAGEMENT" << endl;
                std::cout << "1. Add Manager" << endl;
                std::cout << "2. Remove Manager" << endl;
                std::cout << "3. Search Manager" << endl;
                std::cout << "4. Update Manager" << endl;
                std::cout << "5. Sort Managers" << endl;
                std::cout << "6. Display Managers" << endl;
                std::cout << "Press - to return..." << endl << endl;
                std::cout << "Enter your choice: ";
                std::cin >> managerChoice;

                switch (managerChoice) {
                case '1': // Add Manager
                {
                    system("CLS");
                    std::cout << "ADD MANAGER" << endl;
                    string managerName;
                    int managerID;
                    double managerSalary;
                    std::cout << "Enter Manager Name(-1 to return): ";
                    getline(std::cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Manager ID: ";
                    std::cin >> managerID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    std::cout << "Enter Manager Salary: ";
                    std::cin >> managerSalary;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid Salary input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    if (department->managerExists(managerName, managerID)) {
                        std::cout << "Manager with the same name and ID already exists!" << endl;
                        std::cout << "Press any key to continue...";
                        std::cin >> wait;
                        system("CLS");
                        break;
                    }

                    department->add_manager(managerName, managerID, managerSalary);
                    std::cout << "Manager added successfully!" << endl;
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '2': // Remove Manager
                {
                    system("CLS");
                    std::cout << "REMOVE MANAGER" << endl;
                    string managerName;
                    int managerID;
                    std::cout << "Enter Manager Name(-1 to return): ";
                    getline(std::cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Manager ID: ";
                    std::cin >> managerID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    if (department->managerExists(managerName, managerID)) {
                        Manager* manager = department->get_managers();
                        while (manager != nullptr) {
                            if (manager->get_name() == managerName && manager->get_id() == managerID) {
                                department->delete_manager(manager->get_name(), manager->get_id(), manager->get_salary());
                                break;
                            }
                            manager = manager->get_next();
                        }
                    }
                    else {
                        std::cout << "Manager does not exist!" << endl;
                        break;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '3': // Search Manager
                {
                    system("CLS");
                    std::cout << "SEARCH MANAGER" << endl;
                    string managerName;
                    int managerID;
                    double managerSalary;
                    std::cout << "Enter Manager Name(-1 to return): ";
                    getline(std::cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Manager ID: ";
                    std::cin >> managerID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    if (department->managerExists(managerName, managerID)) {
                        Manager* manager = department->get_managers();
                        while (manager != nullptr) {
                            if (manager->get_name() == managerName && manager->get_id() == managerID) {
                                system("CLS");
                                manager->display();
                                cout << endl;
                                manager->display_employees();
                                cout << endl;
                                break;
                            }
                            manager = manager->get_next();
                        }
                    }
                    else {
                        std::cout << "Manager does not exist!" << endl;
                    }

                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '4': // Update Manager
                {
                    system("CLS");
                    std::cout << "UPDATE MANAGER" << endl;
                    string managerName;
                    int managerID;
                    double managerSalary;
                    bool found = false;
                    std::cout << "Enter Manager Name(-1 to return): ";
                    getline(std::cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Manager ID: ";
                    std::cin >> managerID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    Manager* node = department->get_managers();
                    while (node != nullptr) {
                        if (node->get_name() == managerName && node->get_id() == managerID) {
                            found = true;
                            break;
                        }
                        node = node->get_next();
                    }

                    if (found) {
                        system("CLS");
                        node->display();
                        cout << endl;
                        cout << "Enter new Name for Manager: ";
                        getline(std::cin >> ws, managerName);
                        cout << "Enter new ID: ";
                        cin >> managerID;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid ID input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        cout << "Enter new Salary: ";
                        cin >> managerSalary;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid Salary input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        department->delete_manager_from_file(node);
                        node->set_name(managerName);
                        node->set_id(managerID);
                        node->set_salary(managerSalary);
                        Employee* employee = node->get_employees();
                        while (employee != nullptr) {
                            node->delete_employee_from_file(employee);
                            employee->set_manager_ID(managerID);
                            node->write_employee(employee);
                            employee = employee->get_next();
                        }
                        department->write_manager(node);
                    }
                    else {
                        cout << "Manager does not exist!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '5': // Sort Managers
                {
                    system("CLS");
                    char option;
                    do {
                        std::cout << "SORT MANAGERS" << endl;
                        std::cout << "1. According to Name" << endl;
                        std::cout << "2. According to ID" << endl;
                        std::cout << "3. According to Salary" << endl;
                        std::cout << "Press - to return..." << endl;
                        std::cin >> option;
                        switch (option) {
                        case '1':
                            department->sort_by_name();
                            std::cout << "Sorted by Name Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '2':
                            department->sort_by_id();
                            std::cout << "Sorted by ID Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '3':
                            department->sort_by_salary();
                            std::cout << "Sorted by Salary Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '-':
                            system("CLS");
                            break;
                        default:
                            system("CLS");
                            std::cout << "Invalid choice!" << endl;
                            break;
                        }
                    } while (option != '-');
                    break;
                }
                case '6': // Display Managers
                {
                    system("CLS");
                    department->display_managers();
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '-':
                {
                    system("CLS");
                    break;
                }
                default:
                {
                    system("CLS");
                    std::cout << "Invalid Choice!" << endl;
                    break;
                }
                }
            } while (managerChoice != '-');
            break;
        }
        case '3': // Manage Employees
        {
            system("CLS");
            string deptName;
            int deptID;
            cout << "Enter Department's name(-1 to return): ";
            getline(std::cin >> ws, deptName);
            if (deptName == "-1") {
                system("CLS");
                break;
            }
            cout << "Enter Department's ID: ";
            cin >> deptID;
            if (std::cin.fail()) {
                system("CLS");
                cerr << "Invalid ID input!" << endl;
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            if (!admin.departmentExists(deptName, deptID)) {
                cout << "Department Does not exist!" << endl;
                cout << "Press any key to return...";
                cin >> wait;
                system("CLS");
                break;
            }

            Department* department = admin.get_departments();
            while (department != nullptr) {
                if (department->get_id() == deptID && department->get_name() == deptName) {
                    system("CLS");
                    cout << "Department Found!" << endl << endl;
                    department->display();
                    cout << endl;
                    break;
                }
                department = department->get_next();
            }

            char employeeChoice;
            do {
                std::cout << "EMPLOYEE MANAGEMENT" << endl;
                std::cout << "1. Add Employee" << endl;
                std::cout << "2. Remove Employee" << endl;
                std::cout << "3. Search Employee" << endl;
                std::cout << "4. Update Employee" << endl;
                std::cout << "5. Sort Employees" << endl;
                std::cout << "6. Display Employees" << endl;
                std::cout << "Press - to return..." << endl << endl;
                std::cout << "Enter your choice: ";
                std::cin >> employeeChoice;

                switch (employeeChoice) {
                case '1':
                {
                    int managerId;
                    string managerName;
                    cout << "For Which Manager, Enter Name(-1 to return): ";
                    getline(cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    cout << "For Which Manager, Enter ID: ";
                    cin >> managerId;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    Manager* manager = department->checkManager(managerName, managerId);
                    if (manager != nullptr) {
                        //Manager Found
                        int employeeId;
                        string employeeName;
                        double employeeSalary;
                        system("CLS");
                        cout << "Manager Found!" << endl << endl;
                        cout << "Enter Name of new employee(-1 to return): ";
                        getline(cin >> ws, employeeName);
                        if (employeeName == "-1") {
                            system("CLS");
                            break;
                        }
                        cout << "Enter ID of new employee: ";
                        cin >> employeeId;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid ID input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        cout << "Enter Salary of new employee: ";
                        cin >> employeeSalary;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid Salary input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        Employee* employee = manager->checkEmployee(employeeName, employeeId);
                        if (employee != nullptr) {
                            cout << "Employee already exists!" << endl;
                        }
                        else {
                            manager->add_employee(employeeName, employeeId, employeeSalary);
                        }
                    }
                    else {
                        cout << "Manager Not Found!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '2': // Remove Employee
                {
                    int managerId;
                    string managerName;
                    cout << "For Which Manager, Enter Name(-1 to return): ";
                    getline(cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    cout << "For Which Manager, Enter ID: ";
                    cin >> managerId;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    Manager* manager = department->checkManager(managerName, managerId);
                    if (manager != nullptr) {
                        //Manager Found
                        int employeeId;
                        string employeeName;
                        double employeeSalary;
                        system("CLS");
                        cout << "Manager Found!" << endl << endl;
                        cout << "Enter Name of employee to delete: ";
                        getline(cin >> ws, employeeName);
                        if (employeeName == "-1") {
                            system("CLS");
                            break;
                        }
                        cout << "Enter ID of employee to delete: ";
                        cin >> employeeId;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid ID input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        Employee* employee = manager->checkEmployee(employeeName, employeeId);
                        if (employee != nullptr) {
                            manager->delete_employee(employeeName, employeeId);
                        }
                        else {
                            cout << "Employee does not exist!" << endl;
                        }
                    }
                    else {
                        cout << "Manager Not Found!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '3': // Search Employee
                {
                    system("CLS");
                    std::cout << "SEARCH EMPLOYEE" << endl;
                    string managerName;
                    int managerID;
                    double managerSalary;
                    std::cout << "Enter Manager Name(-1 to return): ";
                    getline(std::cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    std::cout << "Enter Manager ID: ";
                    std::cin >> managerID;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    if (department->managerExists(managerName, managerID)) {
                        Manager* manager = department->get_managers();
                        while (manager != nullptr) {
                            if (manager->get_name() == managerName && manager->get_id() == managerID) {
                                string empName;
                                int empID;
                                std::cout << "Enter Employee Name(-1 to return): ";
                                getline(std::cin >> ws, empName);
                                if (empName == "-1") {
                                    system("CLS");
                                    break;
                                }
                                std::cout << "Enter Employee ID: ";
                                std::cin >> empID;
                                if (std::cin.fail()) {
                                    system("CLS");
                                    cerr << "Invalid ID input!" << endl;
                                    std::cin.clear();
                                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    break;
                                }
                                Employee *emp = manager->checkEmployee(empName, empID);
                                
                                if (emp == nullptr) {
                                    cout << "Employee not found!" << endl;
                                }
                                else {
                                    emp->display();
                                }
                            }
                            manager = manager->get_next();
                        }
                    }
                    else {
                        std::cout << "Manager does not exist!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '4': // Update Employees
                {
                    int managerId;
                    string managerName;
                    cout << "For Which Manager, Enter Name(-1 to return): ";
                    getline(cin >> ws, managerName);
                    if (managerName == "-1") {
                        system("CLS");
                        break;
                    }
                    cout << "For Which Manager, Enter ID: ";
                    cin >> managerId;
                    if (std::cin.fail()) {
                        system("CLS");
                        cerr << "Invalid ID input!" << endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    Manager* manager = department->checkManager(managerName, managerId);
                    if (manager != nullptr) {
                        //Manager Found
                        int employeeId;
                        string employeeName;
                        double employeeSalary;
                        system("CLS");
                        cout << "Manager Found!" << endl << endl;
                        cout << "Enter Name of employee to update(-1 to return): ";
                        getline(cin >> ws, employeeName);
                        if (employeeName == "-1") {
                            system("CLS");
                            break;
                        }
                        cout << "Enter ID of employee to update: ";
                        cin >> employeeId;
                        if (std::cin.fail()) {
                            system("CLS");
                            cerr << "Invalid ID input!" << endl;
                            std::cin.clear();
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }

                        Employee* employee = manager->checkEmployee(employeeName, employeeId);
                        if (employee != nullptr) {
                            manager->delete_employee_from_file(employee);
                            // Ask for new information
                            cout << "Enter new Name for employee: ";
                            getline(cin >> ws, employeeName);
                            cout << "Enter new ID for employee: ";
                            cin >> employeeId;
                            if (std::cin.fail()) {
                                system("CLS");
                                cerr << "Invalid ID input!" << endl;
                                std::cin.clear();
                                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                break;
                            }
                            cout << "Enter new Salary for employee: ";
                            cin >> employeeSalary;
                            if (std::cin.fail()) {
                                system("CLS");
                                cerr << "Invalid Salary input!" << endl;
                                std::cin.clear();
                                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                break;
                            }

                            // Update employee with new information
                            employee->set_name(employeeName);
                            employee->set_id(employeeId);
                            employee->set_salary(employeeSalary);
                            // Add the updated employee to the file
                            manager->write_employee(employee);
                            cout << "Employee updated successfully!" << endl;
                        }
                        else {
                            cout << "Employee does not exist!" << endl;
                        }
                    }
                    else {
                        cout << "Manager Not Found!" << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '5': // Sort Employee
                {
                    system("CLS");
                    char option;
                    do {
                        std::cout << "SORT EMPLOYEES" << endl;
                        std::cout << "1. According to Name" << endl;
                        std::cout << "2. According to ID" << endl;
                        std::cout << "3. According to Salary" << endl;
                        std::cout << "Press - to return..." << endl;
                        std::cin >> option;
                        switch (option) {
                        case '1':
                            department->sort_by_name();
                            std::cout << "Sorted Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '2':
                            department->sort_by_id();
                            std::cout << "Sorted Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '3':
                            department->sort_by_salary();
                            std::cout << "Sorted Successfully!" << endl;
                            std::cout << "Press any key to continue...";
                            std::cin >> wait;
                            system("CLS");
                            break;
                        case '-':
                            system("CLS");
                            break;
                        default:
                            system("CLS");
                            std::cout << "Invalid choice!" << endl;
                            break;
                        }
                    } while (option != '-');
                    break;
                }
                case '6':
                {
                    system("CLS");
                    if (department->get_managers() == nullptr) {
                        std::cout << "No Managers!" << endl;
                    }
                    else {
                        Manager* temp = department->get_managers();
                        int count = 0;
                        while (temp != nullptr) {
                            count++;
                            std::cout << count << "." << endl;
                            std::cout << " - Manager Name: " << temp->get_name() << endl;
                            std::cout << " - Manager ID: " << temp->get_id() << endl;
                            std::cout << " - Manager Salary: " << temp->get_salary() << endl;
                            std::cout << " - Manager's Department: " << temp->get_department_id() << endl << endl;
                            temp->display_employees();
                            temp = temp->get_next();
                        }
                        std::cout << endl;
                    }
                    std::cout << "Press any key to continue...";
                    std::cin >> wait;
                    system("CLS");
                    break;
                }
                case '-':
                {
                    system("CLS");
                    break;
                }
                default:
                {
                    system("CLS");
                    std::cout << "Invalid Choice!" << endl;
                    break;
                }
                }
            } while (employeeChoice != '-');
            break;
        }
        case '-':
        {
            system("CLS");
            return;
            break;
        }
        default:
        {
            system("CLS");
            std::cout << "Invalid Choice!" << endl;
            break;
        }
        }
    } while (option != '-');
}

void choose_interface(Admin& admin) {
    char choice;
    do {
        std::cout << "CHOOSE INTERFACE" << endl;
        std::cout << "1. Admin Interface" << endl;
        std::cout << "2. Manager Interface" << endl;
        std::cout << "3. Employee Interface" << endl;
        std::cout << "Press - to return..." << endl << endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            //Login for Admin
            system("CLS");
            admin_login(admin);
            break;
        case '2':
            //Login for Managers
            system("CLS");
            manager_login(admin.get_departments());
            break;
        case '3':
            //Login for Employees
            system("CLS");
            employee_login(admin.get_departments());
            break;
        case '-':
            std::cout << "Exiting..." << endl;
            break;
        default:
            system("CLS");
            std::cout << "Invalid choice" << endl;
        }
    } while (choice != '-');
}