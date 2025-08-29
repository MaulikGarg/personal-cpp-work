#include<iostream>
using namespace std;

class Point3d{
    private:
        int x;
        int y;
        int z;
    public:
        void setValues(int inX, int inY, int inZ){
            x = inX;
            y = inY;
            z = inZ;
        }
        void print(){
            cout << "<" << x << ", " <<  y << ", " <<  z << ">\n"; 
        }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}
