#include<iostream>
using namespace std;
int main()
{
    char arr1[50], arr2[50];
    int i=0, check=0, check1 = 0;
    cout<<"Enter the First String: ";
    cin>>arr1;
    cout<<"Enter the Second String: ";
    cin>>arr2;
    
    for(int i =0; arr1[i] != '\0'; i++){
        check++;
    }
    for(int i =0; arr2[i] != '\0'; i++){
        check1++;
    }

    if(check < check1){
        cout << "String 2 is greater than string 1\n";
    }
    else{
        cout << "String 1 is greater than string 2\n";
    }
    return 0;
}