#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;
fstream myFile;

class Shift {
private:
    string startTime; //00:00 AM
    string endTime;
    bool late;
    bool overtime;
    double expectedHours = 8.0; // Assuming 8 hours is the standard workday

public:
    Shift(string start, string end) : startTime(start), endTime(end), late(false), overtime(false) {
        calculateLateness();
        calculateOvertime();
    }
    void calculateLateness() {
        late = (startTime > "09:00 AM");
    }
    void calculateOvertime() {
        double duration = calculateDuration();
        overtime = (duration > expectedHours);
    }
    double calculateDuration() {
        // Time should be in 24-hour format (HH:mm)
        int startHour = stoi(startTime.substr(0, 2));
        int startMinute = stoi(startTime.substr(3, 2));
        int endHour = stoi(endTime.substr(0, 2));
        int endMinute = stoi(endTime.substr(3, 2));
        // Calculate duration in hours
        double duration = (endHour - startHour) + (endMinute - startMinute) / 60.0;
        return duration;
    }
    //Setters
    void setStartTime(string startTime) {
        this->startTime = startTime;
    }
    void setEndTime(string endTime) {
        this->endTime = endTime;
    }
    void setLate(bool late) {
        this->late = late;
    }
    void setOvertime(bool overtime) {
        this->overtime = overtime;
    }
    //Getters
    string get_start_time() { return startTime; }
    string get_end_time() { return endTime; }
    bool isLate() { return late; }
    bool isOvertime() { return overtime; }
};

class Attributes {
protected:
    int ID;
    string name;
    double salary;
    Shift* shifts; //head
public:
    Attributes(int ID, string name, double salary) : ID(ID), name(name), salary(salary), shifts(nullptr) {}

    //Getters
    int get_id() { return ID; }
    string get_name() { return name; }
    double get_salary() { return salary; }

    //Setters
    void set_id(int ID) { this->ID = ID; }
    void set_name(string name) { this->name = name; }
    void set_salary(double salary) { this->salary = salary; }

    virtual void display() = 0;
};

class Employee : public Attributes {
private:
    int manager_id;
    Employee* next;
public:
    Employee(int ID, string name, double salary) : Attributes(ID, name, salary), manager_id(manager_id), next(nullptr) {}
    //Getters
    int get_manager_ID() { return manager_id; }
    Employee* get_next() { return next; }
    //Setters
    void set_manager_ID(int manager_id) {
        this->manager_id = manager_id;
    }
    void set_next(Employee* node) {
        next = node;
    }

    void display() {
        std::cout << "\t\tEmployee Name: " << name << endl;
        std::cout << "\t\tEmployee ID: " << ID << endl;
        std::cout << "\t\tEmployee Salary: " << salary << endl;
    }

};

class Manager : public Attributes {
private:
    int department_id;
    Employee* employees; //head
    Manager* next;
    int nextID;
public:
    Manager(int ID, string name, double salary) : Attributes(ID, name, salary), employees(nullptr), next(nullptr), nextID(0) {}
    //Getter
    Manager* get_next() { return next; }
    int get_department_id() { return department_id; }
    Employee* get_employees() { return employees; }
    //Setter
    void set_next(Manager* node) {
        next = node;
    }
    void set_department_id(int department_id) {
        this->department_id = department_id;
    }

    //add Employee to tail
    void add_employee(string emp_name, int emp_id, double salary, bool emp_from_file = false) {
        nextID++;
        Employee* node;
        if (emp_from_file) {
            node = new Employee(emp_id, emp_name, salary);
        }
        else {
            node = new Employee((ID * 100) + nextID, emp_name, salary);
        }
        node->set_manager_ID(ID);
        if (employees == nullptr) {
            employees = node;
        }
        else {
            Employee* temp = employees;
            while (temp->get_next() != nullptr) {
                temp = temp->get_next();
            }
            temp->set_next(node);
        }
        std::cout << "Employee successfully Added!" << endl;
        if (!emp_from_file) {
            std::cout << "Employee written to file too !" << endl;
            write_employee(node);
        }
    }

