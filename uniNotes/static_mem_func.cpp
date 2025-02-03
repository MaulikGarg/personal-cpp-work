//static_mem_func.cpp <- filename
#include <iostream>
using namespace std;

class MyClass {
private:
     static int count;  // Static data member declaration
public:
    MyClass() {
        count++;  // constructor: Increment the count when an object is created
    }
    static int getCount() {return count;}
};

// Initialize the static data member outside the class because non const
int MyClass::count = 1;

int main() {
    cout << MyClass::getCount() << '\n'; //prints 1
    MyClass t1; //constructor adds 1 to count
    cout << t1.getCount(); //prints 2, static function used
    return 0;
}
