#include <iostream>
using namespace std;

int main(){
    
    for(int i = 5; i>=1; i--){
        for(int j = 5; j>=1; j--){
            if(i+j == 6){
                cout << "#";
            }
            else
                cout << "O";
        }
        cout << endl;
    }
    
    return 0;
}