#include<iostream>
using std::cout;

class Circle{
    private:
        double radius;
    public:
        Circle(){ //constructor1 without arguments
            radius = 1;
        }
        Circle(double r){ //constructor2 with arguments
            radius = r;
        }
        double area(){
            return (3.14*radius*radius);
        }
};
int main()
{
    Circle C1; //calls the constructor1 
    Circle C2(10); //calls the constructor2
    cout << C1.area() << '\n'; //prints 3.14, as 3.14*1*1
    cout << C2.area() << '\n'; //prints 314 as 3.14*10*10
    return 0;
}

