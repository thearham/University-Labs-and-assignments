#include <iostream>
using namespace std;

void table(int num){
    for(int i = 1; i <= 10; i++){
        cout << num << " * " << i << " = " << num * i << endl;
    }
}
float diameter(float radius){
    return 2 * radius;
}
float circumference(float radius1){
    return 2 * (22/7) * radius1;
}
float area(float radius2){
    return (22/7) * (radius2 * radius2);
}

int main(){
    int num, radius, radius1, radius2;

    cout << "Enter number: ";
    cin >> num;
    table(num);

    cout << "Enter radius = ";
    cin >> radius;
    cout << "Diameter: "<< diameter(radius) << "\n";

    cout << "Enter radius = ";
    cin >> radius1;
    cout <<"Circumference = "<< circumference(radius1) << "\n";

    cout << "Enter radius = ";
    cin >> radius2;
    cout <<"Area = "<< area(radius2) << "\n";
    
    system("pause");
    return 0;
}