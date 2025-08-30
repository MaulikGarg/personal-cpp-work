#include <iostream>
#include <iomanip>
#include <limits> // for std::numeric_limits
using namespace std;

void ignoreLine();
bool clearFailedExtraction();
void err(string errorstring);
double ctok(double inputTemperature, char unit);

int main()
{
    cout << "enter a temperature: ";
    //get temp
    double inputTemperature = 0;
    cin >> inputTemperature;
    if(!clearFailedExtraction()) ignoreLine();

    //get unit
    cout << "Enter a unit (c/k): ";
    char unit{};
    cin >> unit;
    //fail if invalid input
    if(!clearFailedExtraction()) ignoreLine();
    if(unit != 'k' && unit != 'c') err("invalid unit.");

    if (unit == 'c' && inputTemperature < (-273.15))
        err("Temperature below absolute zero.");
    if (unit == 'k' && inputTemperature < 0)
        err("Temperature below absolute zero.");

    cout << ctok(inputTemperature, unit);

    if(unit == 'c') cout << 'k' << '\n';
    if(unit == 'k') cout << 'c' << '\n';

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

double ctok(double inputTemperature, char unit)
{
    if(unit == 'c') return inputTemperature + 273.15;
    if(unit == 'k') return inputTemperature - 273.15;
}
