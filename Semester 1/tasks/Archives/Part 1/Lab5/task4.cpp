#include <iostream>
using namespace std;

int main(){
    int sub1, sub2, sub3, sub4, sub5;
    int Total_marks = 500; 
  

    cout << "Enter marks of subject 1 = ";
    cin >> sub1;
    cout << "Enter marks of subject 2 = ";
    cin >> sub2;
    cout << "Enter marks of subject 3 = ";
    cin >> sub3;
    cout << "Enter marks of subject 4 = ";
    cin >> sub4;
    cout << "Enter marks of subject 5 = ";
    cin >> sub5;

    int sum = sub1 + sub2 + sub3 + sub4 + sub5;

    cout << "Sum of all subjects = ";
    cout << sum << endl;

    float percentage = (sum*100)/Total_marks;

    cout << "Percentage = ";
    cout << percentage << " %" << endl;

    if(percentage >= 50 && percentage <=90){
        cout << "Pass" << endl;
    }
        else if(percentage >= 90){
            cout << "Pass, Well Done!" << endl;
    }
    else{
        cout << "Fail!" << endl;
    }

    system("pause");
    return 0;

}