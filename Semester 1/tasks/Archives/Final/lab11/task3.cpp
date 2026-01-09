#include <iostream>
using namespace std;
int main()
{
   int size;
   cout<<"Enter the size of array::";
   cin>> size;
   int randArray[size];
   for(int i=0; i<size; i++)
      randArray[i] = rand() % 100;  //Generate number between 0 to 99
  
   cout<<"\nElements of the array::"<<endl;
  
   for(int i=0; i<size; i++)
      cout<< "Elements no "<< i+1 << "::" <<randArray[i]<<endl;
   return 0;
}