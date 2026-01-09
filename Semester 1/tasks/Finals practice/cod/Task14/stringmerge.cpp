#include <iostream>
using namespace std;

int main(){
    char str1[100], str2[100], str3[100];
    int i,k;
    cout << "string 1 = ";
    cin >> str1;
    
    cout << "string 2 = ";
    cin >> str2;
    
    for (i = 0; str1[i] != '\0' ; i++)
    {
        str3[i] = str1[i];
    }
    k = i;
    for ( i = 0; str2[i] != '\0'; i++)
    {
        str3[k] = str2[i];
    }
    
    for ( i = 0; str3[i] != '\0' ; i++)
    {
        cout << str3[i];
    }
    
    return 0;
}