#include <iostream>

int doubleNumber(int num){
    return 2*num;
}

int main()
{
    int num{};
    std::cout << "Enter num: ";
    std::cin >> num;
    std::cout << "Double of " << num << " is: " << doubleNumber(num);
    return 0;
}
