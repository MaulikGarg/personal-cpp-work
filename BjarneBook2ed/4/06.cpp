#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<string> countingInWords {"zero", "one", "two", "three", 
                            "four", "five", "six", "seven", 
                            "eight", "nine"};
    vector<string> countingInNums = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
    };

    cout << "Enter a number between 0 to 9 in words or number: ";
    string input {};
    cin >> input;

    for (size_t i = 0; i < countingInWords.size(); i++)
    {
        if (input == countingInWords[i])
        {
            cout << "Numbered out: " << countingInNums[i];
            break;
        }
        if (input == countingInNums[i])
        {
            cout << "Spelled out: " << countingInWords[i];
            break;
        }
        
    }
    return 0;
}
