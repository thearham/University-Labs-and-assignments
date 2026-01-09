#include <iostream>
using namespace std;
   
int main(){
    int arr[100], count, i, num;
       
    cout << "Enter Number of Elements in Array\n";
    cin >> count;
     
    cout << "Enter " << count << " numbers in array \n";
      
    
    for(i = 0; i < count; i++){
        cin >> arr[i];
    }
      
    cout << "Enter a number to serach in Array\n";
    cin >> num;
      
    
    for(i = 0; i < count; i++){
        if(arr[i] == num){
            arr[i] = 0;
        }
    }
      
    if(i == count){
        cout  << "Element Not Present in Input Array\n";
    }
    cout << "Modified array = ";
    for(i=0; i < count; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}