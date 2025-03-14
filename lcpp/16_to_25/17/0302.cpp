#include <String>
#include <array>
#include <iostream>

struct Item {
  std::string_view name{"???"};
  int gold{};
};

int main() {
  // constexpr std::array items{Item{"sword", 5}, Item{"dagger", 3}, Item{"club", 2}, Item{"spear", 7}};
  constexpr std::array<Item, 4> items{
      {{"sword", 5}, {"dagger", 3}, {"club", 2}, {"spear", 7}}};
  for (const auto &c_item : items) {
    std::cout << "A " << c_item.name << " costs " << c_item.gold << " gold.\n";
  }
}
