#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
// #include <cmath>
#include "../libraries/random.h"

#define DEBUGGING
using namespace std;

void err(string errorstring)
{
    cerr << errorstring;
    exit(1);
}

void gameplay()
{
    #ifdef DEBUGGING
        cout << "type '{' to see the number." << '\n';
    #endif

    vector<char> letters;
    int lettersAdded{0};
    while (lettersAdded < 4)
    {
        bool isrepeat{false};
        char temp = static_cast<char>(Random::get(0, 25) + 'a');
        for (int j = 0; j < letters.size(); j++)
        {
            if (letters[j] == temp)
            {
                isrepeat = true;
                break;
            }
        }
        if (isrepeat)
            continue;
        letters.push_back(temp);
        lettersAdded++;
    }

    while (true)
    {
        cout << "enter your 4 diff letter digit guess: ";
        vector<char> userInput{0, 0, 0, 0};
        // check if user input already exists in user input vector
        for (int j = 0; j < 4; j++)
        {
            char currentInput{};
            cin >> currentInput;

#ifdef DEBUGGING
            if(currentInput == '{'){
            for (char c : letters)
            {
                cout << c << " ";
            }}
#endif

            for (int i = 0; i < 4; i++)
            {
                if (userInput[i] == currentInput)
                {
                    err("entered same number twice");
                }
            }
            userInput[j] = currentInput;
        }

        int cow{0};
        int bull{0};

        // checking for element match
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (userInput[j] == letters[i])
                {
                    cow++;
                }
            }
        }

        // checking for identity match
        for (int j = 0; j < 4; j++)
        {
            if (userInput[j] == letters[j])
            {
                bull++;
                cow--;
            }
        }

        if (bull == 4)
        {
            cout << "you win!";
            break;
        }
        // printing input
        for (int i : userInput)
            cout << static_cast<char>(i);
        cout << "\nRight number and position: " << bull << " \nRight number wrong position: " << cow << '\n';
    }
}

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
