#include <iostream>
using namespace std;

int main(){
    int count = 6;
    int arr[count];
    int cnt = 0;

    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < count; i++)
    {
        if (arr[i] == 2)
        {
            cnt++;
        }
        
    }

    if(cnt * 2 == 8){
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
    

    



    
    return 0;
}