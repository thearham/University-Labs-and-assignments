#include <iostream>
using namespace std;

int main(){
    int n, i, numbers, pos_sum = 0, neg_sum = 0;
    cout << "How many numbers you want to input: ";
    cin >> n;

    for(i=1; i<=n; i++){
        cout << "Enter number " << i << " = ";
        cin >> numbers;

        if(numbers < 0){
            neg_sum ++;
        }
        else{
            pos_sum ++;
        }
    }
    cout << "Number of positive values entered = " << pos_sum << endl;
    cout << "Number of negative values entered = " << neg_sum << endl;

    system("pause");
    return 0;
}