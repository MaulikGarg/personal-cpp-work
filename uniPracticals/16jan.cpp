#include <iostream>
#include <cmath>

using namespace std;

class Rectangle
{
private:
    double length{};
    double breadth{};

public:
    void input(double len, double bre)
    {
        length = len;
        breadth = bre;
    }
    void area()
    {
        cout << "area: " << length * breadth << '\n';
    }
    void perimeter()
    {
        cout << "perimeter: " << 2 * (length + breadth) << '\n';
    }
    void diagonal()
    {
        cout << "diagonal: " <<  sqrt(pow(length,2)+pow(breadth,2)) << '\n';
    }
};

int main()
{
    Rectangle R1;
    cout << "enter the length and breadth: ";
    double inputLenght{};
    double inputBreadth{};
    cin >> inputLenght >> inputBreadth;
    R1.input(inputLenght, inputBreadth);

    int calculation{};
    cout << "type 1 for area, 2 for perimeter, 3 for diagonal lenght: ";
    cin >> calculation;

    switch (calculation)
    {
    case 1:
        R1.area();
        break;
    case 2:
        R1.perimeter();
        break;
    case 3:
        R1.diagonal();
        break;
    
    default:
        break;
    }
    return 0;
}
