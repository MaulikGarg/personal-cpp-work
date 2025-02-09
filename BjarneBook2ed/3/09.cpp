#include<iostream>
#include<string>
#include<string_view>

int main()
{
    std::cout << "Enter your number in words: ";
    std::string number{};
    std::cin >> number;
 
    if (std::string_view{number} == "zero")
        std::cout << "\n0";
    else if (std::string_view{number} == "one")
        std::cout << "\n1";
    else if (std::string_view{number} == "two")
        std::cout << "\n2";
    else if (std::string_view{number} == "three")
        std::cout << "\n3";
    else if (std::string_view{number} == "four")
        std::cout << "\n4";
    else std::cout << "not a number i know.";

    return 0;
}
