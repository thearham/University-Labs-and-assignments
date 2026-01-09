#include <iostream>
using namespace std;

int main(){
    int arr[4] = {3,5,2,1};
    for(int i = 0; i<= 4; i++){
        for(int j = 0; j <=4; j++){
            if(arr[j] > arr[j+1]){
                int z = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = z;
            }
        }
    }
    for(int i = 0; i< 4; i++ ){
        cout << arr[i] << endl;
    }
    
    
    return 0;
}
