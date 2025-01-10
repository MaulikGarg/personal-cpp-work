#include <iostream>
#include <string>
#include <string_view>

using namespace std;

inline void simple_error(string s)
{
    cerr << "error: " << s << '\n';
    exit(1);
}

int main()
{
    // getting recipient name from user
    cout << "Enter the name of the person you want to write to: ";
    string first_name;
    cin >> first_name;
    cout << "\nDear " << first_name << ", How are you? I am fine. I miss you.";

    // getting friend name from user
    cout << "\nEnter the name of another friend: ";
    string friend_name;
    cin >> friend_name;
    cout << "\nHave you seen " << friend_name << " lately?\n";

    // getting friend sex from user
    cout << "\nEnter friend sex (m/f): ";
    char friend_sex{0};
    cin >> friend_sex;

    // printing next line based on sex
    cout << "\nIf you see " << friend_name << " please ask ";
    if (friend_sex == 'm')
        cout << "him";
    else
        cout << "her";
    cout << " to call me.\n";

    // getting age from user
    cout << "\nEnter the age of the recipient: ";
    int age{0};
    cin >> age;
    if (age <= 0 || age >= 110)
        simple_error("you're kidding!");
    else
        cout << "\nI hear you just had a birthday and you are " << age << " years old.";

    // printing message based on age
    if (age < 12)
        cout << " Next year you will be " << age + 1 << ".\n";
    else if (age == 17)
        cout << " Next year you will be able to vote.\n";
    else if (age > 70)
        cout << " I hope you are enjoying retirement.\n";

    // closing message
    cout << "\nYours sincerely";
    return 0;
}
