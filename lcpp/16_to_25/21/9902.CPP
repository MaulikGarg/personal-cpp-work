#include <iostream>
using namespace std;

class Average {
  std::int32_t sum{};
  int count{};

 public:
  friend ostream& operator<<(ostream& os, const Average& obj);
  Average& operator+=(int num) {
    count++;
    sum += num;
    return *this;
  }
};
ostream& operator<<(ostream& os, const Average& obj) {
  if (obj.count == 0) {
    os << obj.sum;
  } else
    os << static_cast<double>(obj.sum) / obj.count;
  return os;  
}

int main() {
  Average avg{};
  std::cout << avg << '\n';

  avg += 4;
  std::cout << avg << '\n';  // 4 / 1 = 4

  avg += 8;
  std::cout << avg << '\n';  // (4 + 8) / 2 = 6

  avg += 24;
  std::cout << avg << '\n';  // (4 + 8 + 24) / 3 = 12

  avg += -10;
  std::cout << avg << '\n';  // (4 + 8 + 24 - 10) / 4 = 6.5

  (avg += 6) += 10;          // 2 calls chained together
  std::cout << avg << '\n';  // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

  Average copy{avg};
  std::cout << copy << '\n';

  return 0;
}
