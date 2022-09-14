/* 10.Class Matrix
{
    int a[3][3];
Public:
    //methods;
};
Let m1 and m2 are two matrices. Find out m3=m1+m2 (use operator
overloading).*/
#include <iostream>
using namespace std;
class Matrix
{
private:
    int a[3][3];

public:
    void inputMatrix()
    {
        cout << "Enter Matrix Element (3*3): \n";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
    }
    void showMatrix()
    {
        cout << "Matrix is: \n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << "  ";
            }
            cout << endl;
        }
    }
    Matrix operator+(Matrix m)
    {
        Matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        return temp;
    }
};
int main()
{
    Matrix m1, m2, m3;
    m1.inputMatrix();
    m1.showMatrix();
    m2.inputMatrix();
    m2.showMatrix();
    m3 = m1 + m2;
    m3.showMatrix();
    return 0;
}