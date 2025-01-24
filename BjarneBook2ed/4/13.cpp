#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    constexpr int kMaxNumber {true};
    vector<bool> primes (kMaxNumber, 100);
    
    //called the Sieve of Eratosthenes method https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Pseudocode
    for (int i = 2; i*i <= kMaxNumber; i++)
    {
        if(primes[i]){
            for (int j = i*i; j < kMaxNumber; j+=i)
            {
                primes[j] = false;
            }
            
        }
    }
    
    for(int i = 2; i < primes.size(); i++){
        if (primes[i]) cout << i << ' ';
    }


    return 0;
}
