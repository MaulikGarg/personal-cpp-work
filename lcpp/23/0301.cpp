#include <functional>
#include <iostream>
#include <string>

class Teacher {
 private:
  std::string m_name{};

 public:
  Teacher(std::string_view name) : m_name{name} {}

  const std::string& getName() const { return m_name; }
};

class Department {
 private:
  std::vector<std::reference_wrapper<const Teacher>> teachers{};

 public:
  Department() {}
	void add (Teacher& teach) { teachers.push_back(teach); }
	friend std::ostream& operator<<(std::ostream& os , const Department& dept);
};

std::ostream& operator<<(std::ostream& os , const Department& dept){
	os << "Department : ";
	for(auto i: dept.teachers){
		os << i.get().getName() << ' ';
	}
	os << '\n';
	return os;
}

int main() {
  // Create a teacher outside the scope of the Department
  Teacher t1{"Bob"};
  Teacher t2{"Frank"};
  Teacher t3{"Beth"};

  {
    // Create a department and add some Teachers to it
    Department department{};  // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  }  // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
}
