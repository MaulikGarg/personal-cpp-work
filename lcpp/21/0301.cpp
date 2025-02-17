#include <iostream>
#include <numeric>

class Fraction{
  int numerator;
  int denominator;
  public:
    Fraction(int n, int d=1) : numerator{n}, denominator{d} {}
    void print(){std::cout << numerator << '/' << denominator << '\n';}
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    Fraction reduce(){
      int gcd {std::gcd(numerator,denominator)};
      return {numerator/gcd, denominator/gcd};
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2){
  return{f1.numerator*f2.numerator, f1.denominator*f2.denominator};
}

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
