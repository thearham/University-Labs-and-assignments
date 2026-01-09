#include <iostream>
using namespace std;

int main(){
    char arr[20] = {'a', 'B','v','%','/','1','s','h','^','5','3','#','h','s','Y','%','@','2','8'};
    char num, special , alpha ;
    
    for(int i = 0; arr[i] != '\0'; i++){
        if (arr[i] >= 0 && arr[i] <= 9)
        {
            num += arr[i];
        }
        else if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z') )
        {
            alpha += arr[i];
        }
        else
        {
            special += arr[i];
        }
        
    }
    cout << "Integers = " << num << " " << endl;
    cout << "Alphabets = " << alpha << " " << endl;
    cout << "Special characters = " << special << " " << endl;

    return 0;
}