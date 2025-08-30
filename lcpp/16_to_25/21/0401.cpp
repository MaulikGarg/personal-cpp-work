#include <iostream>
#include <numeric>

class Fraction{
  int numerator{};
  int denominator{};
  public:
    Fraction(int n=0, int d=1) : numerator{n}, denominator{d} {}
    void print(){std::cout << numerator << '/' << denominator << '\n';}
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    Fraction reduce() const {
      int gcd {std::gcd(numerator,denominator)};
      return {numerator/gcd, denominator/gcd};
    }
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& is, Fraction& frac);
};

Fraction operator*(const Fraction& f1, const Fraction& f2){
  return{f1.numerator*f2.numerator, f1.denominator*f2.denominator};
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac){
  Fraction reduced{frac.reduce()};
  os << reduced.numerator << '/' << reduced.denominator << ' ';
  return os;
}

std::istream& operator>>(std::istream& is, Fraction& frac){
  int num{};
  int den{};
  char ignore{};
  if(is >> num >> ignore >> den){
    if(den!=0){
      frac.numerator = num;
      frac.denominator = den;
    } else std::cin.setstate(std::ios_base::failbit);
  }
  return is;
}

int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}
