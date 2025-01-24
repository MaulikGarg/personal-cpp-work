#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    cout << "Enter distances: ";
    vector<double> distances;

    //sum of distances
    double sum{};

    //taking input
    for(double inputDistance; cin >> inputDistance;){
        distances.push_back(inputDistance);
        sum += inputDistance;
    }

    //sorting to find the shortest and longest
    sort(distances.begin(), distances.end());

    //calculating mean
    double mean{sum/static_cast<double>(distances.size())};

    cout << "The total distance is: " << sum << '\n';
    cout << "The shortest distance is: " << distances[0] << '\n';
    cout << "The longest distance is: " << distances[distances.size()-1] << '\n';
    cout << "The mean distance is: " << mean << '\n';
    return 0;
}
