#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "../libraries/random.h"

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
};

class Deck {
  std::array<Card, 52> m_deck{};
  size_t m_nextCard{};

 public:
  Deck() {
    size_t current{};
    for (auto& i : Card::s_allSuits) {
      for (auto& j : Card::s_allRanks) {
        m_deck[current++] = Card{j,i};
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

int main() {
  Deck deck{};
  std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' '
            << deck.dealCard() << '\n';

  deck.shuffle();
  std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' '
            << deck.dealCard() << '\n';

  return 0;
}
