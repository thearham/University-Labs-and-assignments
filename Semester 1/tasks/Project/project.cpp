#include <iostream>
using namespace std;


const int maxStudents = 5;
const int subjects = 2;

int main() {
    int rollNumbers[maxStudents];
    int marksComputerScience[maxStudents];
    int marksMathematics[maxStudents];
    float percentages[maxStudents];
    char grades[maxStudents];

    char continueEnrolling;
    int enrolledStudents = 0;

    do {
        
        cout << "Enter Roll Number for student " << enrolledStudents + 1 << ": ";
        cin >> rollNumbers[enrolledStudents];

        do {
            cout << "Enter Marks for Computer Science (out of 100) for student " << enrolledStudents + 1 << ": ";
            cin >> marksComputerScience[enrolledStudents];
        } while (marksComputerScience[enrolledStudents] > 100);

        do {
            cout << "Enter Marks for Mathematics (out of 100) for student " << enrolledStudents + 1 << ": ";
            cin >> marksMathematics[enrolledStudents];
        } while (marksMathematics[enrolledStudents] > 100);


        percentages[enrolledStudents] = (marksComputerScience[enrolledStudents] + marksMathematics[enrolledStudents]) / 2.0;
        if (percentages[enrolledStudents] >= 90.0) {
            grades[enrolledStudents] = 'A';
        } else if (percentages[enrolledStudents] >= 80.0) {
            grades[enrolledStudents] = 'B';
        } else if (percentages[enrolledStudents] >= 70.0) {
            grades[enrolledStudents] = 'C';
        } else if (percentages[enrolledStudents] >= 60.0) {
            grades[enrolledStudents] = 'D';
        } else {
            grades[enrolledStudents] = 'F';
        }

        enrolledStudents++;

        if (enrolledStudents < maxStudents) {
            cout << "Do you want to continue enrolling students? (Y/N): ";
            cin >> continueEnrolling;
        } else {
            cout << "maxStudentsimum number of students enrolled. Exiting enrollment process.\n";
            continueEnrolling = 'N';
        }

    } while (continueEnrolling == 'Y' || continueEnrolling == 'y');


    cout << "\nStudent Data:\n";
    for (int i = 0; i < enrolledStudents; ++i) {
        cout << "\nStudent Roll Number: " << rollNumbers[i] << "\n";
        cout << "Marks for Computer Science: " << marksComputerScience[i] << "\n";
        cout << "Marks for Mathematics: " << marksMathematics[i] << "\n";
        cout << "Percentage: " << percentages[i] << "%\n";
        cout << "Grade: " << grades[i] << "\n";
    }


    char continueOperations;
    do {
        int operation;
        cout << "\nAdvanced Operations:\n";
        cout << "1. Update Roll Number of a particular Student.\n";
        cout << "2. Update marks of a particular student for CS.\n";
        cout << "3. Update marks for Mathematics.\n";
        cout << "4. Delete the record of a particular student.\n";
        cout << "5. End.\n";
        cout << "Enter your choice: ";
        cin >> operation;

        int rollToUpdate;
        int indexToUpdate;

        switch (operation) {
            case 1:
                cout << "Enter Roll Number of the student to update: ";
                cin >> rollToUpdate;
                for (int i = 0; i < enrolledStudents; ++i) {
                    if (rollNumbers[i] == rollToUpdate) {
                        cout << "Enter updated Roll Number for the student: ";
                        cin >> rollNumbers[i];
                        break;
                    }
                }
                break;
            case 2:
                cout << "Enter Roll Number of the student to update: ";
                cin >> rollToUpdate;
                for (int i = 0; i < enrolledStudents; ++i) {
                    if (rollNumbers[i] == rollToUpdate) {
                        cout << "Enter updated marks for Computer Science (out of 100): ";
                        cin >> marksComputerScience[i];
                        break;
                    }
                }
                break;
            case 3:
                cout << "Enter Roll Number of the student to update: ";
                cin >> rollToUpdate;
                for (int i = 0; i < enrolledStudents; ++i) {
                    if (rollNumbers[i] == rollToUpdate) {
                        cout << "Enter updated marks for Mathematics (out of 100): ";
                        cin >> marksMathematics[i];
                        break;
                    }
                }
                break;
            case 4:
                cout << "Enter Roll Number of the student to delete: ";
                cin >> rollToUpdate;
                for (int i = 0; i < enrolledStudents; ++i) {
                    if (rollNumbers[i] == rollToUpdate) {
                        for (int j = i; j < enrolledStudents - 1; ++j) {
                            rollNumbers[j] = rollNumbers[j + 1];
                            marksComputerScience[j] = marksComputerScience[j + 1];
                            marksMathematics[j] = marksMathematics[j + 1];
                            percentages[j] = percentages[j + 1];
                            grades[j] = grades[j + 1];
                        }
                        enrolledStudents--;
                        break;
                    }
                }
                break;
            case 5:
                cout << "Exiting advanced operations.\n";
                
                break;
            case 6:
                
                break;
            default:
                cout << "Invalid choice.\n";
        }

        cout << "Do you want to continue with advanced operations? (Y/N): ";
        cin >> continueOperations;

    } while (continueOperations == 'Y' || continueOperations == 'y');


    cout << "\nFinal Student Data:\n";
    for (int i = 0; i < enrolledStudents; ++i) {
        cout << "\nStudent Roll Number: " << rollNumbers[i] << "\n";
        cout << "Marks for Computer Science: " << marksComputerScience[i] << "\n";
        cout << "Marks for Mathematics: " << marksMathematics[i] << "\n";
        cout << "Percentage: " << percentages[i] << "%\n";
        cout << "Grade: " << grades[i] << "\n";
    }

    return 0;
}
