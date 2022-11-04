#include <iostream>
using namespace std;
class Student
{
private:
    int sub1, sub2, sub3;

public:
    void setSubData(int sub1, int sub2, int sub3)
    {
        this->sub1 = sub1;
        this->sub2 = sub2;
        this->sub3 = sub3;
    }
    int getSub1() { return sub1; }
    int getSub2() { return sub2; }
    int getSub3() { return sub3; }
};
class TotalMarks : public Student // single inheritance
{
private:
    int total;

public:
    void doTotal() { total = getSub1() + getSub2() + getSub3(); }
    int getTotal() { return total; }
};
class Percentage : public TotalMarks // multilevel inheritance
{
private:
    float percentage;

public:
    void findPercentage() { percentage = getTotal() / 3.0f; } // (total * 300)/ 100.0
    float getPercentage() { return percentage; }
};
int main()
{
    Percentage student1; 
    student1.setSubData(94, 100, 35); // 3 subjects marks 
    student1.doTotal();
    student1.findPercentage();
    cout<<student1.getPercentage();
    return 0;
}