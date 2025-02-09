#include <iostream>
using namespace std;

namespace X
{
    int var{};
    void print()
    {
        cout << "in x: " << var << '\n';
    }
}

namespace Y
{
    int var{};
    void print()
    {
         cout << "in y: " << var << '\n';
    }
}

namespace Z
{
    int var{};
    void print()
    {
         cout << "in z: " << var << '\n';
    }
}

int main()
{
    X::var = 7;
    X::print(); // print X’s var
    using namespace Y;
    var = 9;
    print(); // print Y’s var
    {
        using Z::print;
        using Z::var;
        var = 11;
        print(); // print Z’s var
    }
    print();    // print Y’s var
    X::print(); // print X’s var
}
