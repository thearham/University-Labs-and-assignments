#include <iostream>
using namespace std;

const int MONTHS = 3;


void getData(int[][2]);
double avgHigh(int[][2]);
double avgLow(int[][2]);

int main() {
    int temperatures[MONTHS][2];

    getData(temperatures);

    cout << "The average high temperature for the year is: " << avgHigh(temperatures) << endl;
    cout << "The average low temperature for the year is: " << avgLow(temperatures) << endl;

    return 0;
}


void getData(int temperatures[][2]) {
    cout << "Enter the highest and lowest temperatures for each month:" << endl;
    for (int i = 0; i < MONTHS; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> temperatures[i][0] >> temperatures[i][1];
    }
}


double avgHigh(int temperatures[][2]) {
    double total = 0.0;
    for (int i = 0; i < MONTHS; i++) {
        total += temperatures[i][0];
    }
    return total / MONTHS;
}


double avgLow(int temperatures[][2]) {
    double total = 0.0;
    for (int i = 0; i < MONTHS; i++) {
        total += temperatures[i][1];
    }
    return total / MONTHS;
}
