#include "inputClear.h"
#include "setFuncs.h"
#include "gameParameters.h"
#include <iostream>

using std::set;
using std::cin;
using std::cout;

using namespace numberGame;
using namespace gameparameters;
using namespace inputclear;

void gameplay();

int main()
{
    bool replay{true};
    do
    {
        gameplay();
        cout << "\nDo you want to replay? (enter 0 to exit)";
        cin >> replay;
    } while (replay);

    closeGame();

    return 0;
}

void gameplay()
{
    set<char> numbers = getNumberSet();

    while (true)
    {
        cout << "Enter your 4 diff integer digit guess: ";

        set<char> userInput = getSet(numbers);
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

            if (*it_user == *it_generated)
                correctPosition++;
            else if (userInput.count(*it_generated))
                correctDigit++;

            // incrementing the iterator so it moves to the next element
            it_user++;
            it_generated++;
        }

        if (correctPosition == numberCount)
        {
            cout << "you win!";
            break;
        }

        // printing input
        printSet(userInput);
        cout << "\nRight number and position: " << correctPosition << " \nRight number wrong position: " << correctDigit << '\n';

        if(hasUnextractedInput()) ignoreLine();
    }
}


