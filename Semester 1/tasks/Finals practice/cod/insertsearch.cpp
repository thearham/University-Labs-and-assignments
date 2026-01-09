#include <iostream>
using namespace std;

int main(){
    int arr[30], i,k, pos;
    int count;
    cout << "Enter the number of elements: ";
    cin>>count;

    cout << "Enter array: ";
    for (i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
    cout << "Enter k = ";
    cin >> k;

    int start = 0, end = count - 1;
    int middle = (start + end) / 2;

    while (start <= end)
    {
        if (arr[middle] < k)
        {
            start = middle + 1;
        }
        else if (arr[middle] == k)
        {
            cout << "element found at: " << middle << endl;
            break;
        }
        else
            end = middle - 1; 
        middle = (start + end) / 2;       
        
    }
    if (start > end)
    {
        for ( i = 0; i < count; i++)
        {
            
            if(arr[i] >= k){
                pos = i;
                break;
            }
        }
        cout << pos;
    }
    
    
    
    
    return 0;
}