#include <iostream>
using namespace std;

void newArrayWithNoDups(int arr1[], int N, int arr2[], int M, int C[], int &sizeC)
{
    int i = 0, j = 0;
    sizeC = 0;

    while (i < N && j < M)
    {
        while (i < N-1 && arr1[i] == arr1[i+1])
        {
            i++;
        }
        while (j < M-1 && arr2[j] == arr2[j+1])
        {
            j++;
        }

        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            C[sizeC++] = arr1[i];
            i++;
            j++;
        }        
    
    }

    while (sizeC < N+M)
    {
        C[sizeC++] = -1;
    }    
}

void printArray(int arr[], int size) {
    std::cout << "{";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    int A[] = {2, 2, 3, 6, 6, 6, 7, 8, 9, 21, 25, 210, 210};
    int B[] = {1, 1, 4, 4, 5, 7, 10, 11, 11, 17, 21, 29};
    
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);
    int C[N + M];
    int sizeC;

    newArrayWithNoDups(A, N, B, M, C, sizeC);

    std::cout << "C = ";
    printArray(C, sizeC);

    return 0;
}