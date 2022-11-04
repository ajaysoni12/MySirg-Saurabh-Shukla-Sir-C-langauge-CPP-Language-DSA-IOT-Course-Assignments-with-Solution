#include <iostream>
using namespace std;
class Employee
{
protected:
    int empCode;
    char name[20];

public:
    void acceptData()
    {
        cout << "\nEnter employee no. : ";
        cin >> empCode;
        cout << "\nEnter employee name : ";
        cin >> name;
    }
    int getEmpid() { return empCode; }
};
class FullTime : public Employee
{
protected:
    int noOfDays;
    float salary, dailyRate;
    float calcFullTimeEmpSalary()
    {
        salary = noOfDays * dailyRate;
        return salary;
    }

public:
    void acceptDataFullTimeEmp()
    {
        acceptData();
        cout << "\nEnter no. of days: ";
        cin >> noOfDays;
        cout << "\nEnter daily rate: ";
        cin >> dailyRate;
    }
    void showFullTimeEmpDetails()
    {
        cout << "\n-----------------------";
        cout << "\nEmployee Code: " << empCode;
        cout << "\nEmployee Name: " << name;
        cout << "\nSalary: " << calcFullTimeEmpSalary();
        cout << "\nStatus:\tFullTime";
        cout << "\n-----------------------";
    }
};
class PartTime : public Employee
{
private:
    int workingHrs;
    float hourlyRate, salary;
    float calcPartTimeEmpSalary()
    {
        salary = workingHrs * hourlyRate;
        return salary;
    }

public:
    void acceptDataPartTimeEmp()
    {
        acceptData();
        cout << "\nEnter working hours: ";
        cin >> workingHrs;
        cout << "\nEnter hourly rate: ";
        cin >> hourlyRate;
    }
    void showPartTimeEmpDetails()
    {
        cout << "\n-----------------------";
        cout << "\nEmployee Code: " << empCode;
        cout << "\nEmployee Name: " << name;
        cout << "\nSalary: " << calcPartTimeEmpSalary();
        cout << "\nStatus:\tPartTime";
        cout << "\n-----------------------";
    }
};
int main()
{
    int fullTimeEmp, partTimeEmp;
    cout << "\nHow many full time emp you want enter? ";
    cin >> fullTimeEmp;
    FullTime f[fullTimeEmp];
    cout << "\nHow many Part time emp you want enter? ";
    cin >> partTimeEmp;
    PartTime p[partTimeEmp];

    int emp1 = 0, emp2 = 0;

    do
    {
        int choice1, choice2;
        cout << "\n\n1. Enter Record: ";
        cout << "\n2. Display Record: ";
        cout << "\n3. Search Record: ";
        cout << "\n4. Quit: ";
        cout << "\n\tEnter your choice: ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            cout << "\n\n1. FullTime Employee: ";
            cout << "\n2. PartTime Employee: ";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                f[emp1].acceptDataFullTimeEmp();
                emp1++;
                break;
            case 2:
                p[emp2].acceptDataPartTimeEmp();
                emp2++;
                break;
                // defualt case
            }
            break;
        case 2:
            // show all emp details
            // First - for full time employee
            for (int i = 0; i < emp1; i++)
                f[i].showFullTimeEmpDetails();

            // Second - for Part time employee
            for (int i = 0; i < emp2; i++)
                p[i].showPartTimeEmpDetails();
            break;

        case 3:
            int searchId;
            cout << "\nEnter emp id: ";
            cin >> searchId;
            for (int i = 0; i < emp1; i++)
            {
                if (f[i].getEmpid() == searchId)
                {
                    f[i].showFullTimeEmpDetails();
                    break;
                }
            }
            // Second - for Part time employee
            for (int i = 0; i < emp2; i++)
                if (p[i].getEmpid() == searchId)
                {
                    p[i].showPartTimeEmpDetails();
                    break;
                }
            break;
        case 4:
            exit(0);
            // default case
        }
    } while (emp1 <= fullTimeEmp || emp2 <= partTimeEmp);

    return 0;
}