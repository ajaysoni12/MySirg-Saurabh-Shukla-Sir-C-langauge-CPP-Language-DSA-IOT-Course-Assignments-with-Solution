#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fout.open("D:/My Life/first.txt");
    fout << "This is first file content";
    fout.close();

    fin.open("D:/My Life/first.txt");
    fout.open("D:/My Life/second.txt");

    char ch;
    while (!fin.eof())
    {
        fin.get(ch); // you can use getline(fin, str) function
        if (ch >= 65 and ch <= 91)
            fout << tolower(ch);
        else if (ch >= 97 and ch <= 122)
            fout << toupper(ch);
    }

    fin.close();
    fout.close();
    return 0;
}