#include <iostream>

// Function to process arrays A and B
void processArrays(int A[], int N, int B[], int M) {
    bool processed[10] = {false}; // to track numbers 0-9 if they have been processed

    for (int i = 0; i < N; ++i) {
        int num = A[i];
        if (num >= 0 && num <= 9 && !processed[num]) {
            processed[num] = true; // mark the number as processed
            for (int j = 0; j < M; ++j) {
                if (B[j] == num) {
                    B[j] = -1; // mark as deleted
                }
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    std::cout << "{";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    int A[] = {11, 6, 21, 4, -2, 12, 5, 7, 6, 21, 5, 6, 16, 7, 12, 88, -12, 0, 32, 45, 54};
    int B[] = {6, 2, 4, 7, 2, 5, 7, 6, 1, 8, 8, 6, 9, 9, 8};
    
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);

    processArrays(A, N, B, M);

    std::cout << "A = ";
    printArray(A, N);

    std::cout << "B = ";
    printArray(B, M);

    return 0;
}

