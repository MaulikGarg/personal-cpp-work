#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers;

    cout << "Enter +ve numbers: ";
    for (int num; cin >> num;)
    {
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    int mode{numbers[0]};
    int modeOccuredCount{};
    int currentCounter{1};

    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] == numbers[i - 1])
        {
            currentCounter++;
        }
        else
        {
            if (currentCounter > modeOccuredCount)
            {
                mode = numbers[i - 1];
                modeOccuredCount = currentCounter;
            }
            currentCounter = 0;
        }
    }
    if (currentCounter > modeOccuredCount)
    {
        mode = numbers[numbers.size() - 1];
        modeOccuredCount = currentCounter;
    }

    cout << "Mode is: " << mode;

    return 0;
}
