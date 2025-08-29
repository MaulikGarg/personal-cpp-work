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

    cout << "Enter the number of primes wanted: ";
    int primesWanted{};
    cin >> primesWanted;

    vector<int> primes(primesWanted, 0);
    primes[0] = 2;

    
    for (int counter = 3; primes[primesWanted-1] == 0; counter++)
    {
        if (isPrime(counter))
        {
            primes[counter-2] = counter;
        } 
    }
    

    for (int i = 2; i < primesWanted; i++)
    {
        if (primes[i])
            cout << i << ' ';
    }

    return 0;
}
