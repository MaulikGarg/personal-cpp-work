/* this contains any possible code references i may need in the future */

/* DO NOT COMPILE THIS FILE*/

/*INDEX:

1) function to check if 2 doubles are equal using relative epsilon
2) function to check if 2 doubles are equal using absolute epsilon
3) function to check if 2 doubles are equal using combination of above 2 functions
4) Sieve of Eratosthenes algorithm to get prime number upto n given number -> https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Pseudocode
5) Ignoring all buffer using cin.
*/

//#define ONE
//#define TWO
//#define THREE
//#define FOUR
//#define FIVE

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


#ifdef FOUR

/*Sieve of Eratosthenes algorithm to get prime number upto n given number*/
constexpr int kMaxNumber {true};
    vector<bool> primes (kMaxNumber, 100);
    
    //https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Pseudocode
    for (int i = 2; i*i <= kMaxNumber; i++)
    {
        if(primes[i]){
            for (int j = i*i; j < kMaxNumber; j+=i)
            {
                primes[j] = false;
            }
            
        }
    }

#endif


#ifdef FIVE
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
#endif