    void delete_employee(string emp_name, int emp_id) {
        if (employees == nullptr) {
            std::cout << "No Employees!" << endl;
        }
        else if (employees->get_id() == emp_id && employees->get_name() == emp_name) {
            delete_employee_from_file(employees);
            Employee* temp = employees;
            if (employees->get_next() == nullptr) {
                delete employees;
                employees = nullptr;
            }
            else {
                employees = employees->get_next();
                delete temp;
            }
        }
        else {
            Employee* temp = employees;
            Employee* prev = nullptr;
            bool found = false;
            while (temp != nullptr) {
                if (temp->get_name() == emp_name && temp->get_id() == emp_id) {
                    found = true;
                    std::cout << "Found!" << endl;
                    break;
                }
                prev = temp;
                temp = temp->get_next();
            }

            if (found == true) {
                prev->set_next(prev->get_next()->get_next());
                delete_employee_from_file(temp);
                delete temp;
            }
            else {
                std::cout << "Not Found!" << endl;
            }

        }

    }

    void search_employee(string name, int id) {
        if (employees == nullptr) {
            std::cout << "No Employees!" << endl;
            return;
        }

        Employee* temp = employees;
        bool found = false;

        while (temp != nullptr) {
            if (temp->get_id() == id && temp->get_name() == name) {
                temp->display();
                found = true;
                break;
            }
            temp = temp->get_next();
        }

        if (!found) {
            std::cout << "Employee not found!" << endl;
        }
    }

    Employee* checkEmployee(string name, int id) {
        if (employees == nullptr) {
            std::cout << "No Employees!" << endl;
            return nullptr;
        }

        Employee* temp = employees;
        bool found = false;
        while (temp != nullptr) {
            if (temp->get_id() == id && temp->get_name() == name) {
                return temp;
                break;
            }
            temp = temp->get_next();
        }

        return nullptr;
    }

