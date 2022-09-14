/*
4. Create a class Time which contains:
- Hours
- Minutes
- Seconds
Write a C++ program using operator overloading for the following:
1. = = : To check whether two Times are the same or not.
2. >> : To accept the time.
3. << : To display the time.
*/
#include <iostream>
using namespace std;
class Time
{
private:
    int hours, minutes, second;

public:
    friend void operator>>(istream &cin, Time &t);
    friend void operator<<(ostream &cout, Time t);
    friend bool operator==(Time t1, Time t2);
};
bool operator==(Time t1, Time t2)
{
    if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.second == t2.second)
        return true;
    return false;
}
void operator<<(ostream &cout, Time t)
{
    cout << "Hours: " << t.hours << endl;
    cout << "Minutes: " << t.minutes << endl;
    cout << "Second: " << t.second << endl;
}
void operator>>(istream &cin, Time &t)
{
    cout << "Enter Hours: ";
    cin >> t.hours;
    cout << "Enter Minutes: ";
    cin >> t.minutes;
    cout << "Enter Second: ";
    cin >> t.second;
}
int main()
{
    Time t1, t2, t3;
    cout << "Enter First Time: \n";
    cin >> t1; // operator>>(cin,t1);
    cout << "First Time: \n";
    cout << t1; // operator << (cout, t1);
    cout << "Enter Second Time: \n";
    cin >> t2;
    cout << t2;
    bool result = (t1 == t2);
    result ? cout << "Time are same" : cout << "Time are not same";
    return 0;
}