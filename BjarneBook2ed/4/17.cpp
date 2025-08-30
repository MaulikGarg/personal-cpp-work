#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> values{};

    string input{};
     while (cin >> input)
     {
         values.push_back(input);
     }

    sort(values.begin(), values.end());
    string_view mode{values[0]};
    int modeOccuredCount{};
    int currentCounter{1};

    for (int i = 1; i < values.size(); i++)
    {
        if (values[i] == values[i - 1])
        {
            currentCounter++;
        }
        else
        {
            if (currentCounter > modeOccuredCount)
            {
                mode = values[i - 1];
                modeOccuredCount = currentCounter;
            }
            currentCounter = 1;
        }
    }
    if (currentCounter > modeOccuredCount)
    {
        mode = values[values.size() - 1];
        modeOccuredCount = currentCounter;
    }
    cout << "Mode is: " << mode;

    return 0;
}
