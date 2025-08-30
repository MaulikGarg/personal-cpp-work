#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int upperBound {100};
    int lowerBound {1};
    int midpoint{};
    while (1)
    {
        midpoint = {(lowerBound+upperBound) / 2};
        cout << "\n(y/n/e) Is the number you're thinking of less than " << midpoint << " ? type e if it is that.\n";

        char getInput{};
        cin >> getInput;

        if (getInput == 'e')
        {
            break;
        }
        else if (getInput == 'y')
        {
            upperBound = midpoint-1;
        }
        else if (getInput == 'n')
        {
            lowerBound = midpoint+1;
        }
    }

    cout << "Number is: " << midpoint;
    return 0;
}
