#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

void fizzbuzz(int nums)
{
    static const vector<int> divisors{3, 5, 7, 11, 13, 17, 19};
    static const vector<string_view> words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

    for (int i = 1; i <= nums; i++)
    {
        bool printed{false};
        for (int j = 0; j < static_cast<int>(divisors.size()); j++)
        {
            if (i % divisors[j] == 0)
            {
                cout << words[j];
                printed = true;
            };
        }
        if(!printed) cout << i;
        cout << '\n';
    }
}

int main()
{
    fizzbuzz(150);
    return 0;
}
