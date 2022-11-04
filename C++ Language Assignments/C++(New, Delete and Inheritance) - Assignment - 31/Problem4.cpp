#include <bits/stdc++.h>
using namespace std;
class Person
{
protected: // no need to made getter setter
    char pName[20], pAddress[20];
    int phoneNo;
};
class Employee : public Person // Single Inheritance
{
protected:
    int eNo;
    char eName[20];
};
class Manager : public Employee // Multilevel Inheritance
{
protected:
    char desigNation[30], departName[30];
    float basicSalary;

public:
    void acceptDetails()
    {
        cout << "\nEnter details of Manager";
        cout << "\n-------------------------";
        cout << "\nEnter Employee Number: ";
        cin >> eNo;
        cout << "\nEnter Name: ";
        cin >> eName;
        cout << "\nEnter Address: ";
        cin >> pAddress;
        cout << "\nEnter PhoneNo. ";
        cin >> phoneNo;
        cout << "\nEnter Designation: ";
        cin >> desigNation;
        cout << "\nEnter Department Name: ";
        cin >> departName;
        cout << "\nEnter Basic Salary: ";
        cin >> basicSalary;
    }
    float getSalary() { return basicSalary; }
    char *getName() { return eName; }
};
int main()
{
    int i, totalManager, temp = INT_MIN;
    Manager man[100];
    cout << "\nHow many Manager you want enter? ";
    cin >> totalManager; // Accepts details for 'n' manager

    for (i = 0; i < totalManager; i++)
        man[i].acceptDetails();

    int ind = -1; 
    for (i = 0; i < totalManager; i++)
    {
        if (temp < man[i].getSalary())
        {
            temp = man[i].getSalary();
            ind = i; 
        }
    }

    cout<<"\nManager with highest salary is: "<<temp<<endl; 
    cout<<"\nAnd Manager Name is: "<<man[i].getName()<<endl; 
    return 0;
}