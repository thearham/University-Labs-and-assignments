#include<iostream>
using namespace std;


int main(){
    int sum, salespeople, sales[100];

    cout <<"Enter the number of salespeople: ";// tp get the number of salesperson
    cin >> salespeople;

    for(int i = 0; i < salespeople; i++){ // loop to get the sales of each person in array
        cout << "Enter sales for salesperson " << i+1 << ": ";
        cin >> sales[i];
    }
    sum = 0;
    for (int i = 0; i < salespeople; i++){
        sum += sales[i];
    }
    cout << "\nTotal sales:" << sum;
    return 0;
}
