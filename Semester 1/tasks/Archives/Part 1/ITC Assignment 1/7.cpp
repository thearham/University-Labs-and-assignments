#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter a Character: ";
    cin >> ch;
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        cout << endl << ch << " is an Alphabet";
    else {
    cout << endl << ch << " is not an Alphabet";
    cout << endl;
    }
    return 0;
}