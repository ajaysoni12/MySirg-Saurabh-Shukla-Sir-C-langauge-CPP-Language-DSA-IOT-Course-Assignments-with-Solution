#include <iostream>
#include <string.h>
using namespace std;
class worker
{
protected:
    int code;
    char name[20];
    float salary;

public:
    worker() {}
    worker(int code, char *n, float salary)
    {
        this->code = code;
        strcpy(name, n);
        this->salary = salary;
    }
    void showDetailsOfWorker()
    {
        cout << "\n\nCode: " << code;
        cout << "\n Name: " << name;
        cout << "\nSalary: " << salary;
    }
};
class Officer
{
protected:
    float DA, HRA;

public:
    Officer() {}
    Officer(float d, float h)
    {
        DA = d;
        HRA = h;
    }
    void showDetailsOfOfficer()
    {
        cout << "\nDA: " << DA;
        cout << "\nHRA: " << HRA;
    }
};
class Manager : public worker, public Officer
{
private:
    float TA, gSalary;

public:
    Manager() {}
    Manager(int c, char *n, float s, float d, float h) : worker(c, n, s), Officer(d, h)
    {
    }
    void showDetailsManager()
    {
        showDetailsOfWorker();
        showDetailsOfOfficer();
        TA = 0.10 * salary;
        cout << "\nTA: " << TA;
        gSalary = DA + HRA + TA + salary;
        cout << "\nGross Salary is: " << gSalary;
    }
};
int main()
{
    int cnt, i;
    cout << "\nEnter Manager count: ";
    cin >> cnt;
    Manager *m = new Manager[cnt];
    for (int i = 0; i < cnt; i++)
    {
        cout << "\n\nEnter worker information for " << i + 1 << endl;
        int c;
        cout << "\nEnter code: ";
        cin >> c;
        char name[20];
        cout << "\nEnter name: ";
        cin >> name;
        float salary;
        cout << "\nEnter salary: ";
        cin >> salary;
        float d;
        cout << "\nEnter DA: ";
        cin >> d;
        float h;
        cout << "\nEnter HRA: ";
        cin >> h;
        m[i] = Manager(c, name, salary, d, h);
    }
    for(int i=0; i<cnt; i++)
    {
        cout<<"\nmanager information: "<<endl; 
        m[i].showDetailsManager();
    }
    return 0;
}