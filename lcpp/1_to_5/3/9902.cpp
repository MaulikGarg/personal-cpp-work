#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number: ";
	int x {};
	std::cin >> x;
	return x;
}

void writeAnswer(double x)
{
	std::cout << "The quotient is: " << x << '\n';
}

int main()
{
	int x{readNumber()};
	int y{readNumber()};
	writeAnswer((double)(x)/y);

	return 0;
}
