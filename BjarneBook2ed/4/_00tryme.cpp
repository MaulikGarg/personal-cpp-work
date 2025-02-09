#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> bannedWords = {"tits", "pussy"};
    vector<string> words;
    for (string temp; cin >> temp;) {
        words.push_back(temp);
    }
        
    
    cout << "Number of words: " << words.size() << '\n';

    sort(words.begin(), words.end());

    for (size_t i = 0; i < words.size(); i++)
    {
        for (size_t y = 0; y < bannedWords.size(); y++)
        {
            if (words[i] == bannedWords[y])
            {
                words[i] = "Bleep";
            }
            
        }
        
    }
    
    for (int i = 0; i < words.size(); ++i)
        if (i == 0 || words[i-1] != words[i])
            cout << words[i] << "\n";
}
