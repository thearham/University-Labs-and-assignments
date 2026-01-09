#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person();
    Person(string, int);
    void setAge(int);
    void setName(string);
    int getAge();
    string getName();
    void Info();    
};


