#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
constexpr int g_consoleLines{20};
#include "../libraries/random.h"

class Direction {
 public:
  enum Type {
    up,
    left,
    down,
    right,
    max,
  };

 public:
  Direction(Type type) : m_direction{type} {}
  Type getType() { return m_direction; }
  Direction operator-() const {
    switch (m_direction) {
      case up:
        return down;
      case down:
        return up;
      case left:
        return right;
      case right:
        return left;
      default:
        assert(false && "Invalid direction!");
        return max;
    }
  }
  static Direction getRandomDirection() {
    return Direction{static_cast<Type>(Random::get(0, 3))};
  }
  friend std::ostream& operator<<(std::ostream& os, const Direction& obj);
  Type getDirection() const { return m_direction; }

 private:
  Type m_direction;
};

std::ostream& operator<<(std::ostream& os, const Direction& obj) {
  switch (obj.m_direction) {
    case Direction::up:
      os << "Up";
      break;
    case Direction::down:
      os << "Down";
      break;
    case Direction::left:
      os << "Left";
      break;
    case Direction::right:
      os << "Right";
      break;
    default:
      os << "Invalid";
  }
  return os;
}

struct Point {
  int m_x_coord;
  int m_y_coord;
  Point getAdjacentPoint(Direction obj) {
    switch (obj.getType()) {
      case Direction::up:
        return Point{m_x_coord, m_y_coord - 1};
      case Direction::down:
        return Point{m_x_coord, m_y_coord + 1};
      case Direction::left:
        return Point{m_x_coord - 1, m_y_coord};
      case Direction::right:
        return Point{m_x_coord + 1, m_y_coord};
      default:
        break;
    }
    assert(0 && "Unsupported direction was passed!");
    return *this;
  }
};
bool operator==(const Point& p1, const Point& p2) {
  return p1.m_x_coord == p2.m_x_coord && p1.m_y_coord == p2.m_y_coord;
}

bool operator!=(const Point& p1, const Point& p2) { return !(p1 == p2); }

namespace UserInput {
bool isValidInput(char input) {
  return input == 'w' || input == 'a' || input == 's' || input == 'd' ||
         input == 'q';
}
void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
char getCharacter() {
  char operation{};
  std::cin >> operation;
  ignoreLine();  // remove any extraneous input
  return operation;
}

char getInput() {
  char inp{};
  while (!isValidInput(inp)) inp = getCharacter();
  return inp;
}

Direction charToDirection(char ch) {
  switch (ch) {
    case 'w':
      return Direction{Direction::up};
    case 's':
      return Direction{Direction::down};
    case 'a':
      return Direction{Direction::left};
    case 'd':
      return Direction{Direction::right};
    default:
      assert(false && "Invalid direction!");
      return Direction{Direction::max};
  }
}

}  // namespace UserInput

class Tile {
  int m_value{-1};

 public:
  Tile() {}
  Tile(int value) : m_value{value} {}
  int getNum() const { return m_value; }
  bool isEmpty() const { return !m_value; }
  friend std::ostream& operator<<(std::ostream& os, Tile& obj);
  friend bool operator!=(const Tile& t1, const Tile& t2);
};
bool operator!=(const Tile& t1, const Tile& t2) {
  return t1.m_value != t2.m_value;
}
std::ostream& operator<<(std::ostream& os, Tile& obj) {
  int num{obj.getNum()};
  if (num > 9)
    os << ' ' << num << ' ';
  else if (num > 0)
    os << "  " << num << ' ';
  else
    os << "    ";
  return os;
}

class Board {
  Tile elements[4][4];

 public:
  Board() {
    int num{};
    for (size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        if (num == 15)
          elements[i][j] = 0;
        else
          elements[i][j] = ++num;
      }
    }
  }
  friend std::ostream& operator<<(std::ostream& os, Board& obj);
  bool isValidTile(int x, int y) {
    return (x >= 0 && x < 4) && (y >= 0 && y < 4);
  }
  Point getEmptyTileLoc() {
    for (size_t y = 0; y < 4; y++) {
      for (size_t x = 0; x < 4; x++) {
        if (elements[y][x].getNum() == Tile{0}.getNum())
          return {static_cast<int>(x), static_cast<int>(y)};
      }
    }
    assert(0 && "There is no empty tile in the board!!!");
    return {-1, -1};
  }
  void swapTiles(Point& first, Point& second) {
    std::swap(elements[first.m_y_coord][first.m_x_coord],
              elements[second.m_y_coord][second.m_x_coord]);
  }
  bool moveTile(Direction& dir) {
    Point emptyTile{getEmptyTileLoc()};
    Point finalLocation{emptyTile.getAdjacentPoint(dir)};
    if (!isValidTile(finalLocation.m_x_coord, finalLocation.m_y_coord))
      return false;
    swapTiles(emptyTile, finalLocation);
    return true;
  }
  void randomize(int number) {
    while (number--) {
      Direction dir{Direction::getRandomDirection()};
      moveTile(dir);
    }
  }
  friend bool operator==(const Board& b1, const Board& b2) {
    for (size_t i = 0; i < 4; i++) {
      for (size_t j = 0; j < 4; j++) {
        if (b1.elements[i][j] != b2.elements[i][j]) {
          return false;
        }
      }
    }
    return true;
  }
  bool playerWon(const Board& solved) { return *this == solved; }
};

std::ostream& operator<<(std::ostream& os, Board& obj) {
  for (int i = 0; i < g_consoleLines; i++) os << '\n';
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      os << obj.elements[i][j];
    }
    os << '\n';
  }
  return os;
}

int main() {
  Board solved;
  Board board{};
  board.randomize(200);
  std::cout << board;

  std::cout << "Enter a command: ";
  while (true) {
    char ch{UserInput::getInput()};

    // Handle non-direction commands
    if (ch == 'q') {
      std::cout << "\n\nBye!\n\n";
      return 0;
    }

    // Handle direction commands
    Direction dir{UserInput::charToDirection(ch)};
    if (board.moveTile(dir))
      std::cout << board;
    else {
      std::cout << "\nInvalid direction, Please try again:";
      continue;
    }

    std::cout << "You entered direction: " << dir << '\n';
    if (board.playerWon(solved)) {
      std::cout << "\n\n\nYou Won !\n\n\n";
      break;
    }
  }

  return 0;
}
