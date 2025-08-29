#include <iostream>

struct IntPair{
    int num1;
    int num2;
    void print(){
        std::cout << "Pair(" << num1 << ',' << num2 << ")\n";
    }
};

int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	return 0;
}
