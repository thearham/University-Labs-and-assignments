#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void enroll(string [][3], string [][4], int);
void drop(string [][3], string [][4], int);
void totals(string [][4], int);
void changesection(string [][4], int);
void coursecount(string [][4], int);
void coursenotenrolled(string [][4], string [][3], int );
void coursewithminstudents(string [][4], int);


int main(){

    cout << "***************Menu*****************" << endl;
	cout << "Press 1 for the enrollment of student in a course" << endl;
	cout << "Press 2 for drop a specified course." << endl;
	cout << "Press 3 for Display Students Enrolled Courses." << endl;
	cout << "Press 4 for Update Section of Student for enrolled Course." << endl;
	cout << "Press 5 for Display Total number of Students enrolled in particular course." << endl;
	cout << "Press 6 for Display course not enrolled by any student." << endl;
	cout << "Press 7 for Display the Student with minimum number of registered course." << endl;

    string courses[5][3], students[50][4];
    int total = 0;
    int select;
    char repeat;

    do
    {
        cout << "Enter a selection = ";
        cin >> select;
        if (select == 1)
        {
            enroll(courses, students, total);
        }
        if (select == 2)
        {
            drop(courses, students, total);
        }
        if (select == 3)
        {
            totals(students, total);
        }
        if (select == 4)
        {
            changesection(students, total);
        }
        if (select == 5)
        {
            coursecount(students,total);
        }
        if (select == 6)
        {
            coursenotenrolled(students, courses, total);
        }
        if (select == 7)
        {
            coursewithminstudents(students, total);
        }       
        
        cout << "Press Y to continue = ";
        cin >> repeat;

    } while (repeat == 'Y');
    


    return 0;
}

void enroll(string courses[][3], string students[][4], int total){
    string code, title, section, id, selectcourse,chour;
    ifstream fin("courses.txt");
    int x = 0;
    while (fin >> code >> chour)
    {
        getline(fin, title);
        courses[x][0] = code;
        courses[x][1] = chour;
        courses[x][2] = title;
        x++;
    }
    cout << "Input id =  ";
    cin >> id;
    cout << "select a course = " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << courses[i][0] << " " << courses[i][1] << " " << courses[i][2] << " " << courses[i][3] << endl;
    }
    cout << endl << "Enter= ";
    cin >> selectcourse;
    int s = 0;
    for (int i = 0; i < 4; i++)
    {
        if (selectcourse == courses[i][0])
        {
            cout << "You are enrolled." << endl;
            s = i;
            break;
        }
        
    }

    cout << "Enter Section Name = ";
    cin >> section;
    students[total][0] = id;
    students[total][1] = selectcourse;
    students[total][2] = section;
    students[total][3] = courses[s][1];
    total++;
    for (int i = 0; i < total; i++)
    {
        if (students[i][2] != section && students[i][0] != id)
        {
            cout << "Enrollment in different sections not allowed!" << endl;
            break;
        }
        else
        {
            cout << "You are enrolled!" << endl;
            break;
        }
    }
}
void drop(string courses[][3], string students[][4], int total){
        string selectcourse, id;
        cout << "Enter Id = ";
        cin >> id;
        cout << "Enter course to drop = ";
        cin >> selectcourse;
        int temp = 0;
        for (int i = 0; i < total - 1; i++)
        {
            if (students[i][0] == id && students[i][1] == selectcourse)
            {
                students[i][0] = students[i+1][0];
                students[i][1] = students[i+1][1];
                students[i][2] = students[i+1][2];
                students[i][3] = students[i+1][4];
                temp++;
                
            }
            else
            {
                cout << "Course is not enrolled." << endl;
            }
        }
        total -= temp;
        
}
void totals(string students[][4], int total){
    cout << "Enrolled Students are = " << endl;
            for (int i = 0; i < total; i++)
            {
                cout << students[i][0] << "  " << students[i][1] << endl;
            }
}
void changesection(string students[][4], int total){
    string  section, id, selectcourse;
    cout << "Enter id = ";
    cin >> id;
    cout << "Enter course = ";
    cin >> selectcourse;
    cout << "Enter section = ";
    cin >> section;
    for (int i = 0; i < total; i++)
    {
        if (students[i][0] == id && students[i][1] == selectcourse)
        {
            students[i][2] = section;
            break;
        }
        else
        {
            cout << "Course not enrolled." << endl;
        }
    }
}
void coursecount(string students[][4], int total){
    string selectcourse;
    int count = 0;
    cout << "Enter code = ";
    cin >> selectcourse;
    for (int i = 0; i < total; i++)
    {
        if (students[i][1] == selectcourse)
        {
            count++;
        }
        cout << "Total students in course = " << count << endl;
    }
}
void coursenotenrolled(string students[][4], string courses[][3], int total){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < total; j++){
            if (students[j][1] != courses[i][0]){
                cout << courses[i][0] << endl;
            }   
        }
    }
}
void coursewithminstudents(string students[][4], int total){
    int min = total;
    string minstudents;
    for (int i = 0; i < total; i++){
        int current = 0;
        string curstudent = students[i][0];
        for (int j = 0; j < total; j++)
        {
            if (students[i][0] == curstudent)
            {
                current++;
            }
        }
        if (current < min)
        {
            min = current;
            minstudents = curstudent;
        }
    }
    cout << "Minimum courses are of = " << minstudents << " with" << min<< " course" << endl;
}