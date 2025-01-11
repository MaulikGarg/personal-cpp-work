#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    constexpr double cmInAnInch     {2.54};
    constexpr double inchesInFeet   {12};
    constexpr double metresInCm     {0.01};

    double smallest{};
    double largest{};
    //counts the number of times the loop has been run
    int counter {1};
    double sum{};
    vector<double> values;

    while (1)
    {
        cout << "\nEnter a number followed by a unit: ";
        double input {};
        cin >> input;

        string unit{};
        cin >> unit;

        if(unit != "m") input *= metresInCm;

        if (unit == "in")
        {
            input *= cmInAnInch;
            unit = "m";
        }
        if(unit == "ft"){
            input *= inchesInFeet;
            input *= cmInAnInch;
            unit = "m";
        }
        if(unit == "cm"){
            unit = "m";
        }

        if(unit != "m") break;

        if(counter == 1) {
            largest = input;
            smallest = input;
        } else {
            if (input > largest){
                largest = input;
                cout << "The largest input so far" << '\n';
            } else if(input < smallest){
                smallest = input;
                cout << "The smallest input so far" << '\n';
            }
        }

        values.push_back(input);
        sort(values.begin(), values.end());
        sum += input;

        cout << "The largest value so far is: " << largest << " m." << '\n';
        cout << "The smallest value so far is: " << smallest << " m." << '\n';
        cout << "The number of values so far is: " << counter << '\n';
        cout << "The sum of values so far is: " << sum << " m." << '\n';

        for(double i: values) cout << i << ' ';
        counter++;

        // cout << "Enter 2 ints: ";
        // if(!(cin >> n1)) break;
        // if(!(cin >> n2)) break;

        // if (n1 > n2)
        // {
        //     cout << "The larger is: " << n1 << "\nThe smaller is: " << n2 << '\n';
        //     if (n1-n2 < 1.0/100)
        //     {
        //         cout << "The numbers are almost equal.";
        //     }
            
        // }
        // else if (n2>n1)
        // {
        //     cout << "The larger is: " << n1 << "\nThe smaller is: " << n2 << '\n';
        //     if (n2-n1 < 1.0/100)
        //     {
        //         cout << "The numbers are almost equal.";
        //     }
        // }
        // else if(n1==n2)
        // {
        //     cout << "The numbers are equal.";
        // }
        
        
    }
    

    return 0;
}
