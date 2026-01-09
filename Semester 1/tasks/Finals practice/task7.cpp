#include <iostream>
using namespace std;

int main(){
    int size = 5;
    int arr[size] = {1,4,10,-3};
    int target = 14;
    int num1, num2;

    for (int i = 0; i < size ; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                num1 = j;
                num2 = i;
            }
            
        }
        
    }
    cout << "[" << num1 << "," << num2 << "]" << " or [" << num2 << "," << num1 << "]" << endl;
    
    
    
    return 0;
}