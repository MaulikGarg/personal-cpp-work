// inheritance3.cpp <- filename
#include <iostream>
#include <string>
using namespace std;

class Camera {
 public:
  int megapixel;
};

// not all phones have cameras, so we don't do Phone : Camera
class Phone {
 public:
  int phoneNumber;
};

// smartPhones have both camera and phone abilities
class smartPhone : public Camera, public Phone {
 public:
  smartPhone(int mp, int num) {  // constructor
    megapixel = mp;
    phoneNumber = num;
  }
};

int main() {
  smartPhone myPhone(69, 1234567890);
  cout << "My phone has " << myPhone.megapixel
       << " megapixel camera and my phone number is " << myPhone.phoneNumber;
  return 0;
}
