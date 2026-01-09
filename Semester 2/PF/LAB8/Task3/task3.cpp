#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
string name, designation_in, designation, phoneNumber, updated_designation, word;
int salary, choice;
cout << "Press 1 to find a record's designation in the file" << endl;
cout << "Press 2 to update a record's designation in the file" << endl;
cout << "Press 3 to delete a record's designation in the file" << endl;
cout << "Press 4 to add a new word in the file" << endl;
cout << "Enter your choice: ";
cin >> choice;

ifstream recordFile;
ofstream tempFile;
recordFile.open("read.txt");
tempFile.open("temp.txt");

switch(choice)
{
    case 1:
        cout << "Enter the designation (without space in between) of the employee: ";
        cin >> designation_in;

        cout << "Name\tPhone Number" << endl;
        while (recordFile >> name >> salary >> designation >> phoneNumber)
        {
            if (designation_in == designation)
            {
                cout << name << "\t" << phoneNumber << endl;
            }
        }
        break;
    case 2:
        cout << "Enter the designation (without space in between) of the employee to update: ";
        cin >> designation_in;

        cout << "Enter the new designation for the employee: ";
        cin >> updated_designation;

        while (recordFile >> name >> salary >> designation >> phoneNumber)
        {
            if (designation_in == designation)
            {
                tempFile << name << " " << salary << " " << updated_designation << " " << phoneNumber << endl;
            }
            else
            {
                tempFile << name << " " << salary << " " << designation << " " << phoneNumber << endl;
            }
        }
        cout << "Record updated successfully!" << endl;
        break;
    case 3:
        cout << "Enter the designation (without space in between) of the employee to delete: ";
        cin >> designation_in;

        while (recordFile >> name >> salary >> designation >> phoneNumber)
        {
            if (designation_in == designation)
            {
                tempFile << name << " " << salary << " "  << " " << phoneNumber << endl;
            }
            else
            {
                tempFile << name << " " << salary << " " << designation << " " << phoneNumber << endl;
            }
        }
        cout << "Record deleted successfully!" << endl;
        break;
    case 4:
        cout << "Enter the designation (without space in between) of the employee to add word infront:";
        cin >> designation_in;
        cout << "Enter the word to add: ";
        cin >> word;

        while (recordFile >> name >> salary >> designation >> phoneNumber)
        {
            if (designation_in == designation)
            {
                tempFile << name << " " << salary << " " << designation << " " << word << " " << phoneNumber << endl;
            }
            else
            {
                tempFile << name << " " << salary << " " << designation << " " <<  phoneNumber << endl;
            }
            
        }
        

        cout << "Record added successfully!" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
}

recordFile.close();
tempFile.close();

remove("record.txt");
rename("temp.txt", "record.txt");

return 0;
}