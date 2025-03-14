#include "../libraries/random.h"
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cctype>

using namespace std;

//wordlist defining the available wordpool 
namespace wordlist
{
    vector<string_view> words{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};
    const int wordlistsize{static_cast<int>(words.size())};

};

class Session
{
private:
    string_view m_word; // current session's word
    vector<char> m_wrong_guesses; // holds every wrong guess from user
    vector<char> m_right_guesses; // holds every correct guess from user
    int m_guesses{6}; //number of guesses available

    //checks if letter is inside a given container, used to check in guess vectors and word
    template <typename T>
    bool isLetterInWord(const T& word, const char a)
    {
        //if the character is in the word, return
        for (const auto &i : word)
            if (i == a) return true;
            
        return false;
    }

public:
    bool endgame{false}; // if the game has reached a proper ending or not
    // picks a random word from the word list
    Session() : m_word{wordlist::words[Random::get(0, wordlist::wordlistsize - 1)]} {} 

    void winOrLose() 
    {
        if (m_guesses == 0) // no more guesses left, end the game and print word
        {
            cout << "You lost!  The word was: " << m_word;
            endgame = true;
            return;
        }

        for (const auto &i : m_word) // check if the current correct list satisfies the word
            if (!isLetterInWord(m_right_guesses, i)) return;

        cout << "You won!";
        endgame = true;
    }
    
    void getGameState()
    {
        cout << "\nThe word: ";
        for (const auto &i : m_word)
        {
            //if a letter has been guessed correctly, print it.
            if (isLetterInWord(m_right_guesses, i))
                cout << i;
            else
                cout << '_';
        }

        cout << "\tWrong Guesses: ";
        //print + for every remaining guess
        for (int i{0}; i < m_guesses; i++)
            cout << '+';
        //print the previous wrong guesses
        for (const auto &i : m_wrong_guesses)
            cout << i;
        cout << '\n';
    }

    void getUserInput()
    {
        while (true)
        {
            cout << "\nEnter your next letter: ";
            char temp{};
            cin >> temp;
            temp = static_cast<char>(tolower(temp));

            //if invalid input has been entered, set cin to valid again and retry
            if (!cin || temp < 'a' || temp > 'z')
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.clear();
                cout << "That wasn't a valid input.  Try again.";
                continue;
            }

            //if the current input has been guessed before, retry
            if (isLetterInWord(m_wrong_guesses, temp) || isLetterInWord(m_right_guesses, temp))
            {
                cout << "You already guessed that.  Try again.";
                continue;
            }

            //if the current letter is in the word, push it to the correct list, if not, push to wrong list
            if (isLetterInWord(m_word, temp))
                m_right_guesses.push_back(temp);
            else
            {
                m_guesses--;
                m_wrong_guesses.push_back(temp);
            }
            
            //check current win/lose state, if guesses are out or word has been guessed, break the loop.
            winOrLose();
            if (endgame)
            {
                break;
            }

            cout << "You entered: " << temp;

            break;
        }
    }
};

int main()
{
    cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess the word.  To lose: run out of pluses.\n";
    Session test;
    while (!test.endgame)
    {
        test.getGameState();
        test.getUserInput();
    }
    return 0;
}
