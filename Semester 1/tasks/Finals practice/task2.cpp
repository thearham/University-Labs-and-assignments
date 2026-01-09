#include <iostream>
using namespace std;

int main(){
    int arr[4], t, f;

    cout << "arr: ";
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if(arr[i] == 2 || arr[i] == 3){
        
        }
        else if (arr[i] != 2 || arr[i] != 3)
        {
            cout << "False" << endl;
            break;
        }
        
    }
    
    
    
    return 0;
}