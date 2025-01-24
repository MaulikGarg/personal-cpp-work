#include<iostream>
#include<string>
#include<string_view>
#include<vector>

using namespace std;

using vectOfStrings = vector<string>;
using vectOfDoubles = vector<double>;

namespace {
    constexpr int namecount {5};
}
int main()
{
    vectOfStrings names;
    cout << "Enter the names: ";
    string current{};
    for(int i = 0; i < namecount; i++){
        cin >> current;
        names.push_back(current);
    }

    vectOfDoubles ages;
    double currentAge{};
    for(int i = 0; i < namecount; i++){
        cout << "Enter " << names[i] << " 's age: ";
        cin >> currentAge;
        ages.push_back(currentAge);
    }

    cout << "\n\t UNSORTED \n";

    for(int i = 0; i < namecount; i++){
        cout << names[i] << " 's age is: " << ages[i] << '\n';
    }
    
    vectOfStrings sortedNames {names};
    vectOfDoubles sortedAges;

    sort(sortedNames.begin(), sortedNames.end());

    //push sorted ages
    for(int i = 0; i < namecount; i++){
        for(int j = 0; j < namecount; j++){
            if(sortedNames[i] == names[j]){
                sortedAges.push_back(ages[j]);
                break;
            }
        }
    }
    
    cout << "\n\t SORTED \n";
    for(int i = 0; i < namecount; i++){
        cout << sortedNames[i] << " 's age is: " << sortedAges[i] << '\n';
    }

    return 0;
}
