/*
Ask the user to enter three values. The program should then print these values. 
Add an appropriate comment above function main().

The program should match the following output (when run with input values 4, 5, and 6):

Enter three numbers: 4 5 6
You entered 4, 5, and 6.

*/


#include <iostream>

// this program extracts three values and prints them into the console.
int main(){

    int x{};
    int y{};
    int z{};

    std::cout << "Please enter three integers: ";
    std::cin >> x >> y >> z;
    std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n";

}
