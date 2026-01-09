#include <iostream>
using namespace std;

int main(){
    int i,students = 5, arr[20], index, max_marks = 0, max_id = 0, lowest_marks = 0, lowest_id = 0 , sum = 0;
    int average, id;
    for (i = 0; i < 5 ; i++)
    {
        cout << "Enter Marks: ";
        cin >> arr[i]; 
    }
    
        for (i = 0; i < students ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (i = 0; i < students; i++)
    {   // task a:
        if(arr[0] < arr[i]){
            arr[0] = arr[i];
            max_marks = arr[0];
            max_id = i;
        }
        // task b:
        else if(arr[0] > arr[i]){
            arr[0] = arr[i];
            lowest_marks = arr[0];
            lowest_id = i;
        }
    }
    cout << "The highest marks are: " << max_marks << " and the index = " << max_id << endl;
    cout << "The lowest marks are: " << lowest_marks << " and the index = " << lowest_id << endl;
    
    //task d:
    for(i = 0; i < 5; i++){
        sum += arr[i];
        average = sum / students;
        if(arr[i] < sum){
            id = i;
        }
    }
    cout << "The average marks are: " << average << endl;
    cout << "The id's of students with marks lower than average = " << id << " " << endl;

    //task e:
    arr[2] = (arr[0] + arr[1]) - 2;
    cout << "Updated array = ";
    for (i = 0; i < students; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //task f:
    for (i = 0; i < students; i++)
    {
        for (int j = 0; j < students; i++)
        {
            if(arr[j] > arr[j+1]){
                int z = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = z;
        }
        
    }
    cout << "Sorted array = ";
    for (i = 0; i < students; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    



    system("pause");
    return 0;   
}
