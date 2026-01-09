#include <iostream>
#include <vector>

void sortRGB(std::vector<char>& arr) {
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 'R':
                std::swap(arr[low++], arr[mid++]);
                break;
            case 'G':
                mid++;
                break;
            case 'B':
                std::swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    std::vector<char> arr = {'R', 'B', 'G', 'B', 'G', 'R', 'R', 'G', 'B', 'R', 'G', 'B'};
    sortRGB(arr);
    
    for (char c : arr) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}

