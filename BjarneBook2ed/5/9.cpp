#include<iostream>
#include<string>
#include<string_view>
#include<vector>
//#include<algorithm>
//#include <cmath>
//#include "../libraries/random.h"

using namespace std;

void ignoreLine();
bool clearFailedExtraction();
void err(string errorstring);

int main()
{
    //get number of values.
    cout << "Please enter the number of values you want to sum: ";
    int numOfValues{};
    cin >> numOfValues;
    if(!clearFailedExtraction()) ignoreLine();
    if(numOfValues < 1) err("Number of values cannot be less than 1.");

    //getting values inside the vector
    vector<int> values{};
   
    cout << "Please enter some integers (press '|' to stop): ";
    for(int currentInput; cin >> currentInput;){
        if(cin.peek() == '.') err("fractional sum cannot be displayed.");
        if(!clearFailedExtraction()) ignoreLine();
        values.push_back(currentInput);
    }

    if(values.size() < numOfValues) err("Number of values input less than specified.");

    //summing the num of values
    int sum{0};
    for(int i=0; i < numOfValues; i++){
        sum += values[i];
    }

    //printing sum
    cout << "The sum is: " << sum;


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
