#include<iostream>
#include<string>
#include<string_view>
#include<vector>
using namespace std;

int main()
{
    vector word { 'h','e','l','l','o'};
    cout << "The array has " << word.size() << " elements.\n";
    cout << word[1] << word.at(1);
    return 0;
}
