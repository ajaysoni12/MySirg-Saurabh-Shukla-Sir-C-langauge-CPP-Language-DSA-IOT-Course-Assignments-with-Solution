#include <iostream>
using namespace std;
int rem(int num)
{
    return (num % 10);
}
template <typename X>
void hashTable(X table[], X num)
{
    table[rem(num)] = num;
}
int main()
{
    int table[10];
    hashTable<int>(table, 50);
    return 0;
}