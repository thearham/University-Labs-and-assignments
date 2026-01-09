#include <iostream>
#include <fstream>
using namespace std;

void copyArray(int [], int []);
int main(){
    int arr1[5] = {1,2,3,4,5}, arr2[5];

    copyArray(arr1, arr2);
    
    return 0;
}

void copyArray(int s_arr[], int d_arr[]){
    for (int i = 0; i < 5; i++)
    {
        d_arr[i] = s_arr[i];
    }

    ofstream myFile("output.txt");

    for (int i = 0; i < 5; i++)
    {
        myFile << s_arr[i] << " ";
    }
    myFile.close();
    
}