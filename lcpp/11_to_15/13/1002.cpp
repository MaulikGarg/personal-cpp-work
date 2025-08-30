#include<iostream>
using namespace std;

struct Fraction{
    double numerator{};
    double denominator{1};
};

void getFraction(Fraction& frac){
    cout << "Enter a fraction (q/r) : ";
    cin >> frac.numerator;
    cin.get(); //reads the / character and discards it
    cin >> frac.denominator;
}

Fraction multiply(const Fraction& frac1, const Fraction& frac2){
    return(Fraction{frac1.numerator*frac2.numerator, frac1.denominator*frac2.denominator});
}

void printFraction(const Fraction& frac){
    cout << frac.numerator << "/" << frac.denominator;
}

int main()
{
    Fraction f1;
    getFraction(f1);
    Fraction f2;
    getFraction(f2);
    printFraction(multiply(f1,f2));
    return 0;
}
