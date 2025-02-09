#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void getInputFromFile(vector<string>* tobefilled){
    cout << "Enter the file name without extension: ";
    string input{};
    cin >> input;
    
    ifstream file{input+".txt"};

    string temp{};
    while (getline(file,temp))
    {
        tobefilled->push_back(temp);
    }   
}

vector<string> reverseInput(const vector<string>& ogMessage){
    vector<string> reversedString;

    for(string i: ogMessage){
        string word{};
        //for each line, reverse it by word
        for(int current = i.size() - 1; 0<=current; current--){
            word.push_back(i[current]);
        }
        reversedString.push_back(word);
    }
    return reversedString;
} 

int main(){
    vector<string> originalMessage{};
    getInputFromFile(&originalMessage);

    vector<string> reversedMessage{reverseInput(originalMessage)};

    for(string i: reversedMessage){
        cout << i << '\n';
    }
}
