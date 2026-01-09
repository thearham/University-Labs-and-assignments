#include <iostream>
using namespace std;

void avgOfMatrixCols(const int source[][3], int destination[])
{
    int rowSize = 3, colSize = 3;
    int sum, avg;
    
    for (int i = 0; i < colSize; i++)
    {
        sum = 0;
        for (int j = 0; j < rowSize; j++)
        {
            sum+= source[j][i];
        }
        avg = sum / colSize;
        destination[i] = avg;
    }
    for (int i = 0; i < rowSize; i++)
    {
        cout << destination[i] << " ";
    }
    
    

}

int main(){
    int twoD[3][3] = {{1,2,3},
                      {4,5,6},
                      {7,8,9}};
    
    int avg[3];

    avgOfMatrixCols(twoD,avg);
    return 0;
}