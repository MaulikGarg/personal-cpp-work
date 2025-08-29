#include <iostream>
#include <string>
#include <string_view>
// #include<vector>
// #include<algorithm>
// #include <cmath>
#include "../libraries/random.h"

using namespace std;

namespace GameParameters
{
    constexpr int maxGuessesAllowed{7};
    constexpr int minNumToPickFrom{1};
    constexpr int maxNumToPickFrom{100};
}

int getNumber(int guessCount);
void gameplay();
bool replay();

int main()
{

    do
    {
        gameplay();
    } while (replay());
    cout << "Thank you for playing.";

    return 0;
}

int getNumber(int guessCount)
{
    int response{};
    do
    {
        cout << "Guess #" << guessCount << " : ";
        cin >> response;
        if (response >= GameParameters::minNumToPickFrom && response <= GameParameters::maxNumToPickFrom)
        {
            return response;
        }
        else
        {
            cout << "Invalid input, please enter a number between "
                 << GameParameters::minNumToPickFrom << " and "
                 << GameParameters::maxNumToPickFrom << ".\n";
        }
    } while (true);
}

void gameplay()
{
    int computerNumber{Random::get(GameParameters::minNumToPickFrom, GameParameters::maxNumToPickFrom)};

    cout << "Let's play a game. I'm thinking of a number between " << GameParameters::minNumToPickFrom << " and " << GameParameters::maxNumToPickFrom << ". You have 7 tries to guess what it is." << '\n';

    for (int guessCount = 1; true; guessCount++)
    {
        int currentGuess{getNumber(guessCount)};
        if (guessCount < GameParameters::maxGuessesAllowed)
        {
            if (currentGuess < computerNumber)
            {
                cout << "Too low!\n";
            }
            else if (currentGuess > computerNumber)
            {
                cout << "Too high!\n";
            }
            else if (currentGuess == computerNumber)
            {
                cout << "You win!\n";
                break;
            }
        }
        else
        {
            cout << "Sorry, you lose. The correct number was " << computerNumber << " .\n";
            break;
        }
    }
}

bool replay()
{
    char response{};
    do
    {
        cout << "Would you like to play again (y/n)?";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            return true;
        }
        else if (response == 'n' || response == 'N')
        {
            return false;
        }
        cout << "Invalid response. Please enter 'y' or 'n'.\n";

    } while (true);
}
