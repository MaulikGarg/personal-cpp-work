#include <iostream>

using std::cin;
using std::cout;

int readNumber(){
    int temporaryInteger{};
    cout << "Enter a number: ";
    cin >> temporaryInteger;
    return temporaryInteger;
}

void writeAnswer(int num){
    cout << "The number sum is: " << num;
}
