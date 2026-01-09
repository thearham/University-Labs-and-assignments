#include <iostream>
using namespace std;

int main(){
    char str[100],i;

    cout << "enter string = ";
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        }
        
    }
    cout << "lower case = ";
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];
    }

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    cout <<  endl;
    cout << "reversed: ";
    for (i = count; i >= 0; i--)
    {
        cout << str[i];
    }    
    
    return 0;
}