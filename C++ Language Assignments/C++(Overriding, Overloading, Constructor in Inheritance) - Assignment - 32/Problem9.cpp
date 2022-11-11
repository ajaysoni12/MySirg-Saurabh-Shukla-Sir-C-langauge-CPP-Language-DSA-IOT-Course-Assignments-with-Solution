#include <bits/stdc++.h>
using namespace std;
class Area
{
private:
    float areaOfTriangle = 0, areaOfRectangle = 0, areaOfCircle = 0;

public:
    Area() {}
    Area(int length, int width) { areaOfRectangle = length * width; }
    Area(int r) { areaOfCircle = 3.14 * r * r; }
    Area(int a, int b, int c)
    {
        float s = (a + b + c) / 2.0;
        areaOfTriangle = sqrt(s * (s - a) * (s - b) * (s - c));
    }
    void displayAreaTriangle()
    {
        if (areaOfTriangle == 0)
            cout << "This is not a valid triangle.." << endl;
        else
            cout << "Area of triangle is: " << areaOfTriangle << endl;
    }
    void displayAreaRectangle()
    {
        cout << "Area of Rectangle is: " << areaOfRectangle << endl;
    }
    void displayAreaCircle()
    {
        cout << "Area of circle is: " << areaOfCircle << endl;
    }
};
int main()
{
    while (true)
    {
        cout << "\n1. calculate area of triangle";
        cout << "\n2. calculate area of rectangle";
        cout << "\n3. calculate area of circle";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;
        system("cls");
        if (choice == 1)
        {
            cout << "\nEnter the value of edge: ";
            int a, b, c;
            cin >> a >> b >> c;
            Area a1(a, b, c);
            a1.displayAreaTriangle();
        }
        else if (choice == 2)
        {
            int length, width;
            cout << "\nEnter the value of length and width: ";
            cin >> length >> width;
            Area a2(length, width);
            a2.displayAreaRectangle();
        }
        else if (choice == 3)
        {
            int radius;
            cout << "\nEnter the radius: ";
            cin >> radius;
            Area a3(radius);
            a3.displayAreaCircle();
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            cout << "\nWrong option..";
        }
    }
    return 0;
}