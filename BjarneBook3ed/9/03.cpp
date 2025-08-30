/*Write a program that removes all vowels from a file (‘‘disemvowels’’). For example, Once
upon a time! becomes nc pn tm!. Surprisingly often, the result is still readable; try it on your
friends.*/

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <fstream>

using namespace std;

// get the file name
void getFileName(string &name, const string &inOrOut)
{
    cout << "Enter the " << inOrOut << " file name with extension: ";
    cin >> name;
}

bool isVowel(const char character){
    switch (tolower(character))
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    
    default:
        return false;
    }
}

void getFromFile(vector<char>& instring)
{
    // get the file name
    string filename{};
    getFileName(filename, "input");

    // open the input file
    ifstream inputFile{filename.c_str()};
    if (!inputFile)
        exit(1);

    char current{};
    while (inputFile.get(current))
    {
        if(!isVowel(current)){
            instring.push_back(current);
        }
    }
}


int main()
{
    // first we make an input string to get all the character input from the string
    vector<char> inString{};
    getFromFile(inString);

    for(char i: inString){
        cout << i;
    }

    return 0;
}
