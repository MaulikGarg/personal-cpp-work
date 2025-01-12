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

    int mode {numbers[0]};
    int modeOccuredCount {};
    int currentCounter {};

    for (int i = 0; i < numbers.size(); i++)
    {
        if(i == 0) continue;
        if (numbers[i] == numbers[i-1])
        {
            currentCounter++;
        } else if(currentCounter > modeOccuredCount)
        {
            mode = numbers[i-1];
            modeOccuredCount = currentCounter;
            currentCounter = 0;
        }
        
    }
    
    cout << "Mode is: " << mode;
    
    return 0;
}
