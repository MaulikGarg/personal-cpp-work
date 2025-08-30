/* this contains any possible code references i may need in the future */

/* DO NOT COMPILE THIS FILE*/

/*INDEX:

1) function to check if 2 doubles are equal using relative epsilon
2) function to check if 2 doubles are equal using absolute epsilon
3) function to check if 2 doubles are equal using combination of above 2 functions
4) Sieve of Eratosthenes algorithm to get prime number upto n given number -> https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Pseudocode
5) Ignoring all buffer using cin.
6) Zeller's convergence to find day of a year in greogorian calendar.
*/

//#define ONE
//#define TWO
//#define THREE
//#define FOUR
//#define FIVE
//#define SIX

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

// if(clearFailedExtraction()) then it will change cin state and clear bad input. else it will just clear bad input anyway.
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

// returns true if std::cin has unextracted input on the current line, false otherwise
bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

//example:
    while(1){
        cin >> someDouble;
        //when extraction succeeds clear input, if fails then it will also do cin flipping inside the function itself.
        if(!clearFailedExtraction()) ignoreLine();
    }
    
#endif

#ifdef SIX

int dayofyear(int d, int m, int y){
    //uses the zeller's congurence formula 
    // m is month, 3=march 11=nov..14=feb
    //adjust jan and feb
    if(m<3){
        m+=12;
        y-=1;
    }
    int yearInCentury {y%100};
    int zeroBasedCentury {y/100}; //integer division intended

    //formula itself
    double innerBracket = floor((13*(m+1))/5.0);
    double outerBracket = d+innerBracket+yearInCentury+floor(yearInCentury/4.0)+floor(zeroBasedCentury/4.0) - 2*zeroBasedCentury;

    //+1 adjusts sunday to be at 7 and monday at 1.
    return (static_cast<int>(outerBracket)%7) + 1;
}

#endif
