#include <iostream>
#include <math.h>
using namespace std;
class Matrix
{
protected:
    int num1, num2, num3, num4;
    Matrix(int x, int y, int z, int p)
    {
        num1 = x;
        num2 = y;
        num3 = z;
        num4 = p;
    }
};
class cal_determinant : public Matrix
{
private:
    int determinant;

public:
    cal_determinant(int x, int y, int z, int p) : Matrix(x, y, z, p) {}
    void calDeterminant()
    {
        determinant = fabs(num1 * num4 - num2 * num3);
        cout << "\nDeterminant of matrix is: " << determinant;
    }
};
int main()
{
    cal_determinant obj(1, 2, 3, 4);
    obj.calDeterminant();

    return 0;
}