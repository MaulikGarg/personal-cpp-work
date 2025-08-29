#include<iostream>

int main(){
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    (x%2 == 0) ?std::cout << "The value " << x << " is an Even number." 
               :std::cout << "The value " << x << " is an Odd number.";
    return 0;
}
