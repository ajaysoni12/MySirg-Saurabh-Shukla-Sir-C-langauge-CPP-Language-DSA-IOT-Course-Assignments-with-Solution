#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("D:/My Life/hello.txt");
    if (fout)
    {
        cout << "File Open..";
        fout << "Hello World";
    }
    else
        cout << "File not opend...";
    fout.close();
    return 0;
}