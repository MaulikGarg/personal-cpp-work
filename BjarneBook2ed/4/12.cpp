#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int number)
{
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> primes;
    int kMaxNumber {};
    cin >> kMaxNumber;

    for (int i = 2; i < kMaxNumber; i++)
    {
        if(isPrime(i)) primes.push_back(i);
    }

    for(int i : primes) cout << i << " ";
    return 0;
}
