#include <iostream>
using namespace std;

int main(){
    int arr[10];
    int count[10];
    int counter = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++)
    {
        counter = 0;
        for (int j = 0; j < 10; j++)
        {
            
            if (arr[i] == arr[j])
            {
                counter++;
                count[i] = counter;
            }
            
        }
        
    }
    for (int i = 0; i < 10; i++)
    {
        cout << count[i] << " ";
    }
    
    


    
    return 0;
}
