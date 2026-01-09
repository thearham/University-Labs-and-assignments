#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // declare an array of 50 components of type double
    double array[50];

    // initialize the first 25 elements with the square of the index variable
    for (int i = 0; i < 25; i++)
        array[i] = pow(i, 2);

    // initialize the last 25 elements with three times the index variable
    for (int i = 25; i < 50; i++)
        array[i] = 3 * i;

    // output the array with 10 elements per line
    for (int i = 0; i < 50; i++)
    {
        cout << array[i] << " ";

        // print a newline after every 10 elements
        if ((i + 1) % 10 == 0)
            cout << endl;
    }

    return 0;
}
