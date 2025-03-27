/*

  S E P E R A T E
  C H A I N I N G
   H A S H M A P

  Author: Maulik Garg
  Dated: 26 March 2025

*/

#include <iostream>
#include <list>
#include <string>
#include <cassert>

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
  int m_bucketsFilled{};
  // pointer to a list of keyval pairs
  std::list<KeyValuePair>* m_buckets;

  // hash functions
  size_t calculateHash(const K& key, int buckets = 0);

  // resizes the hashmap incase of high load factor
  bool resize();

 public:
  // constructors/destructors
  HashMap(int);
  ~HashMap() { delete[] m_buckets; }
  // inserting element, returns true on success
  bool insert(K key, V val);

  // getters
  float getLoadFactor() {
    return static_cast<float>(m_bucketsFilled) / static_cast<float>(m_bucketCount);
  }
  void printMap();
};

template <typename K, typename V>
HashMap<K, V>::HashMap(int i) {
  m_bucketCount = i;
  m_buckets = new std::list<KeyValuePair>[m_bucketCount];
}

template <typename K, typename V>
size_t HashMap<K, V>::calculateHash(const K& key, int buckets) {
  if(!buckets) buckets = m_bucketCount;
  return std::hash<K>{}(key) % buckets;
}

template <typename K, typename V>
bool HashMap<K, V>::insert(K key, V val) {
  // resize if average list width is too much
  if (getLoadFactor() > m_resizeLoad) {
    resize();
  }

  auto& bucket = m_buckets[calculateHash(key)];
  bucket.push_back(KeyValuePair{key, val});
  m_bucketsFilled++;
  return true;
}

template <typename K, typename V>
bool HashMap<K, V>::resize() {
  int newBucketCount = m_bucketCount * 2;
  auto* newBuckets = new std::list<KeyValuePair>[newBucketCount];

  for (int i = 0; i < m_bucketCount; i++) {
    auto& bucket = m_buckets[i];
    for (auto& pair : bucket) {
      size_t newHash = calculateHash(pair.mm_key, newBucketCount);
      newBuckets[newHash].push_back(pair);
    }
  }

  delete[] m_buckets;
  m_buckets = newBuckets;
  m_bucketCount = newBucketCount;

  return true;
}

template <typename K, typename V>
void HashMap<K, V>::printMap(){
  std::cout << "-------------------------\n";
  for (int i = 0; i < m_bucketCount; i++) {
    auto& bucket = m_buckets[i];
    for (auto& pair : bucket) {
      std::cout << "{ " << pair.mm_key << " : " << pair.mm_val << " }\n";
    }
  }
  std::cout << "-------------------------\n";
}
