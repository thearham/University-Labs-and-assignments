#include <iostream>
using namespace std;

int main(){
    int wind_speed;

    cout << "Input wind speed: ";
    cin >> wind_speed;

    if(wind_speed < 25){
        cout << "Not a strong wind\n";
    }
    else if(wind_speed >= 25 && wind_speed <= 38){
        cout << "Strong Wind\n";
    }
    else if(wind_speed >= 39 && wind_speed <= 54){
        cout << "Gale\n";
    }
    else if(wind_speed >= 55 && wind_speed <= 72){
        cout << "Whole Gale\n";
    }
    else{
        cout << "Hurricane\n";
    }
    
    system("pause");
    return 0;
}