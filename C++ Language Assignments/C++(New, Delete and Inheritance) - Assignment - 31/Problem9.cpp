#include <iostream>
using namespace std;
class Student
{
protected:
    int stId;
    char name[20];
    void acceptStudentInfo()
    {
        cout << "\n\nEnter student id: ";
        cin >> stId;
        cout << "\nEnter student name: ";
        cin >> name;
    }
    void showStudentInfo()
    {
        cout << "\n\n student id: ";
        cout << stId;
        cout << "\n student name: ";
        cout << name;
    }
};
class StudentExam : public Student
{
protected:
    float sub1, sub2, sub3, sub4, sub5, sub6;

public:
    void acceptSubData()
    {
        acceptStudentInfo();
        cout << "\nEnter sub1 No. : ";
        cin >> sub1;
        cout << "\nEnter sub2 No. : ";
        cin >> sub2;
        cout << "\nEnter sub3 No. : ";
        cin >> sub3;
        cout << "\nEnter sub4 No. : ";
        cin >> sub4;
        cout << "\nEnter sub5 No. : ";
        cin >> sub5;
        cout << "\nEnter sub6 No. : ";
        cin >> sub6;
    }
    float totalMarks()
    {
        return (sub1 + sub2 + sub3 + sub4 + sub5 + sub6);
    }
    void showStudentInfoWithSub()
    {
        showStudentInfo();
        cout << "\nMarks: ";
        cout << "\nSub1: " << sub1;
        cout << "\nSub2: " << sub2;
        cout << "\nSub3: " << sub3;
        cout << "\nSub4: " << sub4;
        cout << "\nSub5: " << sub5;
        cout << "\nSub6: " << sub6;
    }
};
class StudentResult : public StudentExam
{
protected:
    float percentage;

public:
    void calPercentage()
    {
        percentage = totalMarks() / 6.0;
    }
    void showStudentDetails()
    {
        showStudentInfoWithSub();
        showPercentage();
    }
    void showPercentage()
    {
        cout << "\nPercentage: " << percentage;
    }
};
int main()
{
    StudentResult s[5]; // you can enter by user
    int noOfStudent = 1;
    // u can use loop also
    s[0].acceptSubData();
    s[0].showStudentDetails();
    return 0;
}