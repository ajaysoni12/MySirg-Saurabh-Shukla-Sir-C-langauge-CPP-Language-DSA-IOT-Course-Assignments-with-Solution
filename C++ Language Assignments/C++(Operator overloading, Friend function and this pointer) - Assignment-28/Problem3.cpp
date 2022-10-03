#include <iostream>
using namespace std;
class Array
{
private:
    int arr[100];
    const int size = 100;

public:
    void setValue(int value, int index)
    {
        if (index >= size)
        {
            cout << "Array Index is Out of Bound Exception..!" << endl;
            exit(0);
        }
        arr[index] = value;
    }
    void showValue(int index)
    {
        if (index >= size)
        {
            cout << "Array Index is out of bound exception...!" << endl;
            exit(0);
        }
        cout << arr[index] << endl;
    }
    int operator[](int index)
    {
        if (index >= size)
        {
            cout << "Array index is out of bound exception...!" << endl;
            exit(0);
        }
        return arr[index];
    }
};
int main()
{
    Array b;
    b.setValue(35, 55);
    b.setValue(343, 3);
    // b.setValue(3,343);
    b.showValue(55);
    b.showValue(3);
    // b.showValue(343);
    cout << b[55] << endl;
    return 0;
}