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
        instring.push_back(current);
    }
}

void writeToFile(const vector<char> &lowercasedVector)
{
    // get the file name
    string filename{};
    getFileName(filename, "output");

    // open the input file
    ofstream outputFile{filename.c_str()};
    if (!outputFile)
        exit(1);
    
    for (char current : lowercasedVector)
    {
        outputFile << current;
    }

}

int main()
{
    // first we make an input string to get all the character input from the string
    vector<char> inString{};
    getFromFile(inString);

    // vector of lowercases
    vector<char> lowerString{};

    // inputting into the vector
    for (char current : inString)
    {
        lowerString.push_back(tolower(current));
    }

    // put this new vector into output file
    writeToFile(lowerString);

    cout << "Write successful!";

    return 0;
}
