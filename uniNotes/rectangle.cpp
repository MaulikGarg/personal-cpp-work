#include <iostream>

using std::cout; // can use cout without the std:: prefix

class Rectangle
{
private: // these are the data members
    int length;
    int breadth;

public:                      // these are the member functions / methods
    void input(int l, int b) // puts the values from given literals into data members
    {
        length = l;
        breadth = b;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
    int area()
    {
        return length * breadth;
    }
};

int main()
{
    Rectangle myRect;   // makes object of type Rectangle with name myRect
    myRect.input(1, 2); // 1,2 literals used for length and breadth
    cout << "Area: " << myRect.area() << '\n';
}
