#include <iostream>
#include <string>
#include <string_view>

using namespace std;

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,

};

constexpr string_view getAnimalName(Animal& tempanimal){
    using enum Animal;
    switch (tempanimal)
    {
    case pig:
        return "pig";
    case chicken:
        return "chicken";
    case goat:
        return "goat";
    case cat:
        return "cat";
    case dog:
        return "dog";
    case duck:
        return "duck";
    default:
        return "error";
        break;
    }
}

void printNumberOfLegs(Animal& tempanimal){
    using enum Animal;
    cout << "A " << getAnimalName(tempanimal) << " has ";
    switch (tempanimal)
    {
    case pig: case dog: case goat: case cat:
        cout << 4;
        break;
    case chicken: case duck:
        cout << 2;
        break;
    default:
        cout << -1;
    }
    cout << " legs.\n";
}

int main()
{
    Animal me {Animal::dog};
    
    printNumberOfLegs(me);

    return 0;
}
