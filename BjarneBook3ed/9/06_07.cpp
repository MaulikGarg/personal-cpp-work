#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter string: ";
    string input{};
    getline(cin, input);

    if(input.find("don't") != string::npos){
        int index = input.find("don't");
        input.replace(index, 5, "do not");
    }
    if(input.find("can't") != string::npos){
        int index = input.find("can't");
        input.replace(index, 5, "can not");
    }

    for (size_t i{}; i < input.size(); i++)
    {
        switch (tolower(input[i]))
        {
        case '.':
        case ';':
        case ',':
        case '?':
        case '\'':
            cout << ' ';
            break;
        case '-':
        {
            if (isalpha(input[i - 1]) && isalpha(input[i + 1]))
            {
                cout << input[i];
                break;
            }
            else
            {
                cout << ' ';
                break;
            }
        }
        default:
            cout << input[i];
        }
    }

    return 0;
}
