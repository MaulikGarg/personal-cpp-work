#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

void print_until_s(const vector<string>& v, const string& quit)
{
    for (string s : v)
    {
        if (s == quit)
            return;
        cout << s << '\n';
    }
}

void print_until_ss(const vector<string>& v, const string& quit)
{
    int quitOccurences{0};
    for (string s : v)
    {
        if (s == quit) quitOccurences++;
        if (quitOccurences == 2) return;
        cout << s << '\n';
    }
}

int main()
{
    std::vector<std::string> myfavobjects{"apple", "banana", "cherry", "date", "elderberry", "date", "fig"};
    print_until_s(myfavobjects, "date");
    cout << "\n\n\n\n";
    print_until_ss(myfavobjects, "date");

    return 0;
}
