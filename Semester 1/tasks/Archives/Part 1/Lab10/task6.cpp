#include <iostream>
using namespace std;

int main(){
    int k,n, result = 1;

    cout << "Input power value, n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;

    for(int i = 1; i<= k; ++i){
        result*=k;
        cout << n <<" power of " << i << " = " << result <<endl;
               
    }

    return 0;
}