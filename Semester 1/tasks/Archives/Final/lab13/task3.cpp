#include <iostream>
using namespace std;

int main(){
    float arr[5];
    cout << "Input students height = ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cout << "Student height listed on above 5 inches are = ";
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] >= 5.0)
        {
            cout << arr[i] << " ";
        }
        
    }
    cout << endl;
    
    system("pause");
    return 0;
}