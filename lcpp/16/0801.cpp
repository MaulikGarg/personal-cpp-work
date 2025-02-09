#include<iostream>
#include<string>
#include<string_view>
#include<vector>
using namespace std;

int main()
{
    const vector<string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    cout << "Enter a name: ";
    string name;
    cin >> name;

    bool found {false};
    for(const auto& currentName : names){
        if(currentName == name) found = true;
    }  

    cout << name << " was ";
    cout << (found ? "" : "not ");
    cout << "found.";
    
    return 0;
}
