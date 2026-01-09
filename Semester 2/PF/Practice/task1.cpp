#include <iostream>
#include <fstream>
using namespace std;

int dataSize(){
    ifstream fin("task1.txt");
    char nums;
    int size = 0;

    while(fin >> nums){
        size++;
    }
    fin.close();
    //fin.clear();
    //fin.seekg(0, ios::beg);
    return size;
}

void getData(char *(&arr), int size){
    ifstream fin("task1.txt");
    char nums;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        fin >> arr[i];
    }
    fin.close();
}

void ConsecutiveOnes(char *arr, int &maximumOnes, int &maximumStartingIndex, int size){
    int currentOnes = 0, startIndex = 0, index = 0; 
    while (index < size)
    {
        if (arr[index] == '1')
        {
            currentOnes++;
            if (currentOnes == 1)
            {
                startIndex = index;
            }   
        }
        else
        {
            if (currentOnes > maximumOnes)
            {
                maximumOnes = currentOnes;
                maximumStartingIndex = startIndex; 
            }
            currentOnes = 0;
        }
        index++;
    }
}

int main(){
    int size = dataSize();
    char *array = new char[size];
    getData(array, size);
    int maximumOnes = 0, maximumStartingIndex = 0;
    ConsecutiveOnes(array, maximumOnes, maximumStartingIndex, size);

    cout << "Maximum consecutive ones are: ";
    for (int i = maximumStartingIndex; i < maximumStartingIndex + maximumOnes;  i++){
        cout << array[i];
    } 
    cout << "\n";
    cout << "Starting index is: " << maximumStartingIndex << endl;
    cout << "Length is: " << maximumOnes << endl;

    delete[] array;
    return 0;


}