/* this contains any possible code references i may need in the future */

/* DO NOT COMPILE THIS FILE*/

/*INDEX:

1) function to check if 2 doubles are equal using relative epsilon
2) function to check if 2 doubles are equal using absolute epsilon
3) function to check if 2 doubles are equal using combination of above 2 functions

*/

//#define ONE
//#define TWO
//#define THREE


#ifdef ONE

/*function to check if 2 doubles are equal using relative epsilon*/
/*Knuth's algorithm*/

#include <algorithm> // for std::max
#include <cmath>     // for std::abs

bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

#endif



#ifdef TWO

/*function to check if 2 doubles are equal using absolute epsilon*/

#include <cmath> // for std::abs()

// absEpsilon is an absolute value
bool approximatelyEqualAbs(double a, double b, double absEpsilon)
{
    // if the distance between a and b is less than or equal to absEpsilon, then a and b are "close enough"
    return std::abs(a - b) <= absEpsilon;
}

#endif




#ifdef THREE

/*function to check if 2 doubles are equal using combination of above 2 functions*/

// C++23 version
#include <algorithm> // for std::max
#include <cmath>     // for std::abs (constexpr in C++23)

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

#endif
