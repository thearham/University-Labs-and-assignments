#include <iostream>
using namespace std;

int main(){
    int n, i, iterations = 0;

    cout << "Input n: ";
    cin >> n;

    do{
        for(i = 1; i<= n; i++){
            if(n%2 == 0){
                n = n/2;
            }
            else if(n%2 != 0){
                n = (3 * n) + 1;
            }
            cout << i << ". " << n << endl;
        }
        if(n == 1){
            break;
        }

    }while(true);

    
    return 0;
}