#include <iostream>
using namespace std;
class Player
{
private:
    int playerNo, noOfMatches;
    string playerName;
    int *goals;

public:
    Player()
    {
        cout << "\nEnter player No.: ";
        cin >> playerNo;
        cout << "\nEnter Player name: ";
        cin >> playerName;
        cout << "\nEnter Player match: ";
        cin >> noOfMatches;
        goals = new int[noOfMatches];
        cout << "\nEnter no. of goals in per match: ";
        for (int i = 0; i < noOfMatches; i++)
        {
            cout << i + 1 << " ";
            cin >> goals[i];
        }
    }

    void display()
    {
        cout << "\nPlayer No.: " << playerNo;
        cout << "\nPlayer name: " << playerName;
        cout << "\nEnter Player match: " << noOfMatches;
        cout << "\n no. of goals in per match: \n";
        for (int i = 0; i < noOfMatches; i++)
            cout << i + 1 << " " << goals[i] << endl;
    }
};
int main()
{
    Player p;
    p.display();
    return 0;
}