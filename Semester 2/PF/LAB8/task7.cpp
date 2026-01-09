#include <iostream>
using namespace std;

int main() {
  
  int numLabs;
  cout << "Enter the total number of labs in the university: ";
  cin >> numLabs;

  
  int *studentsInLab = new int[numLabs];

  
  for (int i = 0; i < numLabs; i++) {
    cout << "Enter the number of students in lab " << i + 1 << ": ";
    cin >> studentsInLab[i];
  }

  
  int totalStudents = 0;
  for (int i = 0; i < numLabs; i++) {
    totalStudents += studentsInLab[i];
  }

  
  float avgStudents = (float)totalStudents / numLabs;

  
  cout << "The average number of students in a lab is: " << avgStudents << endl;

  
  delete[] studentsInLab;

  return 0;
}
