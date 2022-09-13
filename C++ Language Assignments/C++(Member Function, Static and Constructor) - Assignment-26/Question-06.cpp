#include <iostream>
#include <string.h>
using namespace std;
class Student
{
private:
    int rollNo, age; 
    long int mobileNo;
    char name[20];

public:
    Student(int x, char studentName[], int y, int z)
    {
        rollNo = x;
        strcpy(name, studentName);
        age = y;
        mobileNo = z;
    }
    void displayStudentData()
    {
        cout << "Roll No. - " << rollNo << ", Name - " << name << ", Age - " << age << ", Mobile No. - " << mobileNo << endl;
    }
};
int main()
{
    Student st(12, "Ajay", 19, 1234567890);
    st.displayStudentData();
    return 0;
}