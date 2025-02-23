#include <iostream>
#include <string>

#include "../libraries/random.h"

using namespace std;

class Creature {
 protected:
  string_view m_name{};
  char m_symbol{};
  int m_health{};
  int m_damage{};
  int m_gold{};

 public:
  // constructor
  Creature(string_view name, char symbol, int health, int damage, int gold)
      : m_name{name},
        m_symbol{symbol},
        m_health{health},
        m_damage{damage},
        m_gold{gold} {}

  // operations

  void reduceHealth(int dmgDealt) { m_health -= dmgDealt; }
  bool isDead() const { return m_health <= 0; }
  void addGold(int gold) { m_gold += gold; }

  // getters
  const string_view getName() const { return m_name; }
  char getSymbol() const { return m_symbol; }
  int getHealth() const { return m_health; }
  int getDamage() const { return m_damage; }
  int getGold() const { return m_gold; }
};

class Player : public Creature {
  int m_level{1};

 public:
  void replenishHealth(int hp) { m_health += hp; }
  Player(string_view name) : Creature{name, '@', 10, 1, 0}, m_level{1} {}
  void levelUp() {
    m_damage++;
    m_level++;
  }
  int getLevel() const { return m_level; }
  bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature {
 public:
  enum Type { dragon, orc, slime, max };
  Monster(Type type) : Creature{monsterData[type]} {}
  static Monster getRandomMonster() {
    return Monster{static_cast<Type>(Random::get(0, max - 1))};
  }

 private:
  static inline Creature monsterData[]{{"Dragon", 'D', 20, 4, 100},
                                       {"Orc", 'O', 4, 2, 25},
                                       {"Slime", 'S', 1, 1, 10}};
  static_assert(std::size(monsterData) == max);
};

void attackPlayer(Monster& monster, Player& player) {
  cout << "The " << monster.getName() << " hit you for " << monster.getDamage()
       << " damage.\n";
  player.reduceHealth(monster.getDamage());
}

void attackMonster(Monster& monster, Player& player) {
  int extraDmg{Random::get(0, 3)};
  cout << "You hit the " << monster.getName() << " for " << player.getDamage()
       << " damage with an additional " << extraDmg << " damage. ("
       << player.getDamage() + extraDmg << ") .\n";
  monster.reduceHealth(player.getDamage() + extraDmg);
  if (!monster.isDead()) attackPlayer(monster, player);
}

bool fightMonster(Monster& monster, Player& player) {
  cout << "Monster Health: " << monster.getHealth() << '\n';
  cout << "(R)un or (F)ight: ";
  char action;
  cin >> action;
  if (action == 'R') {
    if (Random::get(0, 1)) {
      cout << "You successfully fled.\n";
      return true;
    } else {
      cout << "You failed to flee.\n";
      attackPlayer(monster, player);
    }
  } else {
    attackMonster(monster, player);
  }
  return false;
}

void encounter(Monster& monster, Player& player) {
  while (!monster.isDead()) {
    if (fightMonster(monster, player)) return;
    if (player.isDead()) break;
    if (monster.isDead()) {
      player.addGold(monster.getGold());
      player.levelUp();
      cout << "You killed the " << monster.getName() << "\nYou are now level "
           << player.getLevel() << "\nYou found " << monster.getGold()
           << " gold.\n";
      if (player.getLevel() % 3 == 0) {
        int increasedHealth{Random::get(2, 5)};
        cout << "You've regained " << increasedHealth << " Health points!\n";
        player.replenishHealth(increasedHealth);
      }
      break;
    }
  }
}

int main() {
  cout << "Enter your name: ";
  std::string input;
  cin >> input;
  cout << "Welcome, " << input << ". \n";
  Player player{input};

  while (!player.hasWon() && !player.isDead()) {
    Monster monster{Monster::getRandomMonster()};
    cout << "You have encountered a " << monster.getName() << '('
         << monster.getSymbol() << ").\n";
    encounter(monster, player);
  }

  if (player.isDead()) {
    cout << "You died at level " << player.getLevel() << " with "
         << player.getGold()
         << " gold.\n Too bad you can't take it with you!\n";
  } else if (player.hasWon()) {
    cout << "You have conquered the almighty beasts and escaped the fierce "
            "dungeon!\nWhat adventures await you next, oh "
         << player.getName() << ", the traveler with " << player.getGold()
         << " gold. \n ";
  }

  return 0;
}
