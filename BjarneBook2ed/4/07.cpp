#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

int stringToNum(string input){
    vector<string> countingInWords{"zero", "one", "two", "three",
                                   "four", "five", "six", "seven",
                                   "eight", "nine"};
    vector<string> countingInNums = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
    };

    for (int i = 0; i < countingInWords.size(); i++)
    {
        if (input == countingInWords[i] || input == countingInNums[i])
        {
            return i; 
        }
        
    }

    return 0;
}

int main()
{
    

    cout << "Enter two 1-9 values and character (+, -, * or /)\n";
    string val1Input{};
    string val2Input{};
    char op = ' ';
    while (cin >> val1Input >> val2Input >> op)
    {
        int val1{stringToNum(val1Input)};
        int val2{stringToNum(val2Input)};
        
        switch (op)
        {
        case '+':
            cout << "The sum of " << val1 << " and " << val2 << " is " << val1 + val2 << ".\n";
            break;
        case '-':
            cout << "The difference of " << val1 << " and " << val2 << " is " << val1 - val2 << ".\n";
            break;
        case '*':
            cout << "The product of " << val1 << " and " << val2 << " is " << val1 * val2 << ".\n";
            break;
        case '/':
            cout << "The division of " << val1 << " and " << val2 << " is " << val1 / val2 << ".\n";
            break;
        default:
            cout << "This is not a valid operation (use +, -, * or /)\n";
            break;
        }
    }
}
