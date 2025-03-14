#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

namespace Animals
{
    enum animals : unsigned int
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        maxValue,
    };
    const vector legs {2,4,4,4,2,0};
}

int main()
{
    assert(Animals::legs.size() == Animals::maxValue);
    cout << Animals::legs[Animals::elephant];
    return 0;
}
