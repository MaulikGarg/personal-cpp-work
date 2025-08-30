#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "../libraries/random.h"

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace Potion {
enum Type {
  healing,
  mana,
  speed,
  invisibility,
  max,
};

constexpr std::array types{healing, mana, speed, invisibility};
constexpr std::array prices{20, 30, 12, 50};
constexpr std::array<std::string_view, Type::max> names{
    "healing", "mana", "speed", "invisibility"};
static_assert(Type::max == std::size(prices));
static_assert(Type::max == std::size(names));

}  // namespace Potion

Potion::Type getInput() {
  char input;
  while (true) {
    std::cin >> input;
    // if cin fails, clear stream and go back
    if (!std::cin) {
      ignoreLine();
      std::cin.clear();
    }

    // check if there is more input than just one character
    if (std::cin.peek() != '\n' || std::cin.eof()) {
      std::cout << "I didn't understand what you said.  Try again: ";
      ignoreLine();
      continue;
    }

    if (input == 'q') return Potion::max;

    int val{input - '0'};
    if (val >= 0 && val < Potion::max) return static_cast<Potion::Type>(val);

    // if we reach here then its invalid
    std::cout << "I didn't understand what you said. Try again: ";
    ignoreLine();
  }
}

void shop() {
  std::cout << "\nHere is our selection for today:\n";
  for (auto i : Potion::types) {
    std::cout << i << ") " << Potion::names[i] << " costs " << Potion::prices[i]
              << '\n';
  }
}

class Player {
  static constexpr int m_minGoldStart{80};
  static constexpr int m_maxGoldStart{120};
  std::string m_name{"???"};
  std::array<int, Potion::max> m_inventory{};
  int m_gold;

  void setName() {
    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, m_name);
  }

 public:
  Player() : m_gold{Random::get(m_minGoldStart, m_maxGoldStart)} { setName(); }
  std::string_view getName() { return m_name; }
  int getGold() { return m_gold; }
  void purchase();
  void displayInv();
};

void Player::purchase() {
  while (true) {
    shop();
    std::cout
        << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    Potion::Type selected{getInput()};
    if (selected == Potion::max) return;
    // check if player can afford
    if (m_gold > Potion::prices[selected]) {
      m_gold -= Potion::prices[selected];
      m_inventory[selected]++;
      std::cout << "You purchased a potion of " << Potion::names[selected]
                << ". You have " << m_gold << " gold left.\n";
    } else {
      std::cout << "You can not afford that.\n";
    }
  }
}

void Player::displayInv() {
  std::cout << "\nYour inventory contains:\n";
  for (auto i : Potion::types) {
    std::cout << m_inventory[i] << "x potion of " << Potion::names[i] << '\n';
  }
}

int main() {
  std::cout << "Welcome to Roscoe's potion emporium!\n";
  Player player;
  std::cout << "Hello, " << player.getName() << ", you have "
            << player.getGold() << " gold.\n";
  player.purchase();
  player.displayInv();
  std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
  return 0;
}
