#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin1, fin2;
    ofstream fout;

    fin1.open("D:/My Life/first.txt");
    fin2.open("D:/My Life/second.txt");
    fout.open("D:/My Life/mergeFile.txt");

    // you can also check file opened or not  
    char ch;
    while (!fin1.eof())
    {
        fin1.get(ch); // you can use getline(fin, str) function
        fout << ch;
    }
    while (!fin2.eof())
    {
        fin2.get(ch); // you can use getline(fin, str) function
        fout << ch;
    }
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}