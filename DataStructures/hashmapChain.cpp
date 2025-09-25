/*

  S E P E R A T E
  C H A I N I N G
   H A S H M A P

  Maulik Garg
  Dated: 26 March 2025

*/

#include <cassert>
#include <iostream>
#include <list>
#include <string>

template <typename K, typename V>
class HashMap {
  // key val struct inside the hashmap
  struct KeyValuePair {
    K mm_key;
    V mm_val;
    KeyValuePair(K key, V val) : mm_key{key}, mm_val{val} {}
  };
  // load factor at which the map should resize
  const float m_resizeLoad{2.00f};
  // the total number of buckets
  int m_bucketCount;
  // the number of buckets filled
  int m_elementCount{};
  // pointer to a list of keyval pairs
  std::list<KeyValuePair>* m_buckets;
  // hash getter
  size_t calculateHash(const K& key, int buckets = 0) const;
  // resizes the hashmap incase of high load factor
  bool resize();

 public:
  // iterators
  class iterator {
    // array of lists
    std::list<KeyValuePair>* mm_buckets;
    // current index in the array
    size_t mm_index{};
    // number of buckets
    size_t mm_bucketCount{};
    // current bucket iterator
    std::list<KeyValuePair>::iterator mm_it;

   public:
    iterator(std::list<KeyValuePair>* bucketptr, size_t index, size_t bucketCount);
    bool operator!=(const iterator& operand) const;
    iterator& operator++();
    KeyValuePair& operator*() const;
  };

  // iterator specific functions
  iterator begin() const { return {m_buckets, 0, static_cast<size_t>(m_bucketCount)}; }
  iterator end() const {
    return {m_buckets, static_cast<size_t>(m_bucketCount) , static_cast<size_t>(m_bucketCount)};
  }
  // constructors/destructors
  HashMap(int);
  ~HashMap() { delete[] m_buckets; }

  // funcs
  bool insert(const K& key, const V& val);
  void printMap() const;
  V& find(const K& key) const;
  bool change(const K& key, const V& val);
  // getters
  double getLoadFactor() const {
    if(!m_bucketCount) return 0;
    return (m_elementCount) / static_cast<double>(m_bucketCount);
  }
};

/*-------------------------------------------------*/

template <typename K, typename V>
HashMap<K, V>::iterator::iterator(std::list<KeyValuePair>* bucketptr,
                                  size_t index, size_t bucketCount)
    : mm_buckets{bucketptr}, mm_index{index}, mm_bucketCount{bucketCount} {
  if (mm_index == mm_bucketCount){
    mm_it = mm_buckets[mm_bucketCount].end();
    return;
  }
  while (mm_index != mm_bucketCount && mm_buckets[mm_index].empty()) {
      ++mm_index;
    }
  if (mm_index < mm_bucketCount) {
    mm_it = mm_buckets[mm_index].begin();
  }
}

template <typename K, typename V>
bool HashMap<K, V>::iterator::operator!=(const iterator& operand) const {
  return mm_index != operand.mm_index || mm_buckets != operand.mm_buckets ||
         mm_it != operand.mm_it;
}

template <typename K, typename V>
HashMap<K, V>::KeyValuePair& HashMap<K, V>::iterator::operator*()const {
  return *mm_it;
}

template <typename K, typename V>
typename HashMap<K, V>::iterator& HashMap<K, V>::iterator::operator++() {
  if (++mm_it != mm_buckets[mm_index].end()) return *this;
  while (mm_it == mm_buckets[mm_index].end() && mm_index + 1 < mm_bucketCount) {
    mm_index++;
    mm_it = mm_buckets[mm_index].begin();
  }
  // if it has reached the end
  if(mm_it == mm_buckets[mm_index].end() && mm_index + 1 == mm_bucketCount){
    mm_index++;
    mm_it = mm_buckets[mm_bucketCount].end();
  }
  return *this;
}

/*-------------------------------------------------*/

template <typename K, typename V>
HashMap<K, V>::HashMap(int i) {
  m_bucketCount = i;
  m_buckets = new std::list<KeyValuePair>[m_bucketCount];
}

template <typename K, typename V>
size_t HashMap<K, V>::calculateHash(const K& key, int buckets) const {
  if (!buckets) buckets = m_bucketCount;
  return std::hash<K>{}(key) % buckets;
}

template <typename K, typename V>
bool HashMap<K, V>::insert(const K& key, const V& val) {
  // check if Key already exist and change
  if (change(key, val)) return true;

  // resize if average list width is too much
  if (getLoadFactor() >= m_resizeLoad) {
    resize();
  }

  auto& bucket = m_buckets[calculateHash(key)];
  bucket.emplace_back(KeyValuePair{key, val});
  m_elementCount++;
  return true;
}

template <typename K, typename V>
bool HashMap<K, V>::resize() {
  int newBucketCount = m_bucketCount * 2;
  auto* newBuckets = new std::list<KeyValuePair>[newBucketCount];

  for (auto& pair : *this) {
    size_t newHash = calculateHash(pair.mm_key, newBucketCount);
    newBuckets[newHash].emplace_back(pair);
  }

  delete[] m_buckets;
  m_buckets = newBuckets;
  m_bucketCount = newBucketCount;

  return true;
}

template <typename K, typename V>
V& HashMap<K, V>::find(const K& key) const {
  auto& bucket = m_buckets[calculateHash(key)];
  for (auto& pair : bucket) {
    if (pair.mm_key == key) return pair.mm_val;
  }

  throw std::runtime_error("Key not found");
}

template <typename K, typename V>
bool HashMap<K, V>::change(const K& key, const V& val) {
  auto& bucket = m_buckets[calculateHash(key)];
  for (auto& pair : bucket) {
    if (pair.mm_key == key) {
      pair.mm_val = val;
      return true;
    }
  }
  return false;
}

template <typename K, typename V>
void HashMap<K, V>::printMap() const {
  std::cout << "-------------------------\n";
  for (int i = 0; i < m_bucketCount; i++) {
    auto& bucket = m_buckets[i];
    for (auto& pair : bucket) {
      std::cout << "{ " << pair.mm_key << " : " << pair.mm_val << " }\n";
    }
  }
  std::cout << "-------------------------\n";
}
