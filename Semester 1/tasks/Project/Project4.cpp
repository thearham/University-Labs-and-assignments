#include<iostream>
using namespace std;

int main()
{
    const int size = 16;
    const int totalsize = 15;
    char array[size] = { 0 };
    int first[totalsize] = { 0 };
    int second[totalsize] = { 0 };
    int checksize;
    char check;
    cout << "Enter the first number: ";
    cin >> array;
    for (int counter = 0; array[counter] != '\0'; counter++)
    {
        first[counter] = array[counter] - 48;
        if (array[counter + 1] == '\0' && counter != totalsize - 1)
        {
            checksize = totalsize - 1;
            int temp = 0;
            int checkcounter = counter;
            for (int counter1 = 0; counter1 <= counter; counter1++)
            {
                temp = first[checkcounter];
                first[checkcounter] = first[checksize];
                first[checksize] = temp;
                checkcounter -= 1;
                checksize -= 1;
            }
        }
    }
    cout << "Enter the second number: ";
    cin >> array;
    for (int counter = 0; array[counter] != '\0'; counter++)
    {
        second[counter] = array[counter] - 48;
        if (array[counter + 1] == '\0' && counter != totalsize - 1)
        {
            checksize = totalsize - 1;
            int temp = 0;
            int checkcounter = counter;
            int counter1 = 0;
            for (int counter1 = 0; counter1 <= counter; counter1++)
            {
                temp = second[checkcounter];
                second[checkcounter] = second[checksize];
                second[checksize] = temp;
                checkcounter -= 1;
                checksize -= 1;
            }
        }
    }
    cout << "Press A for addition" << endl;
    cout << "Press S for subtraction" << endl;
    cout << "Press M for multiplication" << endl;
    cout << "Press D for division" << endl;
    cout << "Press R for remainder" << endl;
    cin >> check;
    switch (check)
    {
    case 'A':
    {
        int calcu[totalsize] = { 0 };
        int carry = 0;
        int temp = totalsize - 1;
        int set = 0;
        for (int counter = 0; counter < totalsize; counter++)
        {
            if (first[temp] + second[temp] > 9)
            {
                carry = (first[temp] + second[temp]) / 10;
                first[temp - 1] += carry;
                calcu[temp] = (first[temp] + second[temp]) % 10;
            }
            else
            {
                calcu[temp] = first[temp] + second[temp];
            }
            carry = 0;
            temp -= 1;
        }
        for (int counter = 0; counter < totalsize; counter++)
        {
            if (calcu[counter] != 0)
            {
                set = counter;
                counter = totalsize;
            }
        }
        for (int counter = set; counter < totalsize; counter++)
        {
            cout << calcu[counter];
        }
        break;
    }
    case 'S':
    {
        const int intsize = 15;
        int calcu[intsize] = { 0 };
        int temp = intsize - 1;
        int set = 0;

        for (int counter = 0; counter < intsize; counter++)
        {
            if (second[temp] > first[temp])
            {
                first[temp - 1] -= 1;
                first[temp] += 10;
                calcu[temp] = first[temp] - second[temp];
            }
           else
            {
               calcu[temp] = first[temp] - second[temp];
            }
            temp -= 1;
        }
        for (int counter = 0; counter < intsize; counter++)
        {
            if (calcu[counter] != 0)
            {
                set = counter;
                counter = intsize;
            }
        }
        for (int counter = set; counter < intsize; counter++)
        {
            cout << calcu[counter];
        }
        break;
    }
    case 'M':
    {
        int calculator[totalsize] = { 0 };
        int array[totalsize] = { 0 };
        int carry = 0;
        int temp = totalsize - 1;
        int temp1 = 0;
        int check = 0;
        int carry1 = 0;
        int check1 = totalsize - 1;
        int set = 0;

        while (temp >= 0)
        {
            for (int counter = totalsize - 1; counter >= 0; counter--)
            {
                if (first[counter] * second[temp] > 9)
                {
                    array[counter] = (first[counter] * second[temp]) % 10 + carry;
                    carry = 0;
                    carry = (first[counter] * second[temp]) / 10;
                }
                else
                {
                    array[counter] = (first[counter] * second[temp]) % 10 + carry;
                    carry = 0;
                }
                check += 1;
            }
            check -= 1;
            temp1 = temp;
            for (int counter1 = check; counter1 >= 0; counter1--)
            {
                if (array[check1] + calculator[temp1] > 9)
                {
                    carry1 = (array[check1] + calculator[temp1]) / 10;
                    calculator[temp1 - 1] += carry1;
                    calculator[temp1] = (calculator[temp1] + array[check1]) % 10;
                }
                else
                {
                    calculator[temp1] = array[check1] + calculator[temp1];
                }
                carry1 = 0;
                check1 -= 1;
                temp1 -= 1;
            }
            check = 0;
            temp -= 1;
            check1 = totalsize - 1;
        }
        for (int counter = 0; counter < totalsize; counter++)
        {
            if (calculator[counter] != 0)
            {
                set = counter;
                counter = totalsize;
            }
        }
        for (int counter = set; counter < totalsize; counter++)
        {
            cout << calculator[counter];
        }
        break;
    }
    case 'D':
    {
        int calcu[totalsize] = { 0 };
        int temp = 0;
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;
        int temp4 = 0;
        int check = 0;
        int check1 = 0;
        int set = 0;

        for (int counter = 0; counter < totalsize; counter++)
        {
            temp3 = temp3 + 1;
            if (second[counter] != 0 && check != 4)
            {
                temp3 = 0;
                check = 4;
            }
        }
        temp3 = temp3 + 1;
        for (temp1 = totalsize - temp3; temp1 < totalsize; temp1++)
        {
            temp2 = temp2 * 10 + second[temp1];
        }
        for (int counter = 0; counter < totalsize; counter++)
        {
            temp = temp * 10 + first[counter];
            if (counter < temp3)
            {
                temp4 = temp / temp2;
                temp3 += 1;
                temp = temp % temp2;
            }
            calcu[check1] = temp4;
            check1 += 1;
            temp4 = 0;
        }
        for (int counter = 0; counter < totalsize; counter++)
        {
            if (calcu[counter] != 0)
            {
                set = counter;
                counter = totalsize;
            }
        }
        for (int counter = set; counter < totalsize; counter++)
        {
            cout << calcu[counter];
        }
        break;
    }
    case 'R':
    {
        int calcu[totalsize] = { 0 };
        int temp = 0;
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;
        int temp4 = 0;
        int check = 0;
        int check1 = 0;

        for (int counter = 0; counter < totalsize; counter++)
        {
            temp3 = temp3 + 1;
            if (second[counter] != 0 && check != 4)
            {
                temp3 = 0;
                check = 4;
            }
        }
        temp3 = temp3 + 1;
        for (temp1 = totalsize - temp3; temp1 < totalsize; temp1++)
        {
            temp2 = temp2 * 10 + second[temp1];
        }
        for (int counter = 0; counter < totalsize; counter++)
        {
            temp = temp * 10 + first[counter];
            if (counter < temp3)
            {
                temp4 = temp / temp2;
                temp3 += 1;
                temp = temp % temp2;
            }
        }
        cout << temp;
        break;
    }
    }
    cout << endl;
    return 0;
}