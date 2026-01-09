#include <iostream>
using namespace std;

int main(){
    int n, i;
    float series, sum = 0;
    cout << "Input n: ";
    cin >> n;

    cout << "Series: " << endl;
    for(i = 1; i<= n; i++){
        if(i%2 == 0){
           cout << "1/" << i  << endl;
           sum = sum + (1.0/(i));

        }
        

    }
    cout << "Sum = " << sum << endl;
    

    system("pause");
    return 0;
}