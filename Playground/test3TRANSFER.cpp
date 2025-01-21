#include<iostream>
using namespace std;

class Test{
    private:
        int code;
    public:
        int* getlocation(){
            return &code;
        }
        void display(){
            cout << code << '\n';
        }
};

int main()
{
    Test myTest;
    int* myPointer = myTest.getlocation();
    *myPointer = 4;
    myTest.display();
    return 0;
}
