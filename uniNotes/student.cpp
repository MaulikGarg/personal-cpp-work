#include <iostream>
#include <string> //for strings, not char arrays
using std::string, std::cout;

class Student{
public:
    unsigned rollNum;
    string branch;

private:
    bool isEligible()
    {
        if (rollNum < 2000) return true;
        return false;
    }
};

int main(){
    Student maulik; //object made
    maulik.branch = "CSE"; //public data member accessed
    maulik.rollNum = 1057;

    cout << maulik.isEligible();
    //cannot call the function as it is private.
    //this program will not compile because this gives error

    return 0;
}

