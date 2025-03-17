#include <iostream>

template <typename T>
struct Node {
  T m_data{};
  Node<T>* m_next{nullptr};
  Node(const T& data) : m_data{data}, m_next{nullptr} {}
};

template <typename T>
class LinkedList {
  Node<T>* m_head{nullptr};
  Node<T>* m_tail{nullptr};
  int m_size{};

 public:
  LinkedList() {}
  void addFirst(const T& data);
  void addLast(const T& data);
  void addAtIndex(const T& data, int index);
  friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    Node<T>* current{list.m_head};
    while (current) {
      os << current->m_data << " -> ";
      current = current->m_next;
    }
    os << "end!\n";
    return os;
  }
};

template <typename T>
void LinkedList<T>::addFirst(const T& data) {
  Node<T>* newNode = new Node{data};

  if (!m_head) m_tail = newNode;

  newNode->m_next = m_head;
  m_head = newNode;

  m_size++;
}

template <typename T>
void LinkedList<T>::addLast(const T& data) {
  Node<T>* newNode = new Node{data};

  if (!m_head) m_tail = newNode;

  m_tail->m_next = newNode;
  m_tail = newNode;

  m_size++;
}

template <typename T>
void LinkedList<T>::addAtIndex(const T& data, int index) {
  if (index < 0 || index > m_size)
    throw std::runtime_error("Invalid Index in addAtIndex()");

  // if we are adding at the start
  if (!index) {
    addFirst(data);
    return;
  }
  // if we are adding at the last
  if (index == m_size - 1) {
    addLast(data);
    return;
  }

  Node<T>* newNode = new Node{data};
  Node<T>* current = {m_head};
  while (--index) {
    current = current->m_next;
  }
  newNode->m_next = current->m_next;
  current->m_next = newNode;
  m_size++;
}

int main() {
  LinkedList<int> list;
  try {
    list.addFirst(1);
    list.addFirst(2);
    list.addLast(3);
    std::cout << list;
    list.addAtIndex(4, 2);
    list.addAtIndex(5, -1);
    list.addAtIndex(6, 2);
  } 
  catch (const std::runtime_error& exception) {
    std::cout << exception.what() << '\n';
  }
  std::cout << list;
}
