#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U, typename V>
class Triad
{
private:
    T m_first{};
    U m_second{};
    V m_third{};

public:
    Triad(T i1, U i2, V i3) : m_first{i1}, m_second{i2}, m_third{i3} {}

    // getters
    T first()  const { return m_first; }
    T second()  const { return m_second; }
    T third()  const { return m_third; }

    // setters
    void first(T in) { m_first = in; }
    void second(U in) { m_second = in; }
    void third(V in) { m_third = in; }

    void print() const ;
};

template <typename T, typename U, typename V>
void Triad<T,U,V>::print() const{
    cout << "[" << m_first << ", " << m_second << ", " << m_third << "]";
}

int main()
{
    Triad<int, int, int> t1{1, 2, 3};
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{1, 2.3, "Hello"s};
    t2.print();
    std::cout << '\n';

    return 0;
}
