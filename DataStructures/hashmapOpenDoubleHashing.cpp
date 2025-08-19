#ifndef LIST2_H
#define LIST2_H

/*--- Open Addressing Hashmap Implementation  ---*/

#include <iostream>
#include <utility>
#include <vector>

/*----------------------------------------------------------------------------*/

/*----- HashMap Class -----*/

template <typename K, typename V>
class HashMap {
 public:
  /*--- State Representer Enum ---*/
  enum state { filled, empty, erased };
  /*--- Element Class ---*/
  struct Node {
    std::pair<K, V> pair;
    state nodeState{state::empty};
    Node() : nodeState{state::empty} {}
  };

  /*--- Iterator Class ---*/
  class Iterator {
    using t_data = std::vector<Node>;
    using t_vectorIterator = typename std::vector<Node>::iterator;
    t_data& mm_map;
    typename std::vector<Node>::iterator mm_currentIterator;
    void forwardWhenEmpty();

   public:
    Iterator(t_data&);
    Iterator(t_data&, t_vectorIterator start);
    bool operator!=(const Iterator&) const;
    Iterator& operator++();
    Node& operator*();
  };

  /*--- HashMap Functions ---*/

  // basic constructor, sets size to 1
  HashMap() : m_filledBuckets{0}, m_totalBuckets{1} { m_database.resize(1); }
  // sized constructor, sets map size to given argument
  explicit HashMap(size_t size);
  // updates value at a specific key, throws an exception if map is empty,
  // returns false if key is not found, true if update success
  bool updateValue(const K&, const V&);
  // insert a key value pair into the hashmap
  bool insert(const K&, const V&);
  // erases a key value pair from the hashmap
  bool remove(const K&);
  // returns the value at a specific key
  const V& ValueAt(const K&);
  // returns the load factor of the current Map state
  double getLoadFactor() const;
  // prints the entire map in a graceful format
  void print();

  /*--- Iterator Functions ---*/
  Iterator begin() { return {m_database}; }
  Iterator end() { return Iterator{m_database, m_database.end()}; }

 private:
  /*--- Map Data ---*/
  static constexpr size_t m_hash_shifting{0x9e3779b9};  // 0x9e3779b9 is derived
                                                        // from the Golden Ratio
  static constexpr double m_breakpointLoadFactor{0.75};
  std::vector<Node> m_database;
  size_t m_filledBuckets;
  size_t m_totalBuckets;

  /*--- Insider Functions ---*/
  // resizes the map by doubling the size and reinserting Nodes
  void resizeMap();
  // basic hash function
  size_t calculateHashOne(const K&) const;
  size_t calculateHashOne(const K&, size_t maxSize) const;
  // backup hash function, takes an offset to be considered in calculations
  size_t calculateHashTwo(const K&, size_t offset) const;
  size_t calculateHashTwo(const K&, size_t offset, size_t maxSize) const;
};

/*----- HashMap Class End -----*/

/*----------------------------------------------------------------------------*/

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
typename HashMap<K, V>::Iterator& HashMap<K, V>::Iterator::operator++() {
  if (mm_currentIterator == mm_map.end())
    throw std::runtime_error("EXCEPTION: CANNOT MOVE FORWARD END ITERATOR");
  ++mm_currentIterator;
  forwardWhenEmpty();
  return *this;
}

template <typename K, typename V>
typename HashMap<K, V>::Node& HashMap<K, V>::Iterator::operator*() {
  if (mm_currentIterator == mm_map.end() ||
      mm_currentIterator->nodeState != state::filled)
    throw std::runtime_error("EXCEPTION: CANNOT DEREFERENCE INVALID ITERATOR.");

  return *mm_currentIterator;
}

/*---- ITERATOR FUNCTIONS END -----*/

/*----------------------------------------------------------------------------*/

/*----- HashMap Functions -----*/

