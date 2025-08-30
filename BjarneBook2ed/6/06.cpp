// Chapter 06, exercise 06: implement given grammar, check if sentence follows
// the grammar

/*
    Implements this grammar:

    Sentence:
        Subject Verb
        Sentence Conjunction Sentence

        Subject:
            Noun
            "the" Noun

        Conjunction:
            "and"
            "or"
            "but"

        Noun:
            "birds"
            "fish"
            "C++"

        Verb:
            "rules"
            "fly"
            "swim"

    and checks if an entered sentence is correct according to it or not.
*/

#include <iostream>
#include <string>

using namespace std;

void error(string msg)
{
    cerr << msg;
    exit(1);
}

// class string stream which gets the string input into a stream

class String_stream
{
private: // used for getting the buffer string and seeing if buffer is already full
    bool full;
    string buffer;

public:
    String_stream() : full(false), buffer("") {}; // constructor function
    string get();                                 // gets a string
    void putback(string s);                       // puts back the string into the buffer
};

string String_stream::get()
{
    if (full)
    { // if the buffer is full, empty the buffer and return the buffered string
        full = false;
        return buffer;
    }

    string s{""};
    cin >> s;
    return s;
}

void String_stream::putback(string s)
{ // for filling the buffer
    if (full)
        error("attempt to putback into an already filled buffer"); // if buffer somehow happens to be fill already.
    buffer = s;
    full = true;
}

String_stream userString;

bool isNoun()
{ // checks if its an accepeted noun
    string s = userString.get();
    if (s == "birds" || s == "fish" || s == "c++")
        return true;
    else
        return false;
}

bool isVerb()
{ // checks if its an accepeted verb
    string s = userString.get();
    if (s == "rules" || s == "fly" || s == "swim")
        return true;
    else
        return false;
}

bool isConjunction()
{ // checks if its an accepeted Conjunction
    string s = userString.get();
    if (s == "and" || s == "or" || s == "but")
        return true;
    else
        return false;
}

bool isSubject()
{ // checks for subject, if there is an article "The", calls noun, otherwise puts string back into buffer and calls noun like normal
    string s = userString.get();
    if (s == "The")
    {
        return isNoun();
    }
    else
    {
        userString.putback(s);
        return isNoun();
    }
}

bool isSentence()
{
    return (isSubject() && isVerb());
}

void isNotOk()
{
    cout << "Not OK.";
    exit(0);
}

void isOk()
{
    cout << "OK.";
    exit(0);
}
int main()
{
    cout << "Enter a sentence: ";
    while (true)
    {
        bool isValid{false};
        if (!isSentence())
            isNotOk();

        // now here we are sure a valid sentence has been input.
        string s = userString.get();
        if (s == ".")
            isOk(); // returns true if successful periodt has been received.
        else
        {
            userString.putback(s);
            isValid = isConjunction();
            if (!isValid)
                isNotOk();
        }
    }
}
