#include <iostream>
#include <string>
#include <string_view>

using namespace std;

string getstring()
{

    string str;
    getline(cin >> ws, str);
    return str;
}

int getAge()
{
    int age;
    cin >> age;
    return age;
}

int main()
{

    cout << "Enter the name of person #1: ";
    string name1{getstring()};
    cout << "Enter the age of " << string_view(name1) << ": ";
    int age1{getAge()};

    cout << "Enter the name of person #2: ";
    string name2{getstring()};
    cout << "Enter the age of " << string_view(name2) << ": ";
    int age2{getAge()};

    if (age1 > age2)
    {
        cout << name1 << "(age " << age1 << ")" << " is older than "
             << string_view(name2) << "(age " << age2 << ")" << endl;
    }
    else if (age1 < age2)
    {
        cout << name2 << "(age " << age2 << ")" << " is older than "
             << string_view(name1) << "(age " << age1 << ")." << endl;
    }
    return 0;
}
