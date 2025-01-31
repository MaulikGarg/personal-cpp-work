#include <iostream>
using namespace std;

class Point3d
{
private:
    int x;
    int y;
    int z;

public:
    void setValues(int inX, int inY, int inZ)
    {
        x = inX;
        y = inY;
        z = inZ;
    }
    bool isEqual(Point3d compared)
    {
        return x == compared.x &&
               y == compared.y &&
               z == compared.z;
    }
};

int main()
{
    Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}
