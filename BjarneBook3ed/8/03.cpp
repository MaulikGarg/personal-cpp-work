#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
using namespace std;

class Name_Pairs
{
public:
    vector <pair<string,int>> names;
    void read_names();
    void read_ages();
    void mysort();
    bool operator==(Name_Pairs& comparedPair) const;
    bool operator!=(Name_Pairs& comparedPair) const;
};

void Name_Pairs::read_names(){
    cout << "Enter the names(Enter 0 to terminate): ";
    string temp{""};
    while(cin>>temp){
        if(temp == "0") break;
        names.push_back({temp,0});
    }
}

void Name_Pairs::read_ages(){
    if(names.size() < 1) exit(1);
    for(int i = 0; i < static_cast<int>(names.size()); i++) {
        cout << "Enter " << names[i].first << "'s age: ";
        int temp{};
        cin >> temp;
        names[i].second = temp;
    }
}

void Name_Pairs::mysort(){
    if(names.size() < 1) exit(1);
    sort(names.begin(), names.end());
}

ostream& operator<<(ostream& os, const Name_Pairs& pair){
    os << '\n';
    for(int i=0; i < static_cast<int>(pair.names.size()); i++){
        os << pair.names[i].first << " has age: " << pair.names[i].second << '\n';
    }
    return os;
}

bool Name_Pairs::operator==(Name_Pairs& comparedPair) const{
    if (names.size() != comparedPair.names.size()) return false;
    for (int i = 0; i < static_cast<int>(names.size()); i++)
    {
        if(names[i] != comparedPair.names[i]) return false;
    }
    return true;
}

bool Name_Pairs::operator!=(Name_Pairs& comparedPair) const{
    if (names.size() != comparedPair.names.size()) return true;
    for (int i = 0; i < static_cast<int>(names.size()); i++)
    {
        if(names[i] != comparedPair.names[i]) return true;
    }
    return false;
}

int main()
{
    Name_Pairs mypair;
    mypair.read_names();
    mypair.read_ages();
    
    cout << mypair;

    Name_Pairs mysecondPair;
    mysecondPair.read_names();
    mysecondPair.read_ages();
    
    return 0;
}
