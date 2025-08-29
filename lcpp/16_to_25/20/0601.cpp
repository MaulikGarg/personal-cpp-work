#include <algorithm>
#include <array>
#include <iostream>
#include <string>
using namespace std;

struct Student {
  string_view name{};
  double points{};
};

int main() {
  std::array<Student, 8> arr{{{"Albert", 3},
                              {"Ben", 5},
                              {"Christine", 2},
                              {"Dan", 8},  // Dan has the most points (8).
                              {"Enchilada", 4},
                              {"Francis", 1},
                              {"Greg", 3},
                              {"Hagrid", 5}}};

  const auto& maxScore{max_element(arr.begin(), arr.end(),
                                   [](const Student& s1, const Student& s2) {
                                     return s1.points < s2.points;
                                   })};
  cout << maxScore->name << " is the best student.";
  return 0;
}
