#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

namespace Items
{
    enum type
    {
        health_potion,
        torch,
        arrow,
        max_value
    };

}

std::string_view getItemTypeName(int count, size_t index) {
    switch (index) {
        case 0: return (count == 1) ? " health potion " : " health potions ";
        case 1: return (count == 1) ? " torch " : " torches ";
        case 2: return (count == 1) ? " arrow " : " arrows ";
        default: return "???";
    }
}

void printInv(const vector<int> &inventory)
{
    int total = 0;
    for (size_t i {0}; i < inventory.size(); i++)
    {
        total += inventory[i];
        cout << "You have " << inventory[i] << getItemTypeName(inventory[i], i) << '\n';
    }
    cout << "You have " << total << " total items";
}

int main()
{
    vector inventory{1, 5, 10};
    assert(inventory.size() == Items::max_value);
    printInv(inventory);
    return 0;
}
