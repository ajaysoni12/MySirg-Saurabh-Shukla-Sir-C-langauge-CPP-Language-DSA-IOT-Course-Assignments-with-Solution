#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("D:/My Life/mergeFile.txt");
    if (fin.is_open())
    {
        int noOfLine = 0, noOfChar = 0, noOfWords = 0;
        while (!fin.eof())
        {
            string str;
            getline(fin, str);
            noOfLine++;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == ' ')
                    noOfWords++;
                else
                    noOfChar++;
            }
        }
        cout << "\nIn file,\nNo. of line is: " << noOfLine << endl;
        cout << "\nNo. of character is: " << noOfChar << endl;
        cout << "\nNo. of words is: " << noOfWords +1<< endl;
    }
    else
    {
        cout << "File not open..";
    }
    return 0;
}