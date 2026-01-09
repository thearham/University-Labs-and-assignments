#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Courses 
{
	string courseCode;
	int CreditHours;
	string courseTitle;
};

struct Enrollment {
	string studentId;
	string courseCode;
	string section;
	int creditHours;
};

void Menu()
{
	cout << "***************Menu*****************\n";
	cout << "Press 1 for the enrollment of student in a course\n";
	cout << "Press 2 for drop a specified course.\n";
	cout << "Press 3 for Display Students Enrolled Courses.\n";
	cout << "Press 4 for Update Section of Student for enrolled Course.\n";
	cout << "Press 5 for Display Total number of Students enrolled in particular course.\n";
	cout << "Press 6 for Display course not enrolled by any student.\n";
	cout << "Press 7 for Display the Student with minimum number of registered course.\n";
}

void Enrollments(Enrollment enrollment[], string id,Courses courses[], int &numberOfEnrollments)
{
	string courseCodes, courseTitles, selectedCourse;
	int creditHour;
	string section;
	bool check = false;
	cout << "Enter your ID: ";
	cin >> id;
	cout << "select from following courses: \n";
	ifstream file("courses.txt");
	int i = 0;
	while (file >> courseCodes >> creditHour)
	{
		getline(file, courseTitles);
		courses[i].courseCode = courseCodes;
		courses[i].CreditHours = creditHour;
		courses[i].courseTitle = courseTitles;
		cout << "\t" << courseCodes << " " << creditHour << " " << courseTitles << "\n";
		i++;
	}
	jump:
	cout << "\nEnter the course code: ";
	cin >> selectedCourse;
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (selectedCourse == courses[i].courseCode) {
			cout << "Congratulations you are successfully enrolled in " << selectedCourse << " with " << courses[i].CreditHours << " credit hours!\n";
			index = i;
			check = true;
			break;
		}
		
	}
	if (!check)
	{
		cout << "The course code you entered is not right!!!\n";
		cout << "Enter the course code again!\n";
		goto jump;
	}

	cout << "Enter the section from A to E: ";
	cin >> section;
	
	enrollment[numberOfEnrollments].studentId = id;
	enrollment[numberOfEnrollments].courseCode = selectedCourse;
	if (section <= "E")
	{
		enrollment[numberOfEnrollments].section = section;
	}
	else
	{
		cout << "Enter the section from A to E again: ";
		cin >> section;
		enrollment[numberOfEnrollments].section = section;	
	}
	
	
	enrollment[numberOfEnrollments].creditHours = courses[index].CreditHours;
	numberOfEnrollments++;
	for (int i = 0; i < numberOfEnrollments; i++)
	{
		if (enrollment[i].section != section && enrollment[i].studentId == id) {
			cout << "Cannot enroll into multiple sections! \n";
			break;
		}
		else if(section > "E")
		{
		cout << "Invalid Section!\n";
		break;
		}
		else
		{
			cout << "You are enrolled successfully! \n";
			break;
		}
	}
	
}

void Dropping(Enrollment enrollment[], int &numberOfEnrollments, string id)
{
	string selectedCourse;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter the course code you want to drop: ";
	cin >> selectedCourse;
	for (int i = 0; i < numberOfEnrollments - 1; i++)
	{
		if (enrollment[i].studentId == id && enrollment[i].courseCode == selectedCourse) {
			enrollment[i] = enrollment[i + 1];
			numberOfEnrollments = i;
		}
		else
		{
			cout << "The course is not registered!\n";
		}
	}
	
}

void DisplayStudentsEnrolled(Enrollment enrollment[], int numberOfEnrollments)
{
	cout << "Following students are enrolled\n\n";
	for (int i = 0; i < numberOfEnrollments; i++) {
		cout << "Student Id: " << enrollment[i].studentId << "\tCourse Code:" << enrollment[i].courseCode << "\n";
	}
}

void UpdateSection(Enrollment enrollment[], int numberOfEnrollments, string id)
{
	string selectedCourse, section;
	cout << "\nEnter the id: ";
	cin >> id;
	cout << "\nEnter the course Code: ";
	cin >> selectedCourse;
	cout << "\nEnter the new Section: ";
	cin >> section;
	for (int i = 0; i < numberOfEnrollments; i++)
	{
		if (enrollment[i].studentId == id && enrollment[i].courseCode == selectedCourse) {
			enrollment[i].section = section;
			break;
		}
		else
		{
			cout << "The course is not registered!\n";
		}
	}
}

void TotalStudentsInCourse(Enrollment enrollment[], int numberOfEnrollments)
{
	string courseCode;
	int students = 0;
	cout << "\nEnter the course code: ";
	cin >> courseCode;
	for (int i = 0; i < numberOfEnrollments; i++)
	{
		if (enrollment[i].courseCode == courseCode) {
			students++;
		}
	}
	cout << "The total number of students enrolled in course " << courseCode << " are: " << students << "\n";
}

void CourseNotEnrolled(Enrollment enrollment[], int numberOfEnrollments, Courses courses[])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < numberOfEnrollments; j++)
		{
			if (enrollment[j].courseCode != courses[i].courseCode) {
				cout << courses[i].courseCode << endl;
			}
		}
	}
}

void studentWithMinimumCourses(Enrollment enrollments[], int numberOfEnrollments) {
	int minimumCourses = numberOfEnrollments;
	string minimumStudent;

	for (int i = 0; i < numberOfEnrollments; i++) {
		int currentStudentCourses = 0;
		string currentStudent = enrollments[i].studentId;
		for (int j = 0; j < numberOfEnrollments; j++) {
			if (enrollments[j].studentId == currentStudent) {
				currentStudentCourses++;
			}
		}
		if (currentStudentCourses < minimumCourses) {
			minimumCourses = currentStudentCourses;
			minimumStudent = currentStudent;
		}
	}
	cout << "Student with minimum courses registered: " << minimumStudent << " (" << minimumCourses << " courses)\n";
}

int main()
{
	Courses courses[5];
	Enrollment enrollment[50];
	char continueCheck;
	int choices;
	int numberOfEnrollments = 0;
	string id;
	
	Menu();
		
	do
	{
		cout << "Enter a choice: ";
		cin >> choices;
		cout << "\n";
		if (choices == 1)
		{
			Enrollments(enrollment, id, courses, numberOfEnrollments);
		}
		if (choices == 2)
		{
			Dropping(enrollment,numberOfEnrollments,id);
		}
		if (choices == 3)
		{
			DisplayStudentsEnrolled(enrollment, numberOfEnrollments);
		}
		if (choices == 4)
		{
			UpdateSection(enrollment, numberOfEnrollments, id);
		}
		if (choices == 5)
		{
			TotalStudentsInCourse(enrollment, numberOfEnrollments);
		}
		if (choices == 6)
		{
			CourseNotEnrolled(enrollment, numberOfEnrollments, courses);			
		}
		if (choices == 7)
		{
			studentWithMinimumCourses(enrollment, numberOfEnrollments);
		}

		cout << "Enter 'Y' to continue or 'N' to exit: ";
		cin >> continueCheck;

	} while (continueCheck == 'Y' || continueCheck == 'y');
	
	return 0;
}