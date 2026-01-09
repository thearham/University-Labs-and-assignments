#include <iostream>
#include <fstream>
using namespace std;
void function(char array[]){
    cout<<endl;
  ofstream fout("Output.txt");
  if (array[0] == array[0]=='a'||array[0]=='e'||array[0]=='i'||array[0]=='o'||array[0]=='u')
      {
          for(int j=0;array[j]!=' ';j++){
                  cout<<array[j];
                  fout<<array[j];
                  
              }   
              cout<<" ";
              fout<<" ";
          }
      
  int i=0;
  for(i=0;array[i]!='\0';i++){
      
      
  
      if(array[i]==' '){
          
          if(array[i+1]=='a'||array[i+1]=='e'||array[i+1]=='i'||array[i+1]=='o'||array[i+1]=='u'){
              for(int j=i+1;array[j]!=' ';j++){
                  cout<<array[j];
                  fout<<array[j];
                  
              }   
              cout<<" ";
              fout<<" ";
          }
       
      }
  }
  fout.close();
 
}
int main()
{
  ifstream fin;
  fin.open("input.txt");
  char arr[100];
  fin.getline(arr,100,'\0');
  cout<<arr;
  fin.close();
  function(arr);
    return 0;
}
