#include <iostream>
using namespace std;

int main(){
    int length, width;
    cout << "Enter Length of Rectangle: ";
    cin >> length;
    cout << "Enter Width of Rectangle: ";
    cin >> width;

    cout << "Area of Rectangle: ";
    cout << length * width << endl;
    cout << "Perimeter of Rectangle: ";
    cout << 2 * (length + width) << endl;

    system("pause");
    return 0;
}