    void update_employee(string name, int id) {
        if (employees == nullptr) {
            std::cout << "No Employees!" << endl;
            return;
        }

        Employee* temp = employees;
        bool found = false;

        while (temp != nullptr) {
            if (temp->get_name() == name && temp->get_id() == id) {
                temp->display();
                found = true;
                int id; string name; double salary;
                std::cout << "New Name for employee: ";
                getline(std::cin >> ws, name);
                std::cout << "New ID for employee: ";
                std::cin >> id;
                if (std::cin.fail()) {
                    system("CLS");
                    cerr << "Invalid ID input!" << endl;
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                std::cout << "New Salary for employee: ";
                std::cin >> salary;
                if (std::cin.fail()) {
                    system("CLS");
                    cerr << "Invalid Salary input!" << endl;
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                delete_employee_from_file(temp);
                temp->set_id(id);
                temp->set_name(name);
                temp->set_salary(salary);
                write_employee(temp);
                break;
            }
            temp = temp->get_next();
        }

        if (!found) {
            std::cout << "Employee not found!" << endl;
        }
        else {
            std::cout << "Updated Successfully!" << endl;
        }
    }

    void sort_by_id() {
        Employee* temp = employees;
        while (temp->get_next() != nullptr) {
            Employee* current = employees;
            while (current->get_next() != nullptr) {
                Employee* nextNode = current->get_next();
                if (current->get_id() > nextNode->get_id()) {
                    swap_employees(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }

    void sort_by_name() {
        Employee* temp = employees;
        while (temp->get_next() != nullptr) {
            Employee* current = employees;
            while (current->get_next() != nullptr) {
                Employee* nextNode = current->get_next();
                if (current->get_name() > nextNode->get_name()) {
                    swap_employees(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }


    void sort_by_salary() {
        Employee* temp = employees;
        while (temp->get_next() != nullptr) {
            Employee* current = employees;
            while (current->get_next() != nullptr) {
                Employee* nextNode = current->get_next();
                if (current->get_salary() > nextNode->get_salary()) {
                    swap_employees(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }

    void swap_employees(Employee* a, Employee* b) {
        int tempId = a->get_id();
        string tempName = a->get_name();
        double tempSalary = a->get_salary();

        a->set_id(b->get_id());
        a->set_name(b->get_name());
        a->set_salary(b->get_salary());

        b->set_id(tempId);
        b->set_name(tempName);
        b->set_salary(tempSalary);
    }

    //Write Employee to file
    void write_employee(Employee* node) {
        myFile.open("employees.txt", ios::app);
        if (myFile.is_open()) {
            myFile << endl << node->get_name() << ";" << node->get_id() << ";" << node->get_salary() << ";" << node->get_manager_ID() << ";";
            myFile.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
    }

    void delete_employee_from_file(Employee* node) {
        ifstream inputFile("employees.txt");
        ofstream outputFile("temp_employees.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            string line;

            while (getline(inputFile, line)) {
                istringstream ss(line);
                string empName;
                int empId;
                double empSalary;
                int empManagerId;

                if (getline(ss, empName, ';') &&
                    (ss >> empId) &&
                    (ss.ignore(1, ';')) &&
                    (ss >> empSalary) &&
                    (ss.ignore(1, ';')) &&
                    (ss >> empManagerId) &&
                    (ss.ignore(1, ';'))) {

                    if (empName == node->get_name() && empId == node->get_id()) {
                        //it matches
                        continue;
                    }
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }

                // If the output file is not empty, add a newline before writing a new line
                if (!outputFile.tellp() == 0) {
                    outputFile << '\n';
                }

                // Write the line to the new file (excluding the line to be deleted)
                outputFile << line;
            }

            inputFile.close();
            outputFile.close();

            // Replace the original file with the new file
            if (remove("employees.txt") != 0) {
                cerr << "Error removing original file: " << errno << endl;
            }
            else if (rename("temp_employees.txt", "employees.txt") != 0) {
                cerr << "Error replacing file. Error code: " << errno << endl;
            }
            else {
                cout << "Employee deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error opening files." << endl;
        }
    }

    //Read Employee for starting of the program
    void read_employees() {
        myFile.open("employees.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                stringstream ss(line);
                string empName;
                int empId;
                double empSalary;
                int empManagerId;

                if (getline(ss, empName, ';') && (ss >> empId) && (ss.ignore(1, ';')) && (ss >> empSalary) && (ss.ignore(1, ';')) && (ss >> empManagerId) && (ss.ignore(1, ';'))) {
                    if (empManagerId == ID) {
                        add_employee(empName, empId, empSalary, true);
                    }
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }
            }
            myFile.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
    }

    void delete_all_employees(Employee* emp) {
        while (emp != nullptr) {
            Employee* emp_to_delete = emp;
            emp = emp->get_next();
            delete_employee_from_file(emp_to_delete);
            delete emp_to_delete;
            emp_to_delete = nullptr;
        }
    }

    void display_employees() {
        if (employees == nullptr) {
            std::cout << "No Employees!" << endl;
        }
        else {
            Employee* temp = employees;
            int count = 0;
            while (temp != nullptr) {
                count++;
                std::cout << count << "." << endl;
                std::cout << " - - Employee Name: " << temp->get_name() << endl;
                std::cout << " - - Employee ID: " << temp->get_id() << endl;
                std::cout << " - - Employee Salary: " << temp->get_salary() << endl;
                std::cout << " - - Employee's Manager: " << temp->get_manager_ID() << endl << endl;
                temp = temp->get_next();
            }
            std::cout << endl;
        }
    }

    void display() {
        std::cout << "Manager Name: " << name << endl;
        std::cout << "Manager ID: " << ID << endl;
        std::cout << "Manager Salary: " << salary << endl;
    }
};

class Department {
private:
    int ID;
    string name;
    Manager* managers; //head
    Department* next;
public:
    Department(int ID, string name) : ID(ID), name(name), managers(nullptr), next(nullptr) {}
    //Getter
    Department* get_next() { return next; }
    int get_id() { return ID; }
    string get_name() { return name; }
    Manager* get_managers() { return managers; }
    //Setter
    void set_next(Department* node) { next = node; }
    void set_id(int ID) { this->ID = ID; }
    void set_name(string name) { this->name = name; }
    //add manager to tail
    void add_manager(string man_name, int man_id, double salary, bool manager_from_file = false) {
        Manager* node = new Manager(man_id, man_name, salary);
        node->set_department_id(ID);
        if (managers == nullptr) {
            managers = node;
        }
        else {
            Manager* temp = managers;
            while (temp->get_next() != nullptr) {
                temp = temp->get_next();
            }
            temp->set_next(node);
        }

        if (!manager_from_file) {
            write_manager(node);
        }
    }
    //Delete Manager
    void delete_manager(string man_name, int man_id, double salary) {
        if (managers == nullptr) {
            cout << "No Manager To Delete!" << endl;
            return;
        }
        else if (managers->get_name() == man_name && managers->get_id() == man_id && managers->get_salary() == salary) {
            if (managers->get_next() == nullptr) {
                delete_manager_from_file(managers);
                managers->delete_all_employees(managers->get_employees());
                delete managers;
                managers = nullptr;
            }
            else {
                delete_manager_from_file(managers);
                managers->delete_all_employees(managers->get_employees());
                Manager* man_to_delete = managers;
                managers = managers->get_next();
                delete man_to_delete;
            }
        }
        else {
            Manager* temp = managers;
            while (temp->get_next() != nullptr) {
                if (temp->get_next()->get_name() == man_name && temp->get_next()->get_salary() == salary && temp->get_next()->get_id() == man_id) {
                    delete_manager_from_file(temp->get_next());
                    temp->get_next()->delete_all_employees(temp->get_next()->get_employees());
                    Manager* man_to_delete = temp->get_next();
                    temp->set_next(temp->get_next()->get_next());
                    delete man_to_delete;
                    cout << "Deleted Successfully!" << endl;
                    break;
                }
                temp = temp->get_next();
            }
        }
    }

    Manager* checkManager(string managerName, int managerID) {
        if (managers == nullptr) {
            return nullptr;
        }
        else {
            Manager* node = managers;
            while (node != nullptr) {
                if (node->get_name() == managerName && node->get_id() == managerID) {
                    return node;
                }
                node = node->get_next();
            }
            return nullptr;
        }
    }

    void delete_all_managers(Manager* managers) {
        while (managers != nullptr) {
            Manager* manager_to_delete = managers;
            managers = managers->get_next();

            manager_to_delete->delete_all_employees(manager_to_delete->get_employees());

            delete_manager_from_file(manager_to_delete);
            delete manager_to_delete;
            manager_to_delete = nullptr;
        }
    }

    //Write manager to file
    void write_manager(Manager* node) {
        myFile.open("managers.txt", ios::app);
        if (myFile.is_open()) {
            myFile << endl << node->get_name() << ";" << node->get_id() << ";" << node->get_salary() << ";" << node->get_department_id() << ";";
            myFile.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
    }

    void delete_manager_from_file(Manager* node) {
        ifstream inputFile("managers.txt");
        ofstream outputFile("temp_managers.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            string line;

            while (getline(inputFile, line)) {
                istringstream ss(line);
                string managerName;
                int managerId, departmentId;
                double managerSalary;

                if (getline(ss, managerName, ';') &&
                    (ss >> managerId) &&
                    (ss.ignore(1, ';')) &&
                    (ss >> managerSalary) &&
                    (ss.ignore(1, ';')) &&
                    (ss >> departmentId) &&
                    (ss.ignore(1, ';'))) {

                    if (managerName == node->get_name() && managerId == node->get_id() && departmentId == node->get_department_id()) {
                        // Match found, skip this line
                        continue;
                    }
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }

                // If the output file is not empty, add a newline before writing a new line
                if (!outputFile.tellp() == 0) {
                    outputFile << '\n';
                }

                // Write the line to the new file (excluding the line to be deleted)
                outputFile << line;
            }

            inputFile.close();
            outputFile.close();

            // Replace the original file with the new file
            if (remove("managers.txt") != 0) {
                cerr << "Error removing original file: " << errno << endl;
            }
            else if (rename("temp_managers.txt", "managers.txt") != 0) {
                cerr << "Error replacing file. Error code: " << errno << endl;
            }
            else {
                cout << "Manager deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error opening files." << endl;
        }
    }


    //Read managers for starting of the program
    void read_managers() {
        myFile.open("managers.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                stringstream ss(line);
                string managerName;
                int managerId;
                double managerSalary;
                int managerDepartmentId;

                if (getline(ss, managerName, ';') && (ss >> managerId) && (ss.ignore(1, ';')) && (ss >> managerSalary) && (ss.ignore(1, ';')) && (ss >> managerDepartmentId) && (ss.ignore(1, ';'))) {
                    if (managerDepartmentId == ID) {
                        add_manager(managerName, managerId, managerSalary, true);
                    }
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }
            }
            myFile.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
    }

    void read_employees_for_each_manager() {
        if (managers == nullptr) {
            std::cout << "No Managers!" << endl;
        }
        else {
            Manager* temp = managers;
            while (temp != nullptr) {
                temp->read_employees();
                temp = temp->get_next();
            }
        }
    }

    void display_managers() {
        if (managers == nullptr) {
            std::cout << "No Managers!" << endl;
        }
        else {
            Manager* temp = managers;
            int count = 0;
            while (temp != nullptr) {
                count++;
                std::cout << count << "." << endl;
                std::cout << " - Manager Name: " << temp->get_name() << endl;
                std::cout << " - Manager ID: " << temp->get_id() << endl;
                std::cout << " - Manager Salary: " << temp->get_salary() << endl;
                std::cout << " - Manager's Department: " << temp->get_department_id() << endl << endl;
                temp = temp->get_next();
            }
            std::cout << endl;
        }
    }

    void display() {
        std::cout << "Department Name: " << name << endl;
        std::cout << "Department ID: " << ID << endl;
    }

    bool managerExists(string managerName, int managerID) {
        if (managers == nullptr) {
            return false;
        }
        else {
            Manager* node = managers;
            while (node != nullptr) {
                if (node->get_name() == managerName && node->get_id() == managerID) {
                    return true;
                }
                node = node->get_next();
            }
            return false;
        }
    }

    void sort_by_id() {
        Manager* temp = managers;
        while (temp->get_next() != nullptr) {
            Manager* current = managers;
            while (current->get_next() != nullptr) {
                Manager* nextNode = current->get_next();
                if (current->get_id() > nextNode->get_id()) {
                    swap_managers(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }

    void sort_by_name() {
        Manager* temp = managers;
        while (temp->get_next() != nullptr) {
            Manager* current = managers;
            while (current->get_next() != nullptr) {
                Manager* nextNode = current->get_next();
                if (current->get_name() > nextNode->get_name()) {
                    swap_managers(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }


    void sort_by_salary() {
        Manager* temp = managers;
        while (temp->get_next() != nullptr) {
            Manager* current = managers;
            while (current->get_next() != nullptr) {
                Manager* nextNode = current->get_next();
                if (current->get_salary() > nextNode->get_salary()) {
                    swap_managers(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }

    void swap_managers(Manager* a, Manager* b) {
        int tempId = a->get_id();
        string tempName = a->get_name();
        double tempSalary = a->get_salary();

        a->set_id(b->get_id());
        a->set_name(b->get_name());
        a->set_salary(b->get_salary());

        b->set_id(tempId);
        b->set_name(tempName);
        b->set_salary(tempSalary);
    }

};

class Admin {
private:
    string name;
    string password;
    Department* departments = nullptr; //head;
    Admin() {}
    Admin(const Admin&) {}
public:
    static Admin& getInstance() {
        static Admin instance;
        return instance;
    }
    //Getters
    string get_password() { return password; }
    string get_name() { return name; }
    Department* get_departments() { return departments; }
    //Setters
    void set_password(string password) {
        this->password = password;
    }
    void set_name(string name) {
        this->name = name;
    }

    //add department to tail
    void add_department(string name, int ID, bool dept_from_file = false) {
        Department* node = new Department(ID, name);
        if (departments == nullptr) {
            departments = node;
        }
        else {
            Department* temp = departments;
            while (temp->get_next() != nullptr) {
                temp = temp->get_next();
            }
            temp->set_next(node);
        }

        if (!dept_from_file) {
            write_department(node);
        }
    }

    void delete_department(string name, int ID) {
        if (departments == nullptr) {
            return;
        }
        if (departments->get_name() == name && departments->get_id() == ID) {
            delete_dept_from_file(departments);
            departments->delete_all_managers(departments->get_managers());
            if (departments->get_next() == nullptr) {
                delete departments;
                departments = nullptr;
            }
            else {
                Department* deptToDelete = departments;
                departments = departments->get_next();
                delete deptToDelete;
            }
        }
        else {
            Department* temp = departments;
            while (temp->get_next() != nullptr) {
                if (temp->get_next()->get_name() == name && temp->get_next()->get_id() == ID) {
                    Department* nodeToDelete = temp->get_next();
                    temp->set_next(temp->get_next()->get_next());
                    temp->delete_all_managers(nodeToDelete->get_managers());
                    delete_dept_from_file(nodeToDelete);
                    delete nodeToDelete;
                    return;
                }
                temp = temp->get_next();
            }
        }
    }

    void sort_depts_by_id() {
        Department* temp = departments;
        while (temp->get_next() != nullptr) {
            Department* current = departments;
            while (current->get_next() != nullptr) {
                Department* nextNode = current->get_next();
                if (current->get_id() > nextNode->get_id()) {
                    swap_departments(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }

    void sort_depts_by_name() {
        Department* temp = departments;
        while (temp->get_next() != nullptr) {
            Department* current = departments;
            while (current->get_next() != nullptr) {
                Department* nextNode = current->get_next();
                if (current->get_name() > nextNode->get_name()) {
                    swap_departments(current, nextNode);
                }
                current = current->get_next();
            }
            temp = temp->get_next();
        }
    }

    void swap_departments(Department* a, Department* b) {
        int tempId = a->get_id();
        string tempName = a->get_name();
        a->set_id(b->get_id());
        a->set_name(b->get_name());
        b->set_id(tempId);
        b->set_name(tempName);
    }

    void display_departments() {
        if (departments == nullptr) {
            std::cout << "No Departments!" << endl;
        }
        else {
            int count = 0;
            Department* temp = departments;
            while (temp != nullptr) {
                cout << "--------------------------------------------------------------------------" << endl;
                std::cout << " Department ID: " << temp->get_id() << endl;
                std::cout << " Department Name: " << temp->get_name() << endl;
                temp = temp->get_next();
                std::cout << endl;
            }
            std::cout << endl;
        }
    }

    bool departmentExists(string deptName, int deptID) {
        if (departments == nullptr) {
            return false;
        }
        else {
            Department* node = departments;
            while (node != nullptr) {
                if (node->get_name() == deptName && node->get_id() == deptID) {
                    return true;
                }
                node = node->get_next();
            }
            return false;
        }
    }

    //File Handling
    void read_departments() {
        myFile.open("departments.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                stringstream ss(line);
                string departmentName;
                int departmentId;

                if (getline(ss, departmentName, ';') && (ss >> departmentId, ";")) {
                    add_department(departmentName, departmentId, true);
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }
            }
            myFile.close();
        }
        else {
            cerr << "Unable to open file!" << endl;
        }
    }

    void write_department(Department* node) {
        myFile.open("departments.txt", ios::app);
        if (myFile.is_open()) {
            myFile << endl << node->get_name() << ";" << node->get_id() << ";";
        }
        myFile.close();
    }

    void delete_dept_from_file(Department* node) {
        ifstream inputFile("departments.txt");
        ofstream outputFile("temp_departments.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            string line;

            while (getline(inputFile, line)) {
                istringstream ss(line);
                string deptName;
                int deptId;

                if (getline(ss, deptName, ';') &&
                    (ss >> deptId) &&
                    (ss.ignore(1, ';'))) {

                    if (deptName == node->get_name() && deptId == node->get_id()) {
                        // Match found, skip this line
                        continue;
                    }
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }

                // If the output file is not empty, add a newline before writing a new line
                if (!outputFile.tellp() == 0) {
                    outputFile << '\n';
                }

                // Write the line to the new file (excluding the line to be deleted)
                outputFile << line;
            }

            inputFile.close();
            outputFile.close();

            // Replace the original file with the new file
            if (remove("departments.txt") != 0) {
                cerr << "Error removing original file: " << errno << endl;
            }
            else if (rename("temp_departments.txt", "departments.txt") != 0) {
                cerr << "Error replacing file. Error code: " << errno << endl;
            }
            else {
                cout << "Department deleted successfully." << endl;
            }
        }
        else {
            cerr << "Error opening files." << endl;
        }
    }


    //Reading managers for every department at start of program
    void read_managers_for_each_dept() {
        if (departments == nullptr) {
            std::cout << "No departments!" << endl;
        }
        else {
            Department* temp = departments;
            while (temp != nullptr) {
                temp->read_managers();
                temp = temp->get_next();
            }
        }
    }

    //Reading employees for every manager at start of program
    void read_employees_for_each_manager() {
        if (departments == nullptr) {
            std::cout << "No Departments!" << endl;
        }
        else {
            Department* temp = departments;
            while (temp != nullptr) {
                temp->read_employees_for_each_manager();
                temp = temp->get_next();
            }
        }
    }
};
