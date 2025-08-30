#include <iostream>
using namespace std;

template <typename T>
struct Triad{
    T element1;
    T element2;
    T element3;
};

template <typename T>
void print(Triad<T>& triad){
    cout << '[';
    cout << triad.element1;
    cout << ", ";
    cout << triad.element2;
    cout << ", ";
    cout << triad.element3;
    cout << "] ";
}

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}
