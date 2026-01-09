#include <iostream>
using namespace std;

int main(){
    int chicken, cow, horse, Total_legs;

    cout << "Enter the count of chickens: ";
    cin >> chicken;

    if(chicken > 0 ){
        chicken;
    }
    else{
        cout << "Must enter positive! " << endl;
        cout << "Renter the value: ";
        cin >> chicken;
    }

    cout << "Enter the count of cows: ";
    cin >> cow;

    if(cow > 0){
        cow;
    }
    else{
        cout << "Must enter positive! " << endl;
        cout << "Renter the value: ";
        cin >> cow;
    }

    cout << "Enter the count of horses: ";
    cin >> horse;

    if(horse > 0){
        horse;
    }
    else{
        cout << "Must enter positive!" << endl;
        cout << "Renter the value: ";
        cin >> horse;
    }  
   
       

    Total_legs = (chicken * 2) + (cow * 4) + (horse * 4);
    cout << "Total legs = " << Total_legs << endl;

    
     
    system("pause");    
    return 0;
}