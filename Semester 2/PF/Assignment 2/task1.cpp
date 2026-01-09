#include <iostream>
#include <fstream>
using namespace std;
char *removeDuplicate(char str[], int n)
{
   // Used as index in the modified string
   int index = 0;  
    
   // Traverse through all characters
   for (int i=0; i<n; i++) {
        
     // Check if str[i] is present before it 
     int j; 
     for (j=0; j<i; j++)
        if (str[i] == str[j])
           break;
      
     // If not present, then add it to
     // result.
     if (j == i)
        str[index++] = str[i];
   }
    
   return str;
}

int main(){
    ifstream data("data.txt");
    char names[100];
    int i =0;
    int size = 0;
    while (!data.eof())
    {
        i++;
        data >> names[i];
        //cout << names << " ";
        
    } 
    for (int i = 0; names[i] != '\0'; i++)
    {
        size++;
    }
        cout << removeDuplicate(names, size);
    
    
    
    
    

   
    return 0;
}