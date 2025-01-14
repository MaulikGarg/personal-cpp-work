#include <iostream>
using namespace std;

namespace constants{
    constexpr double gravity {9.8};
}
double calculateHeight(double height, int seconds)
{

    return height - (constants::gravity * seconds * seconds) / 2;
}

int main()
{
    double height{};
    cout << "Enter the height of the tower in meters: ";
    cin >> height;

    for (int i = 0;; i++)
    {
        double heightnow{calculateHeight(height, i)};
        if (heightnow > 0)
        {
            cout << "At " << i << " seconds, the ball is at height: " << heightnow << " meters" << endl;
        }
        else
        {
            cout << "At " << i << " seconds, the ball is on the ground." << endl;
            break;
        }
    }

    return 0;
}
