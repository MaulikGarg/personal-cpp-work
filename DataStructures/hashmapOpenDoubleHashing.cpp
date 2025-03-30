/*--- Open Addressing Hashmap Implementation  ---*/

#include <iostream>
#include <utility>
#include <vector>

template <typename K, typename V>
class HashMap {
 public:
  /*--- Iterator Class ---*/
  class Iterator {
    using t_data = std::vector<Node>;
    using t_vectorIterator = std::vector<Node>::iterator;
    t_data& mm_map;
    std::vector<Node>::iterator mm_currentIterator;
    void forwardWhenEmpty();

   public:
    Iterator(t_data&);
    Iterator(t_data&, t_vectorIterator start);
    bool operator!=(const Iterator&) const;
    Iterator& operator++();
    std::pair<K, V>& operator*();
  };

  /*--- HashMap Functions ---*/
  HashMap();
  explicit HashMap(int size);
  ~HashMap();
  bool insert(const K&, const V&);
  bool remove(const K&);
  bool updateValue(const K&, const V&);
  const V& ValueAt(const K&) const;
  double getLoadFactor() const;

  /*--- Iterator Functions ---*/
  Iterator begin() { return {m_database}; }
  Iterator end() {
    return Iterator { m_database, m_database.end(); }
  }

 private:
  /*--- State Representer Enum ---*/
  enum state { filled, empty, erased };

  /*--- Element Class ---*/
  struct Node {
    std::pair<K, V> pair;
    state nodeState{state::empty};
  };
  /*--- Map Data ---*/
  static const double m_breakpointLoadFactor{0.75};
  std::vector<Node> m_database;
  size_t m_filledBuckets;
  size_t m_totalBuckets;

  /*--- Insider Functions ---*/
  size_t calculateHash(const K&) const;
  void resizeMap();
};

/*----- ITERATOR FUNCTIONS -----*/

template <typename K, typename V>
HashMap<K, V>::Iterator::Iterator(t_data& data) : mm_map{data} {
  mm_currentIterator = mm_map.begin();
  forwardWhenEmpty();
}

template <typename K, typename V>
HashMap<K, V>::Iterator::Iterator(t_data& data, t_vectorIterator it)
    : mm_map{data}, mm_currentIterator{it} {
  forwardWhenEmpty();
}

template <typename K, typename V>
void HashMap<K, V>::Iterator::forwardWhenEmpty() {
  while (mm_currentIterator != mm_map.end() &&
         mm_currentIterator->nodeState != state::filled) {
    mm_currentIterator++;
  }
}

template <typename K, typename V>
bool HashMap<K, V>::Iterator::operator!=(const Iterator& other) const {
  return mm_currentIterator != other.mm_currentIterator;
}

template <typename K, typename V>
HashMap<K, V>::Iterator& HashMap<K, V>::Iterator::operator++() {
  if (mm_currentIterator == mm_map.end()) return *this;
  ++mm_currentIterator;
  forwardWhenEmpty();
  return *this;
}

template <typename K, typename V>
std::pair<K, V>& HashMap<K, V>::Iterator::operator*() {
  if (mm_currentIterator == mm_map.end() ||
      mm_currentIterator->nodeState != state::filled)
    throw std::runtime_error("EXCEPTION: CANNOT DEREFERENCE INVALID ITERATOR.");

  return mm_currentIterator->pair;
}

/*---- ITERATOR FUNCTIONS END -----*/
