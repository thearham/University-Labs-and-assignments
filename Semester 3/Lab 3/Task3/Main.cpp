#include "Person.h"
#include "Function_definitions.h"

int main(){
    Person person1("arham", 20);
    Person person2("ali", 30);

    Person person3("ayan", person1.getAge() + person2.getAge());

    cout << "Person 1: \n";
    person1.Info();

    cout << "Person 2: \n";
    person2.Info();

    cout << "Person 3: \n";
    person3.Info();

    return 0;
}