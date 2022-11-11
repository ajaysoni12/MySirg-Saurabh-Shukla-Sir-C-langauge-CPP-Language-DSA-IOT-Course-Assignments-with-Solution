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
    void displayPerson()
    {
        cout << "\nName: " << name << " Age: " << age;
    }
};
class Student : public Person
{
protected:
    int rank;

public:
    Student() : Person() {}
    Student(int rank, string name, int age) : Person(name, age)
    {
        this->rank = rank;
    }
    void showData()
    {
        displayPerson();
        cout << " Rank: " << rank;
    }
};
class Topper : public Student
{
private:
    int batch;

public:
    Topper() : Student() {}
    Topper(int batch, int rank, string name, int age) : Student(rank, name, age)
    {
        this->batch = batch;
    }
    void displyeTopper()
    {
        showData();
        cout << " Batch is: " << batch;
    }
};
int main()
{
    Topper s(3,1, "Ajay Soni", 19);
    s.displyeTopper();
    return 0;
}