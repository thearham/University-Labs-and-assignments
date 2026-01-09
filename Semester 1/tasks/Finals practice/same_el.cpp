#include <iostream>
using namespace std;
int main(){

    int inner[5], outter[5];
    bool arraysEqual = true;
    int count = 0;

    cout << "Enter array 1: ";
    for(int i = 0; i < 5; i++){cin >> inner[i];}

    cout << "Enter array 2: ";
    for(int i = 0; i< 5; i++){cin >> outter[i];}
    int swap;
    do
    {
        swap = false;
        for (int i = 0; i < 4; i++)
        {
            if(outter[i] > outter[i+1]){
                int temp = outter[i];
                outter[i] = outter[i+1];
                outter[i+1] = temp;
                swap = true;
            }
        }
        
        
    } while (swap);
    
    


    while (arraysEqual && count < 5)
    {
        if (inner[count] != outter[count])
        {
            arraysEqual = false;
            count++;
        }
        
    }
    

    if(arraysEqual)
        cout << "True" << endl;
    else
        cout << "false" << endl;
    

    
    return 0;
}