#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    cout << "Enter names followed by scores. Type NoName 0 to eliminate. \n";

    // name vector to store names
    vector<string> names{};
    // score vector to store scores
    vector<int> scores{};

    // getting current input
    string currentName{};
    int currentScore{};

    cin >> currentName;
    cin >> currentScore;

    while (currentName != "NoName" && currentScore != 0)
    {
        for (int i = 0; i < names.size(); i++)
        {
            if (currentName == names[i])
            {
                cerr << "Error: repeated names.";
                exit(1);
            }
            
        }
        names.push_back(currentName);
        scores.push_back(currentScore);
        cin >> currentName;
        cin >> currentScore;
    }

    cout << "Enter the score: ";
    cin >> currentScore;
    cout << currentScore << " has names: ";

    bool foundOne{false}; //to check if atleast 1 name is found
    for (int i = 0; i < scores.size(); i++)
    {
        if (currentScore == scores[i])
        {
            cout << names[i] << ", ";
            foundOne = true;
        }
        if(!foundOne) cout << "Score not found.";
    }
    
    return 0;
}
