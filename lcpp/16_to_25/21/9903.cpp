#include <cassert>
#include <iostream>
using namespace std;

class IntArray {
  int m_length{};
  int* m_arr{nullptr};
  void copy(const IntArray& arr) {
    if (&arr == this) return;
    delete[] this->m_arr;
    this->m_length = arr.m_length;
    this->m_arr = new int[m_length];
    for (int count{}; count < arr.m_length; count++) {
      this->m_arr[count] = arr.m_arr[count];
    }
  }

 public:
  ~IntArray() { delete[] m_arr; }
  IntArray(int length) : m_length{length}, m_arr{new int[length]} {
    assert(length > 0);
  }
  IntArray(const IntArray& arr) { copy(arr); }
  int& operator[](int index) {
    assert(index >= 0 && index < m_length);
    return m_arr[index];
  }
  IntArray& operator=(const IntArray& arr) {
    copy(arr);
    return *this;
  }
  friend ostream& operator<<(ostream& os, const IntArray arr);
};

ostream& operator<<(ostream& os, const IntArray arr) {
  for (int count{}; count < arr.m_length; count++) {
    os << arr.m_arr[count] << ' ';
  }
  return os;
}

IntArray fillArray() {
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main() {
  IntArray a{fillArray()};

  std::cout << a << '\n';

  auto& ref{a};  // we're using this reference to avoid compiler self-assignment
                 // errors
  a = ref;

  IntArray b(1);
  b = a;

  a[4] = 7;

  std::cout << b << '\n';

  return 0;
}
