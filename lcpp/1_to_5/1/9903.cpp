#include <iostream>

int main()
{

	int numberEntered1{};
	int numberEntered2{};
	std::cout << "Enter an integer: ";
	std::cin >> numberEntered1;
	std::cout << "Enter another integer: ";
	std::cin >> numberEntered2;

	std::cout << numberEntered1 << " + " << numberEntered2 << " is: " << numberEntered1 + numberEntered2 << ".\n";
	std::cout << numberEntered1 << " - " << numberEntered2 << " is: " << numberEntered1 - numberEntered2;

	return 0;
}
