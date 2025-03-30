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
  HashMap() : m_totalBuckets{1}, m_filledBuckets{0} { m_database.resize(1) };
  explicit HashMap(int size);
  bool updateValue(const K&, const V&);
  bool insert(const K&, const V&);
  bool remove(const K&);
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
    Node() : nodeState{state::empty} {}
  };
  /*--- Map Data ---*/
  static const size_t m_hash_shifting{0x9e3779b9};  // 0x9e3779b9 is derived
                                                    // from the Golden Ratio
  static const double m_breakpointLoadFactor{0.75};
  std::vector<Node> m_database;
  size_t m_filledBuckets;
  size_t m_totalBuckets;

  /*--- Insider Functions ---*/
  void resizeMap();
  size_t calculateHashOne(const K&) const;
  size_t calculateHashTwo(const K&, size_t offset) const;
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
  if (mm_currentIterator == mm_map.end())
    throw std::runtime_error("EXCEPTION: CANNOT MOVE FORWARD END ITERATOR");
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

/*----- HashMap Functions -----*/

template <typename K, typename V>
size_t HashMap<K, V>::calculateHashOne(const K& key) const {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: CANNOT CALCULATE HASH OF EMPTY MAP");
  return std::hash<K>{}(key) % m_totalBuckets;
};

template <typename K, typename V>
size_t HashMap<K, V>::calculateHashTwo(const K& key, size_t offset) const {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: CANNOT CALCULATE HASH OF EMPTY MAP");
  return (std::hash<K>{}(key ^ m_hash_shifting) + offset) % m_totalBuckets;
}

template <typename K, typename V>
HashMap<K, V>::HashMap(int size) : m_totalBuckets{size}, m_filledBuckets{0} {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: HASHMAP CANNOT BE OF SIZE ZERO.");
  m_database.resize(m_totalBuckets);
}

template <typename K, typename V>
bool HashMap<K, V>::updateValue(const K& key, const V& value) {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: CANNOT UPDATE VALUE IN EMPTY MAP.");

  size_t index{calculateHash(key)};

  if (m_database[index].nodeState != state::filled ||
      m_database[index].pair.first != key)
    return false;

  m_database[index].pair.second = value;
  return true;
}

template <typename K, typename V>
bool HashMap<K, V>::insert(const K& key, const V& value) {

  size_t index = calculateHash(key);

  if(getLoadFactor() > m_breakpointLoadFactor){
    resizeMap();
    index = calculateHashOne(key);
  }
  
  size_t offset {0};
  while(m_database[index].nodeState == state::filled && m_database[index].pair.first != key){
    index = calculateHashTwo(key, ++offset);
  }

  if(m_database[index].pair.first == key){
    m_database[index].pair.second = value;
    return true;
  }

  m_database[index].nodeState = state::filled;
  m_database[index].pair = {key, value};
  m_filledBuckets++;
  return true;

}
