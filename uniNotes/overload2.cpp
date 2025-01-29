//overload2.cpp <- file name
#include <iostream>
using std::cout;

class Box {
private:
    int length;

public:
    Box(int l) { length = l; }  // Constructor

    // Overload + operator using a member function
    Box operator+(Box b) {
        return Box(length + b.length); // Adds the lengths and returns a new Box
    }

    void showLength() { cout << "Length: " << length << '\n'; }
};

int main() {
    Box b1(10), b2(20); 
    Box b3 = b1 + b2;  // Calls operator+ function
    b3.showLength();    // Output: Length: 30
}
