#include<iostream>
#include<vector>
using namespace std;

using vectOfDoubles = vector<double>;

double calcTotal(const vectOfDoubles& prices, const vectOfDoubles& weights){
    if(prices.size() != weights.size()) exit(1);
    double total{0};
    for(int i{0}; i < static_cast<int>(weights.size()); i++){
        total += weights[i] * prices[i];
    }
    return total;
}

int main()
{
    vectOfDoubles prices{342.65, 65.34};
    vectOfDoubles weights{4.23, 45.6};
    double total{calcTotal(prices,weights)};
    cout << total << '\n\n';

    return 0;
}
