#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
using namespace std;


class Name_Pairs
{
private:
    vector <pair<string,int>> names;
public:
    void read_names();
    void read_ages();
    void print();
    void mysort();

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

void Name_Pairs::print(){
    if(names.size() < 1) exit(1);
    cout << '\n\n';
    for(int i = 0; i < static_cast<int>(names.size()); i++){
        cout << names[i].first << " is " << names[i].second << " years old.\n";
    }
}

void Name_Pairs::mysort(){
    if(names.size() < 1) exit(1);
    sort(names.begin(), names.end());
}
int main()
{
    Name_Pairs mypair;
    mypair.read_names();
    mypair.read_ages();
    mypair.print();
    mypair.mysort();
    mypair.print();


    return 0;
}
