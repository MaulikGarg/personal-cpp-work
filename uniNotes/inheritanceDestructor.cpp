#include<iostream>
using namespace std;

class Base{
  public:
    Base(){cout << "Base Constructor called\n";}
    ~Base(){cout << "Base Destructor called\n";}
};

class Derived : public Base {
  public:
    Derived(){cout << "Derived Constructor called\n";}
    ~Derived(){cout << "Derived Destructor called\n";}
};

int main()
{
  Derived object; // constructor called
  return 0;
} //destructor is called here
