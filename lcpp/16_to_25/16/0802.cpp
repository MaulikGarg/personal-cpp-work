#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

template <typename T>
bool isValueInArray(const vector<T>& arr, const T& userinput)
{
    for (const auto &currentName : arr)
    {
        if (currentName == userinput)
            return true;
    }
    return false;
}

int main()
{
    const vector<string_view> names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    cout << "Enter a name: ";
    string name;
    cin >> name;

    cout << name << " was " << (isValueInArray<string_view>(names, name) ? "" : "not ") << "found.";

    return 0;
}
