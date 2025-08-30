#include <iostream>

using angle = double;

namespace constants
{
    constexpr double pi { 3.14159 };
}

angle convertToRadians(double degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    angle degrees{};
    std::cin >> degrees;

    angle radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}
