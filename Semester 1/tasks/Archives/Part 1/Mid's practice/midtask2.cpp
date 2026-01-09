#include <iostream>
using namespace std;

int main(){
    int family_members;
    int student_ticket = 250, normal_ticket = 400, executive_ticket = 750, total_movie = 0;
    int simple_popcorn = 100, tacos = 150, caramel_popcorn = 200, total_popcorn = 0;
    char selection;

    cout << "Enter the number of family members with you: ";
    cin >> family_members;
    cout << "Total members including you are " << family_members + 1 << endl;

    cout << "*********** Welcome to Emporium Cinema ************" << endl;
    cout << "Select from the following menu for ticket for each family member including you!" << endl;
    for(int i = 1; i <=(family_members+1); i++){
        cout << "Enter S for student ticket price " << student_ticket << endl;
        cout << "Enter N for student ticket price " << normal_ticket << endl;
        cout << "Enter E for student ticket price " << executive_ticket << endl;
        cout << "Enter your option: ";
        cin >> selection;
        if(selection == 'S'){
            total_movie += student_ticket;
        }
        else if(selection == 'N'){
            total_movie += normal_ticket;
        }
        else if(selection == 'E'){
            total_movie += executive_ticket;
        }
        else{
            cout << "Invalid Input! " << endl;
            cin >> selection;
        }
    }

    cout << "@@@@@@@@@@ Welcome to the popcorn shop @@@@@@@@@@" << endl;
    cout << "Select from the following menu for popcorn for each family member including you!" << endl;
    for(int i = 1; i <=(family_members+1); i++){
        cout << "Enter S for simple price " << simple_popcorn << endl;
        cout << "Enter T for Tacos price " << tacos << endl;
        cout << "Enter C for Caramel price " << caramel_popcorn << endl;
        cout << "Enter your option: ";
        cin >> selection;
        if(selection == 'S'){
            total_popcorn += simple_popcorn;
        }
        else if(selection == 'T'){
            total_popcorn += tacos;
        }
        else if(selection == 'C'){
            total_popcorn += caramel_popcorn;
        }
        else{
            cout << "Invalid Input! " << endl;
            cin >> selection;
        }


    }

    cout << "Amount used for movie = " << total_movie << endl;
    cout << "Amount used for popcorn = " << total_popcorn << endl;
    cout << "Total amount = " << total_movie + total_popcorn << endl;

    
    return 0;
}