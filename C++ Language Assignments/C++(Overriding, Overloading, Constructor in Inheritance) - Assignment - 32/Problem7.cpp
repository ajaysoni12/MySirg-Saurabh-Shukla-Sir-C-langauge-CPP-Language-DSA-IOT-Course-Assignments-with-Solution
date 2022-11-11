#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;

public:
    Person() {}
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};
class Student : public Person
{
private:
    int rank;

public:
    Student() : Person() {}
    Student(int rank, string name, int age) : Person(name, age)
    {
        this->rank = rank;
    }
    void showData()
    {
        cout << "\nStudent Name: " << name << " Age: " << age << " Rank: " << rank;
    }
};
int main()
{
    Student s(1, "Ajay Soni", 19);
    s.showData();
    return 0;
}