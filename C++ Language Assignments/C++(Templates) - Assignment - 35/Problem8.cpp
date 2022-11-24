#include <iostream>
using namespace std;
template <class X>
class Stack
{
private:
    int top;
    X stack[100];

public:
    Stack() { top = -1; }
    void push(X data) { stack[++top] = data; }
    X pop() { return stack[top--]; }
};
int main()
{
    Stack<int> int_stack;
    Stack<string> str_stack;
    int_stack.push(4);
    str_stack.push("Ajay");
    cout << int_stack.pop() << endl;
    cout << str_stack.pop() << endl;
    return 0;
}