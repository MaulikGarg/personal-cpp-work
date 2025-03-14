#include <array>
#include <iostream>

using std::cout, std::array, std::get;

int main()
{
    constexpr array message{'h', 'e', 'l', 'l', 'o'};
    cout << "The array is of length: " <<message.size() << '\n';
    cout << message[1];
    cout << message.at(1);
    cout << get<1>(message);
}
