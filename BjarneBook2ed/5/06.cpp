#include<iostream>
#include <cmath>
#include <limits>

using namespace std;

void ignoreLine();
bool clearFailedExtraction();
void err(string errorstring);

int main()
{
    cout << "quadratic eq solver! enter a b and c: ";
    double a{};
    double b{};
    double c{};
    cin >> a >> b >> c;
    if(!clearFailedExtraction()) ignoreLine();
    
    double discriminant{b*b - 4*a*c};
    if(discriminant < 0) err("discriminant below zero.");

    cout << "results are " << (-b+sqrt(discriminant))/(2.0*a) << 
            " and " 
            << (-b-sqrt(discriminant))/(2.0*a) << " .";
            
    return 0;
}

//clears input buffer
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// if extraction success get false
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        err("failed input.");

        return true;
    }

    return false;
}

void err(string errorstring)
{
    cerr << errorstring;
    exit(1);
}
