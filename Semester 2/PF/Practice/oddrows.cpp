#include <iostream>
using namespace std;

void getOddRows(int **source, int size)
{
    
    int **OddArr = new int*[size/2];
    for (int i = 0; i < size/2; i++)
    {
        OddArr[i] = new int[size];
    }
     
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 0; j < size; j++)
            {
                OddArr[k][j] = source[i][j];
            }
            k++;
        }
    }
    
    cout << "Odd Rows: \n";
    for (int i = 0; i < size / 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << OddArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int size;
    cout << "Enter size of 2d array: ";
    cin >> size;
    int **twoD = new int*[size];
    for (int i = 0; i < size; i++)
    {
        twoD[i] = new int[size];
    }

    cout << "Enter the elements of 2d array: ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> twoD[i][j];
        }
        
    }
    getOddRows(twoD,size);
    return 0;
}