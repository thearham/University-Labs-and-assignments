#include <iostream>
using namespace std;

int main(){
    char str[100];
    int length = 0;
    cin >> str;
    

    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (str[j] > str[j+1])
            {
                int ch = str[j];
                str[j] = str[j+1];
                str[j+1] = ch;
            }
            
        }
        
    }
    for (int i = 0; str[i] != 0; i++)
    {
        cout << str[i];
    }
    
    
     
    
    return 0;
}