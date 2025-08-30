#include <string>
#include<iostream>
using namespace std;

template <typename T>
class StringValuePair{
  string_view m_first;
  T m_second;
  public:
    StringValuePair(string_view x, T y) : m_first{x}, m_second{y} {}
    string_view first() const {return m_first;}
    T second() const {return m_second;}
};

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
