#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

int main()
{
    cout << "quadratic eq solver! enter a b and c: ";
    double a{};
    double b{};
    double c{};
    cin >> a >> b >> c;
    
    double discriminant{b*b - 4*a*c};

    cout << "results are " << (-b+sqrt(discriminant))/(2.0*a) << 
            " and " 
            << (-b-sqrt(discriminant))/(2.0*a) << " .";
            
    return 0;
}
