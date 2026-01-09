#include <iostream>
using namespace std;

int main(){
     int n, n1 = 0, n2 = 1, nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        
        if(i == 1) {
            cout << n1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << n2 << ", ";
            continue;
        }
        nextTerm = n1 + n2;
        n1 = n2;
        n2 = nextTerm;
        
        cout << nextTerm << ", " ;
    }
    cout << endl;
    system("pause");
    return 0;
}