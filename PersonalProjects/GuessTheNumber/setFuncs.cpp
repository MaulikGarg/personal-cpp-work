#include "gameParameters.h"
#include "setFuncs.h"
#include "random.h"
#include <set>
#include <iostream>

namespace numberGame
{
    auto getNumberSet() -> std::set<char>
    {
        // original computer set to store the generated random numbers
        std::set<char> numbers;
        while (numbers.size() < gameparameters::numberCount)
        {
            numbers.insert(static_cast<char>(Random::get(0, 9) + '0'));
        }
        return numbers;
    }

    void printSet(std::set<char> funcSetTemporary)
    {
        for (char i : funcSetTemporary)
            std::cout << i << ' ';
    }

    auto getSet(std::set<char> numbers) -> std::set<char>
    {
        std::set<char> userInput;
        while (userInput.size() < gameparameters::numberCount)
        {
            char input{};
            std::cin >> input;
            if (input == 't')
                printSet(numbers); // only for testing
            if (input == 'e')
                closeGame(); //closes game
            if (std::cin.eof())
                closeGame();
            userInput.insert(input);
        }
        return userInput;
    }

    void closeGame()
    {
        std::cout << "Thanks for playing";
        exit(0); 
    }
}
