#include <iostream>
using namespace std;

int main(){
    int count = 7;
    int arr[count];
    int arr2[count];
    int sum = 0;
    int pos1,pos2;
    

    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }

    
    for (int i = 0; i < count; i++)
    {
        if(arr[i] == 6){
            pos1 = i;
            
        }
        if(arr[i] == 7){
            pos2 = i;
        }
        
        
        
    }
    for (int i = pos1; i <= pos2; i++)
    {
        arr[i] = 0;
    }
    
    
    
    
    
    
    for (int i = 0; i < count; i++)
    {
        arr2[i] = arr[i];
        sum  += arr2[i];
        
    }
    cout << sum << endl;
    
    
    return 0;
}