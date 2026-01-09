/* Program created by: Muhammad Arham Azam
Roll# L1S22BSCS0413
DATE: 28-06-2022, Time: 10:08 PM
Project: A Cafe Management System.
*/
#include <iostream>
using namespace std;

int main(){
    int choice1,choice2,id,students, transaction, total = 0;

    cout << "-----------------------------------WELCOME TO UCP CAFÉ MANAGEMENT SYSTEM----------------------------\n\n";
    jump1: //Flag variable to switch to first screen
    cout << "FIRST MENU:\n(Note = Select from following options)\n\n";

    cout << "1- Login.\n2- Exit.\n\nChoice: ";
    cin >> choice1;

    switch (choice1) // switch statement for screen 1
    {
    case 1: // if the user selects option 1 on screen 1
        cout << "Enter ID: ";
        cin >> id; // get the id of employers
        if (id == 431 || id == 532)
        {
        jump2: //Flag variable to switch to second screen
        cout << "SECOND MENU:\n(Note = Select from following options)\n\n";
        cout << "1- Make a purchase.\n2- Switch\n3- Logout.\n4- Exit.\n\nChoice: ";
        cin >> choice2;
        switch (choice2)// if the user selects option 1 on screen 2
        {
        case 1:
            cout << "Enter the number of students: ";
            cin >> students; // gets the number of customers
            for (int i = 1; i <= students; i++) // loop to ask every student the menu.
            {   
                for (int j = 1; j <= 2; j++) // loop to take 2 orders from each student
                {   
                    
                    cout << "Student" << i <<": \n";
                    cout << "-------------------------------------------------------------ITEMS LIST--------------------------------------------------------\n\n";
                    cout << "Items serial number: \t1\t\t2\t\t3\t\t4\t\t5\t\t6\nName: \t\t\tTEA\t\tSMALL PIZZA\tPATTIES\t\tPASTRY\t\tSAMOSA\t\tGREEN SALAD\n";
                    cout << "Transaction" << j <<": ";
                    cin >> transaction;// gets the order of students
                    if(transaction > 0){
                        ++total; // sum of total orders, if they're greater than 0
                    }
                }
                cout << "\n";

                
            }
            cout << "Total number of transactions = " << total << endl <<endl;
            goto jump2;// statement that takes back to screen 2.
            break;
        case 2:
            cout << "Total number of transactions = " << total << endl <<endl;
            goto jump1;// statement that takes to screen 1.
        case 3:
            cout << "Total number of transactions = " << total << endl <<endl;
            goto jump1;
        case 4: // takes to exit screen
            cout << "---------------------------------GOODBYE--------------------------------\n";
            break;
        default: // if the user inputs wrong option, warns them.
            cout << "Input correct option!!\n";
            goto jump2;
            break;
        }
        
        }
        else
        {
            cout << "Wrong ID: You are not allowed to enter!\n";
        }
        break;
        
      
    case 2:
            cout << "---------------------------------GOODBYE--------------------------------\n";
            break;
    default:
        cout << "Input correct option!!\n";
        goto jump1;
        break;
    }
    system("pause");
    return 0;
}