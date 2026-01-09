#pragma once
#include "Person.h"
//default Constructors
Person::Person(){
    name = " ";
    age = 0;
}
Person::Person(string PersonName, int PersonAge){
    name = PersonName;
    age = PersonAge;
}
//setters:
void Person::setName(string PersonName){
    name = PersonName;
}
void Person::setAge(int PersonAge){
    age = PersonAge;
}
//getters:
string Person::getName(){
    return name;
}
int Person::getAge(){
    return age;
}
void Person::Info(){
    cout << "Name = " << name << "\nAge = " << age << "\n\n";
}

