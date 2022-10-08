#include <iostream>
using namespace std;
void test_try(int num)
{
    try
    {
        if (num >= 0 && num <= 9)
            throw num;
        else
            cout << "\nIt is not a Single Number\n";
        throw;
    }
    catch (int a)
    {
        cout << "\nIt is a Single Number\n";
    }
    catch (char b[100])
    {
        cout << b << endl;
    }
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    test_try(num);
    return 0;
}