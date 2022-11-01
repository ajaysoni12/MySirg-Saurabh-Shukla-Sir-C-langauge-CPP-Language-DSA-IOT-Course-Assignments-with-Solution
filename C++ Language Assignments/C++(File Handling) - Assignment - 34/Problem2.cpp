#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    // firstly file created
    ofstream fout;
    fout.open("D:/My Life/read.txt");
    fout << "Hello world";
    fout.close();

    // file read
    ifstream fin;
    fin.open("D:/My Life/read.txt");
    fin.seekg(0, ios_base::beg); // file pointer go to starting position
    char ch;
    int i, countChar = 0, countSpace = 0;
    while (!fin.eof())
    {
        fin.get(ch);
        if ((ch >= 65 && ch <= 91) || (ch >= 97 && ch <= 122))
            countChar++;
        else if (ch == ' ')
            countSpace++;
    }
    cout << "\nNo. of character in a file: " << countChar << endl;
    cout << "\nNo. of space between these words: " << countSpace+1 << endl;
    fin.close();
    return 0;
}