#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <fstream>
#include <string_view>

using namespace std;

// get the file name
void getFileName(string &name, const string &inOrOut)
{
    cout << "Enter the " << inOrOut << " file name with extension: ";
    cin >> name;
}

bool hasWord(string_view currentline, string_view word){
    return currentline.find(word) != string_view::npos;
}

void getFromFile(vector<string>& instring)
{
    string word{};
    cout << "Enter the word to look for: ";
    cin >> word;

    // get the file name
    string filename{};
    getFileName(filename, "input");

    // open the input file
    ifstream inputFile{filename.c_str()};
    if (!inputFile)
        exit(1);

    string currentLine;
    bool found{false};
    while(getline(inputFile, currentLine)){
        if(hasWord(currentLine, word)){
            instring.push_back(currentLine);
            found = true;
        }
    }
    if(!found) cout << "No string found!";
    
}

int main()
{
    // first we make an input string to get all the character input from the string
    vector<string> inString{};
    
    getFromFile(inString);

    for(auto i: inString){
        cout << i << '\n';
    }

    return 0;
}
