#include <iostream>
using namespace std;

double calculateHeight(double height, int seconds)
{

    return height - (9.8 * seconds * seconds) / 2;
}

int main()
{
    double height{};
    cout << "Enter the height of the tower in meters: ";
    cin >> height;

    cout << "At 0 seconds, the ball is at height: " << height << " meters" << endl;
    cout << "At 1 seconds, the ball is at height: " << calculateHeight(height, 1) << " meters" << endl;
    cout << "At 2 seconds, the ball is at height: " << calculateHeight(height, 2) << " meters" << endl;
    cout << "At 3 seconds, the ball is at height: " << calculateHeight(height, 3) << " meters" << endl;
    cout << "At 4 seconds, the ball is at height: " << calculateHeight(height, 4) << " meters" << endl;
    
    if (calculateHeight(height, 5) > 0)
        cout << "At 5 seconds, the ball is at height: " << calculateHeight(height, 5) << " meters" << endl;
    else
        cout << "At 5 seconds, the ball is on the ground." << endl;

    return 0;
}
