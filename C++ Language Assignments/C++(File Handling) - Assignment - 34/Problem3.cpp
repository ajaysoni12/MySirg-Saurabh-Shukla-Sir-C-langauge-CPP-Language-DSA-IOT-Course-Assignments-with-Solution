#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("D:/My Life/read.txt", ios::app);
    if (fout.is_open())
        fout << "Append some extra words"; // add these words in a file 
    else
        cout << "File not open..";
    fout.close();
    return 0;
}