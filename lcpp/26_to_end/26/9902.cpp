#include<iostream>
using namespace std;

template <typename T, typename U>
class Pair{
  T m_first;
  U m_second;
  public:
    Pair(T x, U y) : m_first{x}, m_second{y} {}
    T first() const {return m_first;}
    U second() const {return m_second;}
};

int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
