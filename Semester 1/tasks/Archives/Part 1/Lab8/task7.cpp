#include <iostream>
using namespace std;

int main(){
    char input;
    do{
        cin >> input;
        if(input == 'X'){
            cout << "Exit" << endl;
            break;
        }
        if(input%2 == 0){
            cout << "It is even" << endl;
        }
        else{
            cout << "It is odd" << endl;
        }
    }while(true);
    
    system("pause");
    return 0;
}