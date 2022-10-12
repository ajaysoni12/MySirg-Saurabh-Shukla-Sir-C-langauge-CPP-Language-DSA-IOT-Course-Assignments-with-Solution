#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class DetectToken
{
private:
    string line;

public:
    DetectToken() { line = ""; }
    void addLine();
    bool searchLine(string);
    void addLineWithFindToken();
    void printAllLine();
    void updateLine();
    void deleteLine(string);
    friend void findToken(string);
};
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}
bool validIdentifier(char *str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}
bool isKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
        !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}
bool isInteger(char *str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}
bool isRealNumber(char *str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}
char *subString(char *str, int left, int right)
{
    int i;
    char *subStr = (char *)malloc(
        sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
void findToken(char *str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);

            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);

            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);

            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);

            else if (isRealNumber(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);

            else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);

            else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}
void DetectToken::addLineWithFindToken()
{
    string temp;
    cout << "Enter C++ Program line: ";
    fflush(stdin);
    getline(cin, temp);
    ofstream fout;
    fout.open("C:/detectToken.txt", ios::app);
    if (!fout)
    {
        cout << "\nFile not open....";
    }
    else
    {
        if (searchLine(temp))
        {
            cout << "\nLine Exist..";
        }
        else
        {
            fout << temp << "\n";
            cout << "\nRecord Added Successfully...\n";
            char *str = const_cast<char *>(temp.c_str());
            findToken(str);
            fout.close();
        }
    }
}
void DetectToken::updateLine()
{
    string tempLine;
    cout << "\nEnter C++ Program Line for Update: ";
    fflush(stdin);
    getline(cin, line);
    if (searchLine(line))
    {
        deleteLine(line);
        cout << "\nEnter new Line: ";
        fflush(stdin);
        getline(cin, tempLine);
        ofstream fout;
        fout.open("C:/detectToken.txt", ios::app);
        if (!fout)
        {
            cout << "\nFile not open...";
        }
        else
        {
            fout << tempLine << "\n";
            cout << "\nRecord update Successfully...";
            fout.close();
        }
    }
    else
    {
        cout << "\nLine not found.." << endl;
    }
}
void DetectToken::deleteLine(string line = "")
{
    string tempLine;
    if (line == "")
    {
        cout << "\nEnter C++ Program Line for Delete: ";
        fflush(stdin);
        getline(cin, line);
    }
    ifstream fin;
    fin.open("C:/detectToken.txt");
    ofstream fout;
    fout.open("C:/temp.txt", ios::app);
    if (!fin || !fout)
    {
        cout << "\nFile Not Create..";
    }
    else
    {
        if (searchLine(line))
        {
            while (!fin.eof())
            {
                getline(fin, tempLine);
                if (line != tempLine)
                {
                    fout << tempLine << "\n";
                }
            }
            fin.close();
            fout.close();
            remove("C:/detectToken.txt");
            rename("C:/temp.txt", "C:/detectToken.txt");
            cout << "\nRecord deleted successfully...";
        }
        else
        {
            cout << "\nLine not found...";
        }
    }
}
bool DetectToken::searchLine(string s = "")
{
    ifstream fin;
    string line;
    if (s == "")
    {
        cout << "\nEnter C++ Program Line for Search: ";
        fflush(stdin);
        getline(cin, s);
    }
    fin.open("C:/detectToken.txt");
    if (!fin)
        cout << "\nFile not Open....";
    else
    {
        while (!fin.eof())
        {
            getline(fin, line);
            if (line == s)
            {
                fin.close();
                return true;
            }
        }
    }
    fin.close();
    return false;
}
void DetectToken::printAllLine()
{
    ifstream fin;
    fin.open("C:/detectToken.txt");
    if (!fin)
    {
        cout << "\nFile not open...";
    }
    else
    {
        int count = 0;
        while (!fin.eof())
        {
            cout << "\nLine No." << ++count << endl
                 << "------------------------------------\n";
            getline(fin, line);
            cout << line << endl;
        }
    }
}
void DetectToken::addLine()
{
    cout << "Enter C++ Program line: ";
    fflush(stdin);
    DetectToken d;
    getline(cin, line);
    ofstream fout;
    fout.open("C:/detectToken.txt", ios::app);
    if (!fout)
    {
        cout << "\nFile not open....";
    }
    else
    {
        if (searchLine(line))
        {
            cout << "\nLine Exist..";
            cout << "\nDo you want to Add Again? (y/n)";
            char option;
            cin >> option;
            while (true)
            {
                if (option == 'y')
                {
                    fout << line << "\n";
                    cout << "\nRecord Added Successfully...";
                    fout.close();
                    break;
                }
                else if (option == 'n')
                {
                    cout << "\nOk...";
                    break;
                }
                else
                {
                    cout << "\nInvalid input...";
                }
            }
        }
        else
        {
            fout << line << "\n";
            cout << "\nRecord Added Successfully...";
            fout.close();
        }
    }
}
int menu()
{
    int choice;
    cout << "\nDetect Token in C++ Program";
    cout << "\n1.Add C++ Program Line(Only)";
    cout << "\n2.Add C++ Program Line(With Know Token)";
    cout << "\n3.View All C++ Program Line";
    cout << "\n4.Search C++ Program Line";
    cout << "\n5.Delete C++ Program Line";
    cout << "\n6.Update C++ Program Line";
    cout << "\n7.Exit";
    cout << "\n\nEnter your choice : ";
    cin >> (choice);
    return (choice);
}
int main()
{
    DetectToken obj;
    while (1)
    {
        system("cls");
        switch (menu())
        {
        case 1:
            obj.addLine();
            break;

        case 2:
            obj.addLineWithFindToken();
            break;

        case 3:
            obj.printAllLine();
            break;

        case 4:
            if (obj.searchLine())
                cout << "\nLine Found...";
            else
                cout << "\nLine Not Found..";
            break;

        case 5:
            obj.deleteLine();
            break;

        case 6:
            obj.updateLine();
            break;

        case 7:
            cout << "\n Thanks for using";
            cout << "\n Press any key to exit";
            system("pause");
            exit(0);

        default:
            cout << "Invalid input";
        }
        system("pause");
    }
    return 0;
}
