#include <iostream>

template <typename T>
struct Node {
  T m_data{};
  Node<T>* m_next{nullptr};
  Node(const T& data) : m_data{data}, m_next{nullptr} {}
  Node(const T& data, Node<T>* ptr) : m_data{data}, m_next{ptr} {}
};

template <typename T>
class LinkedList {
  Node<T>* m_head{nullptr};
  Node<T>* m_tail{nullptr};
  int m_size{};

 public:
  LinkedList() {}
  ~LinkedList();
  void addFirst(const T& data);
  void addLast(const T& data);
  void addAtIndex(const T& data, int index);
  void removeAtIndex(int index);
  void removeValue(const T& value);

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);
};

template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T>* traverse{m_head};
  while (traverse) {
    Node<T>* temp = traverse;
    traverse = traverse->m_next;
    delete temp;
  }
}

template <typename T>
void LinkedList<T>::addFirst(const T& data) {
  Node<T>* newNode = new Node{data};

  if (!m_head)
    m_head = m_tail = newNode;
  else {
    newNode->m_next = m_head;
    m_head = newNode;
  }

  m_size++;
}

template <typename T>
void LinkedList<T>::addLast(const T& data) {
  Node<T>* newNode = new Node{data};

  if (!m_head)
    m_head = m_tail = newNode;
  else {
    m_tail->m_next = newNode;
    m_tail = newNode;
  }

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
  if (index == m_size) {
    addLast(data);
    return;
  }

  Node<T>* newNode = new Node{data};
  Node<T>* current{m_head};
  // current should stop 1 before index
  for (int i = 0; i < index - 1; i++) {
    current = current->m_next;
  }

  newNode->m_next = current->m_next;
  current->m_next = newNode;
  m_size++;
}

template <typename T>
void LinkedList<T>::removeAtIndex(int index) {
  if (!m_head) return;

  // size is always => 0, we cant delete non existing Node
  if (index < 0 || index >= m_size)
    throw std::runtime_error("Invalid Index in removeAtIndex()");

  if (index == 0) {
    Node<T>* temp{m_head};
    m_head = m_head->m_next;
    delete temp;
    if (!m_head) m_tail = nullptr;
    m_size--;
    return;
  }

  // prev reaches the node behind the to be deleted one
  Node<T>* prev{m_head};
  for (int i = 0; i < index - 1; i++) {
    prev = prev->m_next;
  }
  Node<T>* temp{prev->m_next};
  prev->m_next = temp->m_next;
  delete temp;
  // if prev has become that tail
  if (!prev->m_next) m_tail = prev;

  m_size--;
}

template <typename T>
void LinkedList<T>::removeValue(const T& value) {
  if (!m_head) return;

  Node<T>* dummy = new Node<T>{T{}, m_head};
  Node<T>* current = dummy;

  while (current->m_next) {
    if (current->m_next->m_data == value) {
      Node<T>* temp = current->m_next;
      current->m_next = temp->m_next;
      if (temp == m_tail) m_tail = current;
      delete temp;
      m_size--;
    } else {
      current = current->m_next;
    }
  }

  m_head = dummy->m_next;
  delete dummy;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
  Node<T>* current{list.m_head};
  while (current) {
    os << current->m_data << " -> ";
    current = current->m_next;
  }
  os << "end!\n";
  return os;
}

int main() {
  LinkedList<int> list;
  try {
    list.addFirst(1);
    list.addFirst(2);
    list.addLast(3);
    std::cout << list;
    list.addAtIndex(4, 2);
    std::cout << list;
    list.addAtIndex(5, 1);
    list.addAtIndex(6, 2);
  } catch (const std::runtime_error& exception) {
    std::cout << exception.what() << '\n';
  }
  std::cout << list;
}
