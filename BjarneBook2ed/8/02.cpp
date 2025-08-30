#include<iostream>
#include<vector>
#include<string>
using namespace std;


void print(const string& stringe, const vector<int>& vecint){
    cout << stringe << '\n';
    for(int i: vecint){
        cout << i << ' ';
    }
}
int main()
{
    string name {"my string"};
    vector<int> myV;
    myV.resize(10,3);
    print(name,myV);
    

    return 0;
}
