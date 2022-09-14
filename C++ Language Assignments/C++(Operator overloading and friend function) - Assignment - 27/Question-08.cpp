/* 8. Consider a class Matrix
Class Matrix
{
    int a[3][3];
Public:
    //methods;
};
Overload the - (Unary) should negate the numbers stored in the object. */
#include <iostream>
using namespace std;
class Matrix
{
private:
    int a[3][3];

public:
    void setMatrix();
    void showMatrix();
    friend Matrix operator-(Matrix);
};
Matrix operator-(Matrix m)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m.a[i][j] = -m.a[i][j];
    return m;
}
void Matrix::setMatrix()
{
    cout << "Enter Matrix Element (3*3) \n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
}
void Matrix::showMatrix()
{
    {
        cout << "Matrix is: " << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }
}
int main()
{
    Matrix m1, m2;
    m1.setMatrix();
    m1.showMatrix();
    m2 = -m1; //
    m2.showMatrix();
    return 0;
}