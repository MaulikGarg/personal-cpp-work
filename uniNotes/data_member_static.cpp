//data_member_static.cpp <- filename
#include <iostream>
using namespace std;

class MyClass {
public:
    static int count;  // Static data member declaration
    MyClass() {
        count++;  // constructor: Increment the count when an object is created
    }
};

// Initialize the static data member outside the class
int MyClass::count = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    std::cout << MyClass::count;  // Outputs 2
    return 0;
}
