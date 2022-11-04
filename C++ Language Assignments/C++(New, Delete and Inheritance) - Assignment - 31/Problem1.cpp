#include <iostream>
#include <string.h>
using namespace std;
class Person
{
private:
    char *name;
    int age;

public:
    void setName(char name[]) { strcpy(this->name, name); }
    void setAge(int age) { this->age = age; }
    char *getName() { return name; }
    int getAge() { return age; }
};
class Employee : public Person
{
private:
    int empId;
    float salary;

public:
    void setEmpId(int empId) { this->empId = empId; }
    void setSalary(float salary) { this->salary = salary; }
    int getEmpId() { return empId; }
    float getSalary() { return salary; }
    void displayData()
    {
        cout << "\nName - " << getName() << "\nAge - " << getAge() << "\nEmp Id - " << empId << "\nEmp Salary - " << salary << endl;
    }
};
int main()
{
    Employee e1;
    e1.setName("Ajay Soni");
    e1.setAge(20);
    e1.setEmpId(001);
    e1.setSalary(54.34f);
    e1.displayData();
    return 0;
}