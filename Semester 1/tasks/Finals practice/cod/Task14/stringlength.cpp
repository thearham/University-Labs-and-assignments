#include <iostream>
using namespace std;

int main(){
    char str[100];
    int count = 0;



    cout<< "enter string ";
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++)
    {
        ++count;
        
    }
    cout << "length = " << count <<endl;
    

    
    return 0;
}