#include <iostream>
using namespace std;

void twoD(int **arr, int size[]){
    cout << "From function: \n";
    for (int i = 0; i < 3; i++)
    {
        //int *row = arr[i];
        for (int j = 0; j < size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int size[3] = {4,2,1};
    /*for (int i = 0; i < 3; i++)
    {
        cout << "Enter the size of row " << i+1 << " : ";
        cin >> size[i];
    }*/
    int row0[] = {4,3,2,1};
    int row1[] = {3,5};
    int row2[] = {1};
    
    int *arr[3] = {row0, row1,row2};
    
    for (int i = 0; i < 3; i++)
    {
        //int *row = arr[i];
        for (int j = 0; j < size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    int **dptr = arr;
    twoD(dptr, size);
    
    
    
    return 0;
}