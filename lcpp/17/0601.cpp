#include <array>
#include <cassert>
#include <iostream>
#include <string_view>

using namespace std;

namespace Animal {

enum animal_type { chicken, dog, cat, elephant, duck, snake, max_animals };
array types{chicken, dog, cat, elephant, duck, snake};

struct Data {
  string_view name{"???"};
  int legs{};
  string_view sound{"???"};
};

array<Data, 6> data{{
    {"chicken", 4, "cluck"},
    {"dog", 4, "woof"},
    {"cat", 4, "meow"},
    {"elephant", 4, "pawoo"},
    {"duck", 2, "quack"},
    {"snake", 0, "hissss"},
}};

static_assert(size(types) == max_animals);
static_assert(size(data) == max_animals);

void printAnimal(const animal_type& in) {
  cout << "A " << data[in].name << " has " << data[in].legs << " legs and says "
       << data[in].sound << ".\n";
}

};  // namespace Animal

istream& operator>>(istream& is, Animal::animal_type& animal) {
  string input{};
  getline(is >> std::ws, input);
  for (size_t i{0}; i < Animal::data.size(); i++) {
    if (Animal::data[i].name == input) {
      animal = static_cast<Animal::animal_type>(i);
      return is;
    }
  }
  is.setstate(ios_base::failbit);
  return is;
}

int main() {
  cout << "Enter an animal: ";
  Animal::animal_type inAnimal{};
  cin >> inAnimal;

  if (cin)
    Animal::printAnimal(inAnimal);
  else {
    cin.clear();
    inAnimal = Animal::max_animals;
    cout << "That animal couldn't be found.\n";
  }

  cout << "\n\nHere is the data for the rest of the animals:\n";

  for (const auto& i : Animal::types) {
    if (i != inAnimal) Animal::printAnimal(i);
  }

  return 0;
}
