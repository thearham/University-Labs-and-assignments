#include <iostream>
using namespace std;

int main(){
    int n1, n2,list, sum = 0;
    cout << "Input n1: ";
    cin >> n1;
    cout << "Input n2: ";
    cin >>n2;
    cout << "The sum of numbers from " << n1 << " to " << n2 << " is: ";
    while(n1 <= n2){
        list = n1++;
       
        sum += list;
    }
    
    cout << sum;
    cout << endl;
    system("pause");
    return 0;
}