#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void getInputFromFile(vector<string> *tobefilled)
{
    cout << "Enter the file name without extension: ";
    string input{};
    cin >> input;

    ifstream file{input + ".txt"};

    string temp{};
    while (getline(file, temp))
    {
        tobefilled->push_back(temp);
    }
}

vector<string> reverseInput(const vector<string> &ogMessage)
{
    vector<string> reversedString;

    for (string line : ogMessage)
    { 
        string word{};
        vector<string> thisline;
        stringstream currentLineInput(line);
        //get the current line's words seperated.
        while (currentLineInput >> word)
        {
            thisline.push_back(word);
        }
        reverse(thisline.begin(), thisline.end());

        string reversedline{};
        
        for (size_t currentWord = 0; currentWord < thisline.size(); currentWord++)
        {
            reversedline+=thisline[currentWord];
            if(currentWord!=thisline.size() - 1) reversedline+=" ";
        }
        

        reversedString.push_back(reversedline);

    }
    return reversedString;
}

int main()
{
    vector<string> originalMessage{};
    getInputFromFile(&originalMessage);

    vector<string> reversedMessage{reverseInput(originalMessage)};

    for (string i : reversedMessage)
    {
        cout << i << '\n';
    }
}
