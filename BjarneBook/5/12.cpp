#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
// #include <cmath>
// #include "../libraries/random.h"

using namespace std;

void err(string errorstring)
{
    cerr << errorstring;
    exit(1);
}

int main()
{
    vector<char> numbers{'7', '4', '9', '2'};

    while (1)
    {
        cout << "enter your 4 diff integer digit guess: ";
        vector<char> userInput{0, 0, 0, 0};
        // check if user input already exists in user input vector
        for (int j = 0; j < 4; j++)
        {
            char currentInput{};
            cin >> currentInput;
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
                if (userInput[j] == numbers[i])
                {
                    cow++;
                }
            }
        }

        // checking for identity match
        for (int j = 0; j < 4; j++)
        {
            if (userInput[j] == numbers[j])
            {
                bull++;
                cow--;
            }
        }

        if (bull == 4){
            cout << "you win!";
            break;
        }
        //printing input
        for(int i: userInput) cout << static_cast<char> (i);
        cout << "\nRight number and position: " << bull << " \nRight number wrong position: " << cow << '\n';
    }
    // check if the number is even in the vector. if it is then check if the position is accurate.

    return 0;
}
