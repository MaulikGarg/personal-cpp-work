/*

   S T A C K
   U S I N G
       A
  S I N G L Y
  L I N K E D
    L I S T

  Author: Maulik Garg

*/

#include <iostream>

template <typename T>
class LinkedList {
  // single element with data and ptr to next
  struct Node {
    T mm_data{};             // the data inside a node
    Node* mm_next{nullptr};  // the pointer to the next node
    Node(const T& data) : mm_data{data}, mm_next{nullptr} {}
    Node(const T& data, Node* ptr) : mm_data{data}, mm_next{ptr} {}
  };

  Node* m_head{nullptr};  // pointer to the first element
  Node* m_tail{nullptr};  // pointer to the last element
  int m_size{};

 public:
  // deleted functions & operators
  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList&) = delete;

  // constructors
  LinkedList() {}
  LinkedList(const T& data) { addFirst(data); }
  LinkedList(LinkedList&& list) noexcept;
  ~LinkedList();

  // iterator class and functions
  class iterator {
    Node* mm_current{nullptr};

   public:
    iterator(Node* ptr) : mm_current{ptr} {}
    // necessary overloads
    bool operator!=(const iterator& other) const {
      return mm_current != other.mm_current;
    }
    iterator& operator++() {
      mm_current = mm_current->mm_next;
      return *this;
    }
    T& operator*() const { return mm_current->mm_data; }
  };

  // iterator specific functions
  iterator begin() const { return iterator{m_head}; }
  iterator end() const { return iterator{nullptr}; }

  // standard functions
  bool isEmpty() const { return !m_size; }
  void addFirst(const T& data);  // add data to the start of the list
  void addLast(const T& data);   // add data to the end of the list
  void addAtIndex(const T& data, int index);  // add data at a specific index
  void removeAtIndex(int index);     // remove data from a specific index
  void removeValue(const T& value);  // remove all occurences of a value

  // overloads
  LinkedList& operator=(LinkedList&&) noexcept;
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);

  // getters
  int getSize() const { return m_size; }
  const T& getFirst() const {
    if (m_head)
      return m_head->mm_data;
    else
      throw std::runtime_error(
          "Exception in getFirst(): Cannot get element from empty list.\n");
  }
  const T& getLast() const {
    if (m_head)
      return m_tail->mm_data;
    else
      throw std::runtime_error(
          "Exception in getLast(): Cannot get element from empty list.\n");
  }
};

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& list) noexcept
    : m_head{list.m_head}, m_tail{list.m_tail}, m_size{list.m_size} {
  list.m_head = list.m_tail = nullptr;
  list.m_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  while (m_head) {
    Node* temp = m_head;
    m_head = m_head->mm_next;
    delete temp;
  }
}

template <typename T>
void LinkedList<T>::addFirst(const T& data) {
  Node* newNode = new Node{data};

  if (!m_head)  // empty list case
    m_head = m_tail = newNode;
  else {
    newNode->mm_next = m_head;
    m_head = newNode;
  }

  m_size++;
}

template <typename T>
void LinkedList<T>::addLast(const T& data) {
  Node* newNode = new Node{data};

  if (!m_head)  // empty list case
    m_head = m_tail = newNode;
  else {
    m_tail->mm_next = newNode;
    m_tail = newNode;
  }

  m_size++;
}

template <typename T>
void LinkedList<T>::addAtIndex(const T& data, int index) {
  if (index < 0 || index > m_size)
    throw std::runtime_error("Exception in addAtIndex(): Invalid Index\n");

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

  Node* newNode = new Node{data};
  Node* current{m_head};
  // current should stop 1 before index
  for (int i = 0; i < index - 1; i++) {
    current = current->mm_next;
  }

  newNode->mm_next = current->mm_next;
  current->mm_next = newNode;
  m_size++;
}

template <typename T>
void LinkedList<T>::removeAtIndex(int index) {
  if (!m_head) return;  // empty list case

  // size is always => 0, we cant delete non existing Node
  if (index < 0 || index >= m_size)
    throw std::runtime_error("Exception in removeAtIndex(): Invalid Index\n");

  if (index == 0) {
    Node* temp{m_head};
    m_head = m_head->mm_next;
    delete temp;
    if (!m_head) m_tail = nullptr;  // if the list is now empty
    m_size--;
    return;
  }

  // prev reaches the node behind the to be deleted one
  Node* prev{m_head};  // pointer to node behind current index
  for (int i = 0; i < index - 1; i++) {
    prev = prev->mm_next;
  }
  Node* temp{prev->mm_next};
  prev->mm_next = temp->mm_next;
  delete temp;
  // if prev has become that tail
  if (!prev->mm_next) m_tail = prev;

  m_size--;
}

template <typename T>
void LinkedList<T>::removeValue(const T& value) {
  if (!m_head) return;  // empty list case

  // dummy node at index = -1
  Node* dummy = new Node{T{}, m_head};
  Node* current = dummy;  // the traversal pointer

  while (current->mm_next) {
    if (current->mm_next->mm_data == value) {
      Node* temp = current->mm_next;
      current->mm_next = temp->mm_next;
      // if we are deleting the last element
      if (temp == m_tail) m_tail = current;
      delete temp;
      m_size--;
    } else {
      current = current->mm_next;
    }
  }

  m_head = dummy->mm_next;
  if (!m_head) m_tail = nullptr;
  delete dummy;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other) noexcept {
  // self assignment prevention
  if (this == &other) return *this;
  std::swap(m_head, other.m_head);
  std::swap(m_size, other.m_size);
  std::swap(m_tail, other.m_tail);
  return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
  if (!list.m_head) return os;

  // // non iterator approach
  // typename LinkedList<T>::Node* current{list.m_head};
  // while (current) {
  //   os << current->mm_data << " -> ";
  //   current = current->mm_next;
  // }

  for (auto i : list) {
    os << i << " -> ";
  }

  os << "end!\n";
  return os;
}

template <typename T>
class Stack {
  LinkedList<T> m_list;

 public:
  Stack() {}
  Stack(const T& data) : m_list{data} {}

  void push(const T& data) { m_list.addFirst(data); }

  T pop() {
    if (m_list.isEmpty())
      throw std::runtime_error{
          "Exception in pop(): cannot pop from an empty stack.\n"};
    T temp = m_list.getFirst();
    m_list.removeAtIndex(0);
    return temp;
  }

  T peek() {
    if (m_list.isEmpty())
      throw std::runtime_error{
          "Exception in peek(): cannot peek from an empty stack.\n"};
    return m_list.getFirst();
  }

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Stack<U>& stack) {
    if (stack.m_list.isEmpty()) return os;
    for (auto& i : stack.m_list) {
      os << i << " <- ";
    }
    os << "bottom.\n";
    return os;
  }
};
