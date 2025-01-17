/* WIP
note: using an ordered set for now, limits gameplay but easier to implement, change to unordered set later.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>
#include "../libraries/random.h"

namespace gameparameters
{
    // maximum numbers for the game, cannot be more than 10. recommended is <= 6
    constexpr int numberCount{4};
}

using namespace std;
using namespace gameparameters;

void err(string errorstring);
void gameplay();
bool clearFailedExtraction();
void ignoreLine();

int main()
{
    do
    {
        gameplay();
        cout << "\nDo you want to replay?";
        char reply{};
        cin >> reply;
        if (reply == 'n')
            break;
    } while (1);

    cout << "thanks for playing";

    return 0;
}

void gameplay()
{
    // original computer set to store the generated random numbers
    set<char> numbers;
    while (numbers.size() < numberCount)
    {
        numbers.insert(static_cast<char>(Random::get(0, 9) + '0'));
    }

    while (true)
    {
        cout << "enter your 4 diff integer digit guess: ";

        set<char> userInput;
        while (userInput.size() < numberCount)
        {
            char input{};
            cin >> input;
            userInput.insert(input);
        }

        int correctDigit{0};
        int correctPosition{0};

        // iterators to the first element of the set
        auto it_generated = numbers.begin();
        auto it_user = userInput.begin();

        for (int i = 0; i < numberCount; i++)
        {
            /* //checks if the value at current iterator is equal to 
            the value at the same iterator position for the generated set,
            if not, checks if the vector even has a generated number.*/

            if (*it_user == *it_generated) correctDigit++;
            else if (userInput.count(*it_generated)) correctPosition++;

            //incrementing the iterator so it moves to the next element
            it_user++;
            it_generated++;
        }

        if (correctDigit == numberCount)
        {
            cout << "you win!";
            break;
        }
        
        // printing input
        for (char i : userInput)
            cout << i << ' ';
        cout << "\nRight number and position: " << correctPosition << " \nRight number wrong position: " << correctDigit << '\n';
    }
}

/*error checking field*/
void err(string errorstring)
{
    cerr << errorstring;
    exit(1);
}

// function to use max console limit and clear the console thus the input buffer

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
