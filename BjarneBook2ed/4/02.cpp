#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> temps;           // temperatures
    for (double temp; cin >> temp;) // read into temp
        temps.push_back(temp);      // put temp into vector
    // compute mean temperature:
    double sum = 0;
    for (int x : temps)
        sum += x;
    cout << "Average temperature: " << sum / temps.size() << '\n';

    // compute median temperature:
    sort(temps.begin(), temps.end()); // sort temperatures
    size_t size = temps.size();
    double median;
    if (size % 2 == 1) {
        // Odd-sized sequence: middle element
        median = temps[size / 2];
    } else {
        // Even-sized sequence: average of the two middle elements
        median = (temps[size / 2 - 1] + temps[size / 2]) / 2;
    }

    cout << "Median temperature: " << median << '\n';
    
    
}
