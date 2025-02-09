//simple_static.cpp <- filename
#include <iostream>
using namespace std;

void counterFunction() {
    static int count = 0;  // Static variable
    count++; //increase count by 1
    cout << "Count: " << count << endl;
}

int main() {
    counterFunction();  // Output: Count: 1
    counterFunction();  // Output: Count: 2
    counterFunction();  // Output: Count: 3
    return 0;
}