template <typename K, typename V>
void HashMap<K, V>::resizeMap() {
  size_t newSize = m_totalBuckets * 2;

  std::vector<Node> newData(newSize);

  for (const auto& i : m_database) {
    const K& key = i.pair.first;
    if (i.nodeState != filled) continue;
    size_t index = calculateHashOne(key, newSize);
    size_t offset{0};
    while (newData[index].nodeState == state::filled) {
      index = calculateHashTwo(key, ++offset, newSize);
    }
    newData[index].pair = {i.pair.first, i.pair.second};
    newData[index].nodeState = state::filled;
  }
  m_database = std::move(newData);
  m_totalBuckets = newSize;
}

template <typename K, typename V>
size_t HashMap<K, V>::calculateHashOne(const K& key) const {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: CANNOT CALCULATE HASH OF EMPTY MAP");
  return std::hash<K>{}(key) % m_totalBuckets;
};

template <typename K, typename V>
size_t HashMap<K, V>::calculateHashOne(const K& key, size_t maxSize) const {
  if (!maxSize)
    throw std::runtime_error("EXCEPTION: CANNOT CALCULATE HASH OF EMPTY MAP");
  return std::hash<K>{}(key) % maxSize;
};

template <typename K, typename V>
size_t HashMap<K, V>::calculateHashTwo(const K& key, size_t offset) const {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: CANNOT CALCULATE HASH OF EMPTY MAP");
  return (std::hash<K>{}(key ^ m_hash_shifting) + offset) % m_totalBuckets;
}

template <typename K, typename V>
size_t HashMap<K, V>::calculateHashTwo(const K& key, size_t offset,
                                       size_t maxSize) const {
  if (!maxSize)
    throw std::runtime_error("EXCEPTION: CANNOT CALCULATE HASH OF EMPTY MAP");
  return (std::hash<K>{}(key ^ m_hash_shifting) + offset) % maxSize;
}

template <typename K, typename V>
HashMap<K, V>::HashMap(size_t size) : m_filledBuckets{0}, m_totalBuckets{size} {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: HASHMAP CANNOT BE OF SIZE ZERO.");
  m_database.resize(m_totalBuckets);
}

template <typename K, typename V>
bool HashMap<K, V>::updateValue(const K& key, const V& value) {
  if (!m_totalBuckets)
    throw std::runtime_error("EXCEPTION: CANNOT UPDATE VALUE IN EMPTY MAP.");

  size_t index{calculateHashOne(key)};

  if (m_database[index].nodeState != state::filled ||
      m_database[index].pair.first != key)
    return false;

  m_database[index].pair.second = value;
  return true;
}

template <typename K, typename V>
bool HashMap<K, V>::insert(const K& key, const V& value) {
  size_t index = calculateHashOne(key);

  if (getLoadFactor() > m_breakpointLoadFactor) {
    resizeMap();
    index = calculateHashOne(key);
  }

  size_t offset{0};
  while (m_database[index].nodeState == state::filled &&
         m_database[index].pair.first != key) {
    index = calculateHashTwo(key, ++offset);
  }

  if (m_database[index].pair.first == key) {
    return false;
  }

  m_database[index].nodeState = state::filled;
  m_database[index].pair = {key, value};
  m_filledBuckets++;
  return true;
}

template <typename K, typename V>
bool HashMap<K, V>::remove(const K& key){
  for(auto& i : *this){
    if(i.pair.first == key){
      i.nodeState = state::erased;
      i.pair = {};
      return true;
    }
  }
  return false;
}

template <typename K, typename V>
const V& HashMap<K, V>::ValueAt(const K& key) {
  for (const auto& i : *this){
    if(i.pair.first == key) return i.pair.second;
  }
  throw std::runtime_error("EXCEPTION: KEY NOT FOUND.");
}

template <typename K, typename V>
double HashMap<K, V>::getLoadFactor() const {
  double size = (double)m_database.size();
  if (!size) return 0;
  return (double)m_filledBuckets / size;
}

template <typename K, typename V>
void HashMap<K, V>::print() {
  for (auto i : *this) {
    std::cout << i.pair.first << " -> " << i.pair.second << '\n';
  }
}

/*----- HashMap Functions End -----*/

#endif  // LIST2_H
