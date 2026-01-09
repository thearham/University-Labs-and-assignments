#include <iostream>
using namespace std;

int main(){
    int n, numbers, i;
    float average,sum = 0;
    cout << "how many numbers you want to input: ";
    cin >> n;
    for(i=0; i<n;i++){
        cout << "Enter number " << i +1 << " : ";
        cin >> numbers;

        sum += numbers;
    }
    average = (sum) / (n);
    cout << "The average of numbers is: " << average << endl;

    system("pause");
    return 0;
}