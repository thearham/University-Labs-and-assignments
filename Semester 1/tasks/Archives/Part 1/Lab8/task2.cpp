#include <iostream>
using namespace std;

int main(){
    int i,size = 10, number, max_number;
    cout << "Enter 10 numbers: " << endl;
    for(i=0; i<size; ++i){
        cout<< "Number " << i+1 << " = ";
        cin >> number; 

        if(i==0 || number > max_number){
            max_number = number;
        }      
    }
    cout << "Maximum number : " << max_number << endl;
    system("pause");
    return 0;
}