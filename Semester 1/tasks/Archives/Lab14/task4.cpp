#include <iostream>
using namespace std;

int main(){
    char rand[20], a[20];
    cout << "Enter the character array: ";
    cin >> rand;

    cout << "Enter the word to search: ";
    cin >> a;
    int j;
    for(int i = 0; rand[i] != '\0'; i++){
        if (a[j] == rand[i]){
           j++;
        }
    }
    if(a[j] == '\0'){
        cout << "present in array!\n";
    }
    else{
        cout << "Not present!\n";
    }

    
    return 0;
}