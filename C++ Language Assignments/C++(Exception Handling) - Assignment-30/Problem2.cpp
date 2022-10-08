#include <iostream>
using namespace std;
int main()
{
    try
    {
        throw 'E';
    }
    catch (char e)
    {
        cout << "\nException Caught " << e << " " << endl;
    }
    return 0;
}