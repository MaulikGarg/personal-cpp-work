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

namespace settings {
constexpr int maxScore{21};
constexpr int dealerMinDraw{17};
}  // namespace settings

struct Card {
  enum Rank {
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_maxrank
  };
  enum Suit {
    suit_clubs,
    suit_diamonds,
    suit_hearts,
    suit_spades,
    suit_maxsuit
  };

  Rank rank{};
  Suit suit{};

  static constexpr std::array s_allRanks{
      rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,   rank_7,
      rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king};

  static constexpr std::array s_allSuits{suit_clubs, suit_diamonds, suit_hearts,
                                         suit_spades};

  friend std::ostream& operator<<(std::ostream& out, const Card& card) {
    static constexpr std::array rankLetters{'A', '2', '3', '4', '5', '6', '7',
                                            '8', '9', 'T', 'J', 'Q', 'K'};
    static constexpr std::array suitLetters{'C', 'D', 'H', 'S'};

    out << rankLetters[card.rank] << suitLetters[card.suit];
    return out;
  }

  int value() const {
    static constexpr std::array rankValues{11, 2, 3,  4,  5,  6, 7,
                                           8,  9, 10, 10, 10, 10};
    return rankValues[rank];
  }
};

class Deck {
  std::array<Card, 52> m_deck{};
  size_t m_nextCard{};

 public:
  Deck() {
    size_t current{};
    for (auto& i : Card::s_allSuits) {
      for (auto& j : Card::s_allRanks) {
        m_deck[current++] = Card{j, i};
      }
    }
  }

  Card dealCard() {
    assert(m_nextCard != 52);
    return m_deck[m_nextCard++];
  }

  void shuffle() {
    std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
    m_nextCard = 0;
  }
};

struct Player {
  int score{};
};

bool dealerLost(Deck& current, Player& dealer) {
  while (dealer.score < settings::dealerMinDraw) {
    Card currentDraw{current.dealCard()};
    dealer.score += currentDraw.value();
    std::cout << "The dealer draws a " << currentDraw << ". They now have "
              << dealer.score << '\n';
  }

  if (dealer.score > settings::maxScore) {
    std::cout << "The dealer went a bust!\n";
    return true;
  }

  return false;
}

// return true if player wins
bool play() {
  Deck current;
  current.shuffle();

  Player dealer{current.dealCard().value()};
  std::cout << "The dealer shows: " << dealer.score << '\n';

  Player player{current.dealCard().value() + current.dealCard().value()};
  std::cout << "You have score: " << player.score << '\n';

  while (true) {
    std::cout << "(h) to hit, or (s) to stand: ";
    char input;
    std::cin >> input;

    if (!std::cin || (input != 'h' && input != 's')) {
      std::cout << "Invalid input please try again.\n";
      std::cin.clear();
      ignoreLine();
      continue;
    }

    if (input == 's')
      break;
    else {
      Card currentDraw{current.dealCard()};
      player.score += currentDraw.value();
      std::cout << "You were dealt " << currentDraw << ".  You now have: " << player.score << '\n';
      if(player.score > settings::maxScore){
        std::cout << "You went bust.\n";
        return 0;
      }
    }
  }

  if (dealerLost(current, dealer)) {
    return true;
  }

  return player.score > dealer.score ? true : false;
}

int main() {
  if (play())
    std::cout << "You win! \n";
  else
    std::cout << "You lose!\n";

  return 0;
}
