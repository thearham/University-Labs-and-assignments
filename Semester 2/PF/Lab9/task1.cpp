#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	float length, width, radius;
	char firstName[20], lastName[20];
	int age, balance;
	float interestRate;
	char Letter;
	
	ifstream inFile("inData.txt");
	
	inFile >> length >> width;
	inFile >> radius;
	inFile >> firstName >> lastName >> age >> balance >> interestRate;
	inFile >> Letter;
	
	inFile.close();
	
	ofstream outFile("outData.txt");
	
	float area = length * width;
	float parameter = 2 * (length + width);
	float circleArea = (3.1416) * (radius * radius);
	float circleCircumference = 2 * (3.1416) * radius;
	float profitBalance = balance + (balance * interestRate) / 100;
	int ASCII = int(Letter);
	
	outFile << "Rectangle: Length = " << length << ", width = " << width << ", area = " << area << ", parameter = " << parameter << endl;
	outFile << "Circle: Radius = " << radius << ", area = " << circleArea << ", circumference = " << circleCircumference << endl;
	outFile << "Name: " << firstName << " " << lastName << ", age: " << age << ", Beginning balance = $" << balance << ", interest rate = " << interestRate << endl;
	outFile << "Balance at the end of the month = $" << profitBalance << endl;
	outFile << "The character that comes after " << Letter << " in the ASCII set is " << char(ASCII + 1) << endl;
	
	outFile.close();
	
	return 0;
} 
