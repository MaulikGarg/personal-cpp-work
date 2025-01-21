#include<iostream>
using std::cout;

class Student
{
private:
    int rollNum; //only 1 int in object so whole object size is 4 bytes in most cases

public:
    Student(){rollNum = 57;} //constructor                    
};

int main()
{
    Student myStudent[5];
    for(int i = 0; i < 5; i++){
        cout << "The location of Student " << i << " is at: " << &myStudent[i] << '\n';
    } //above statement prints the address of the location
}
