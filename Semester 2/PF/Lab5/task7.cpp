#include <iostream>
using namespace std;

float average(float, float, float);
int main(){
    float x,y,z;

    cout << "Enter x = ";
    cin >> x;
    cout << "Enter y = ";
    cin >> y;
    cout << "Enter z = ";
    cin >> z;

    cout << "Average = : " << average(x,y,z) << endl;
    
    system("pause");
    return 0;
}
float average(float x, float y, float z){
    return (x+y+z)/3;
}