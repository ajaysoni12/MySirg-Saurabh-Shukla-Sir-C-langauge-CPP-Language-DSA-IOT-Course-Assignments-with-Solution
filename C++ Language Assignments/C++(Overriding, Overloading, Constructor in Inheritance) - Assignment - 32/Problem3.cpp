#include <iostream>
using namespace std;
class Animal
{
private:
    string sound;

public:
    string Sound() { return sound; }
    void setSound(string sound) { this->sound = sound; }
};
class Dog : public Animal
{
private:
    string dogSound;

public:
    string Sound() { return dogSound; }
    void setSound(string dogSound) { this->dogSound = dogSound; }
};
int main()
{
    Animal cat;
    cat.setSound("Meyow");
    cout << "\nCat sound is: " << cat.Sound();

    Dog petDog;
    petDog.setSound("Bhauu");
    cout << "\nPet Dog sound is: " << petDog.Sound();

    return 0;
}