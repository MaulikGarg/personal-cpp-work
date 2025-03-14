#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct StudentGrade {
  std::string name{};
  char grade{};
};

class GradeMap {
  std::vector<StudentGrade> m_map;

 public:
  char& operator[](std::string name) {
    auto it = find_if(
        m_map.begin(), m_map.end(),
        [&](const StudentGrade& compared) { return name == compared.name; });
      
    if (it != m_map.end()) return it->grade;

    return m_map.emplace_back(std::string{name}).grade;
  }
};

int main() {
  GradeMap grades{};

  grades["Joe"] = 'A';
  grades["Frank"] = 'B';

  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

  return 0;
}
