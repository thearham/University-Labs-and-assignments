#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a positive number: ";
    cin >> num;

    while(num < 0 || num == 0){
        cout << "Error! Input a postive number: ";
        cin >> num;
    }
    system("pause");    
    return 0;
}