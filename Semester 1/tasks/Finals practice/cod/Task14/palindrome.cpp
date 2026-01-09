#include <iostream>
using namespace std;

int main(){
    char str[100];
    int count = 0;
    bool check;

    cout << "Enter: ";
    cin>>str;

    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    for (int i = 0; i < count/2; i++)
    {
        if (str[i] != str[count - i - 1])
        {
            check = false;
        }
        else{
            check = true;
        }
        
    }
    if (check == true)
    {
        cout << "It is palindrome!" << endl;
    }
    else
        cout << "It is not a palindrome!" << endl;
    
    
    
    
    return 0;
}