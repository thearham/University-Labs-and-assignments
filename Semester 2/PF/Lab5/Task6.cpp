#include <iostream>
using namespace std;

void Swap(int &, int &);

int main(){
    int x, y;
    cout << "Enter the value x = ";
    cin >> x;

    cout << "Enter the value y = ";
    cin >> y;
    cout << "Values after swapping: \n";
    Swap(x,y);
    cout << "Value of x = " << x << "\n";
    cout << "Value of y = " << y << "\n";
    
    system("pause");
    return 0;
}

void Swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}