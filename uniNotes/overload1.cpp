#include<iostream>
using std::cout;

void print(int num) { //same name but takes one integer 
    cout << "Integer: " << num << '\n';
}
void print(double num) { //same name but takes one double
    cout << "Double: " << num << '\n';
}
void print(int num, double dec) { // same name but takes two arguements
    cout << "Integer: " << num << ", Double: " << dec << '\n';
}

int main()
{
    print(1); //calls first function
    print(1.0); //calls second function
    print(1,1.0); //calls third function
    return 0;
}
