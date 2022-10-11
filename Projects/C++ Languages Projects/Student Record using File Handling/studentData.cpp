#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int ID;
class Student
{
private:
    int id, stAge;
    string stName, stStream;

public:
    void addStudent();
    void printAllStData();
    void printStData();
    void searchStudent(int);
    void deleteStudent(int);
    void updateStudent(int);
};
void Student::updateStudent(int stId)
{
    deleteStudent(stId);

    cout << "\nEnter your name: ";
    cin.get();
    getline(cin, stName);
    cout << "\nEnter your age: ";
    cin >> stAge;
    cout << "\nEnter your stream: ";
    cin >> stStream;
    ID++;
    ofstream fout;
    fout.open("D:/Silent-Night/C++ language/studentData.txt", ios::app);
    fout << "\n"
         << id;
    fout << "\n"
         << stName;
    fout << "\n"
         << stAge;
    fout << "\n"
         << stStream;
    fout.close();

    cout << "\nRecord updated Successfully....";
}
void Student::deleteStudent(int stId)
{
    ifstream fin;
    fin.open("D:/Silent-Night/C++ language/studentData.txt");
    ofstream fout;
    fout.open("D:/Silent-Night/C++ language/temp.txt", ios::app);
    Student s;
    while (!fin.eof())
    {
        fin >> s.id;
        fin.ignore();
        getline(fin, s.stName);
        fin >> s.stAge;
        fin >> s.stStream;
        if (stId != s.id)
        {
            fout << "\n"
                 << id;
            fout << "\n"
                 << stName;
            fout << "\n"
                 << stAge;
            fout << "\n"
                 << stStream;
        }
    }
    fin.close();
    fout.close();

    remove("D:/Silent-Night/C++ language/studentData.txt");
    rename("D:/Silent-Night/C++ language/temp.txt", "D:/Silent-Night/C++ language/studentData.txt");
    cout << "\nRecord Deleted Successfully....";
}
void Student::searchStudent(int stId)
{
    ifstream fin;
    fin.open("D:/Silent-Night/C++ language/studentData.txt");
    Student s;
    int flag = 0;
    while (!fin.eof())
    {
        fin >> s.id;
        fin.ignore();
        getline(fin, s.stName);
        fin >> s.stAge;
        fin >> s.stStream;

        if (stId == s.id)
        {
            s.printStData();
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "\nStudent Found...";
    else
        cout << "\nStudent Doesn't found...";
    fin.close();
}
void Student::printStData()
{
    cout << " ID = " << id << endl;
    cout << " Name = " << stName << endl;
    cout << " Age = " << stAge << endl;
    cout << " Stream = " << stStream << endl;
    cout << "####################################" << endl
         << endl;
}
void Student::printAllStData()
{
    ifstream fin;
    fin.open("D:/Silent-Night/C++ language/studentData.txt");
    Student s;
    while (!fin.eof())
    {
        fin >> s.id;
        fin.ignore();
        getline(fin, s.stName);
        fin >> s.stAge;
        fin >> s.stStream;
        s.printStData();
    }
    fin.close();
}
void Student::addStudent()
{
    cout << "\nEnter your name: ";
    cin.get();
    getline(cin, stName);
    cout << "\nEnter your age: ";
    cin >> stAge;
    cout << "\nEnter your stream: ";
    cin >> stStream;
    ID++;

    ofstream fout;
    fout.open("D:/Silent-Night/C++ language/studentData.txt", ios::app);
    fout << "\n"
         << id;
    fout << "\n"
         << stName;
    fout << "\n"
         << stAge;
    fout << "\n"
         << stStream;
    fout.close();

    fout.open("D:/Silent-Night/C++ language/studentId.txt");
    fout << "\n"
         << id;
    fout.close();
    cout << "\nRecord Added Successfully...";
}

int main()
{
    int choice;
    while (true)
    {
        cout << "Enter Your choice" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Print all the students" << endl;
        cout << "3. Search a student" << endl;
        cout << "4. Update a student" << endl;
        cout << "5. Delete a student" << endl;

        cin >> choice;

        Student s;
        int id;
        switch (choice)
        {
        case 1:
            s.addStudent();
            break;
        case 2:
            s.printAllStData();
            break;
        case 3:
            cout << "Enter student id" << endl;
            cin >> id;
            s.searchStudent(id);
            break;

        case 4:
            cout << "Enter student id" << endl;
            cin >> id;
            s.updateStudent(id);
            break;

        case 5:
            cout << "Enter student id" << endl;
            cin >> id;
            s.deleteStudent(id);
            break;

        default:
            return 0;
        }
    }

    return 0;
}