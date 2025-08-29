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
  int aceCount{};
};

Card drawCard(Deck& current, Player& entity) {
  Card tempCard{current.dealCard()};
  if (tempCard.rank == Card::rank_ace) {
    entity.aceCount++;
  }
  entity.score += tempCard.value();
  return tempCard;
}

bool hasLost(Player& entity, std::string_view character) {
  if (entity.score > settings::maxScore) {
    if (entity.aceCount > 0) {
      entity.score -= 10;
      entity.aceCount--;
      std::cout << character << "  used an ace! " << character << " now have "
                << entity.score << '\n';
      return false;
    }
    std::cout << character << " went bust!\n";
    return true;
  }
  return false;
}

bool dealerLost(Deck& current, Player& dealer) {
  while (dealer.score < settings::dealerMinDraw) {
    Card currentDraw{drawCard(current, dealer)};
    std::cout << "The dealer draws a " << currentDraw << ". They now have "
              << dealer.score << '\n';
    if (hasLost(dealer, "The Dealer")) return true;
  }
  return false;
}

bool playerLost(Deck& current, Player& player) {
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
      return false;
    else {
      Card currentDraw{drawCard(current, player)};
      std::cout << "You were dealt " << currentDraw
                << ".  You now have: " << player.score << '\n';
      if (hasLost(player, "You")) return true;
    }
  }
}

enum outcome {
  win,
  lose,
  draw,
  max,
};

outcome play() {
  Deck current;
  current.shuffle();

  Player dealer;

  std::cout << "The dealer shows: " << drawCard(current, dealer) << " ("
            << dealer.score << ")\n";

  Player player;
  std::cout << "You are showing " << drawCard(current, player) << " "
            << drawCard(current, player) << " (" << player.score
            << ")\n";

      if (playerLost(current, player)) return outcome::lose;
  if (dealerLost(current, dealer)) return outcome::win;

  if (player.score == dealer.score) return outcome::draw;
  return player.score > dealer.score ? outcome::win : outcome::lose;
}

int main() {
  switch (play()) {
    case win:
      std::cout << "You win";
      break;
    case lose:
      std::cout << "You lost";
      break;
    case draw:
      std::cout << "Its a draw!";
      break;
    default:
      std::cout << "Invalid game.";
      break;
  }
  std::cout << '\n';
  return 0;
}
