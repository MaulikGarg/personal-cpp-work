#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(const string &s)
{
    vector<string> substrings;
    stringstream inputstr(s);

    string temp{};
    while (inputstr >> temp)
    {
        substrings.push_back(temp);
    }
    return substrings;
}

void printStr(const vector<string> &s)
{
    for (string i : s)
    {
        cout << i << '\n';
    }
}

int main()
{
    cout << "Enter a few words: ";
    string s;
    while (getline(cin, s))
    {
        cout << "\nYou entered:\n";
        printStr(split(s));
        cout << "\nAnother try: ";
    }

    return 0;
}
