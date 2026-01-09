#include <iostream>
using namespace std;

int countPairs(int arr[], int size)
{
    int j = size - 1, count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        j = size - 1;
        while (j > i)
        {
            if (arr[i] == arr[j])
            {
                count++;
                j--;
            }
            else
            {
                j--;
            }
        }
    }
    return count;
}

int main()
{
    int arr[9] = {1,2,1,2,1,2,1,2,4};
    int x = countPairs(arr,9);
    cout << x << endl;
    return 0;
}