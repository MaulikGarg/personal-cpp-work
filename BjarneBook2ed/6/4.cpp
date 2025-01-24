#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Name_Value{
    public:
        string name;
        int score;
};

int main()
{
    cout << "Enter names followed by scores. Type NoName 0 to eliminate. \n";

    vector<Name_Value> nameValues;

    // getting current input
    string currentName{};
    int currentScore{};

    cin >> currentName;
    cin >> currentScore;

    while (currentName != "NoName" && currentScore != 0)
    {
        for (int i = 0; i < nameValues.size(); i++)
        {
            if (currentName == nameValues[i].name)
            {
                cerr << "Error: repeated names.";
                exit(1);
            }
            
        }
        Name_Value temporary{currentName, currentScore};
        nameValues.push_back(temporary);
        cin >> currentName;
        cin >> currentScore;
    }

    for(int i = 0; i < nameValues.size(); i++){
        cout << nameValues[i].name << "\t" << nameValues[i].score << '\n';
    }
    return 0;
}
