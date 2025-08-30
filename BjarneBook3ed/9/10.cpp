#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <sstream>
using namespace std;

bool isAllowed(const char& current, const string& checklist){
    for(char i: checklist){
        if(current==i) return false;
    }
    return true;
}

string getFilteredString(const string &s, const string&w){
    string temp{};
    for(char i: s){
        if(isAllowed(i,w)){
            temp.push_back(i);
        }
    }
    return temp;
}

vector<string> split(const string &s, const string& w)
{
    vector<string> substrings;

    stringstream inputstr(s);

    vector<string>words;
    string temp{};
    while (inputstr >> temp)
    {
        words.push_back(temp);
    }

    for(string tempword: words){
        substrings.push_back(getFilteredString(tempword,w));
    }

    return substrings;
}

void printStr(const vector<string> &s)
{
    for (string i : s)
    {
        cout << i << '\n';
    }
}

int main()
{
    cout << "Enter string with separation characters: ";
	string w;
	getline(cin, w);
	cout << "Enter a few words: ";
	string s;
	while (getline(cin, s)) {
		vector<string> substrings = split(s, w);
		cout << "\nYou entered:\n";
		printStr(substrings);
		cout << "\nAnother try: ";
	}

    return 0;
}
