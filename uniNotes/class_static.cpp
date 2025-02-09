// class_static.cpp <- filename
#include <iostream>
using namespace std;

class Counter{
public:
    int count;
    Counter() { count = 0; }
    void display() { cout << count << endl; }
};

void counterFunction(){
    static Counter myCount;
    myCount.count++;
    myCount.display();
}

int main(){
    counterFunction(); // Output: Count: 1
    counterFunction(); // Output: Count: 2
    counterFunction(); // Output: Count: 3
    return 0;
}
