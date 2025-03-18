#include <iostream>

template <typename T>
class LinkedList {

  struct Node {
    T m_data{};                // the data inside a node
    Node* m_next{nullptr};  // the pointer to the next node
    Node(const T& data) : m_data{data}, m_next{nullptr} {}
    Node(const T& data, Node* ptr) : m_data{data}, m_next{ptr} {}
  };

  Node* m_head{nullptr};  // pointer to the first element
  Node* m_tail{nullptr};  // pointer to the last element
  int m_size{};

 public:
  // constructors
  LinkedList() {}
  ~LinkedList();

  // standard functions
  void addFirst(const T& data);  // add data to the start of the list
  void addLast(const T& data);   // add data to the end of the list
  void addAtIndex(const T& data, int index);  // add data at a specific index
  void removeAtIndex(int index);     // remove data from a specific index
  void removeValue(const T& value);  // remove all occurences of a value

  // overloads
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);

  // getters
  int getSize() const { return m_size; }
  const T& getFirst() const {
    if (m_head) return m_head->m_data;
    else throw std::runtime_error("Exception in getFirst(): Cannot get element from empty list.\n");
  }
  const T& getLast() const {
    if (m_head) return m_tail->m_data;
    else throw std::runtime_error("Exception in getLast(): Cannot get element from empty list.\n");
  }

};

template <typename T>
LinkedList<T>::~LinkedList() {
  Node* traverse{m_head};
  while (traverse) {
    Node* temp = traverse;
    traverse = traverse->m_next;
    delete temp;
  }
}

template <typename T>
void LinkedList<T>::addFirst(const T& data) {
  Node* newNode = new Node{data};

  if (!m_head)  // empty list case
    m_head = m_tail = newNode;
  else {
    newNode->m_next = m_head;
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
    m_tail->m_next = newNode;
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
    current = current->m_next;
  }

  newNode->m_next = current->m_next;
  current->m_next = newNode;
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
    m_head = m_head->m_next;
    delete temp;
    if (!m_head) m_tail = nullptr;  // if the list is now empty
    m_size--;
    return;
  }

  // prev reaches the node behind the to be deleted one
  Node* prev{m_head};  // pointer to node behind current index
  for (int i = 0; i < index - 1; i++) {
    prev = prev->m_next;
  }
  Node* temp{prev->m_next};
  prev->m_next = temp->m_next;
  delete temp;
  // if prev has become that tail
  if (!prev->m_next) m_tail = prev;

  m_size--;
}

template <typename T>
void LinkedList<T>::removeValue(const T& value) {
  if (!m_head) return;  // empty list case

  // dummy node at index = -1
  Node* dummy = new Node{T{}, m_head};
  Node* current = dummy;  // the traversal pointer

  while (current->m_next) {
    if (current->m_next->m_data == value) {
      Node* temp = current->m_next;
      current->m_next = temp->m_next;
      // if we are deleting the last element
      if (temp == m_tail) m_tail = current;
      delete temp;
      m_size--;
    } else {
      current = current->m_next;
    }
  }
  
  m_head = dummy->m_next;
  if(!m_head) m_tail = nullptr;
  delete dummy;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
  if(!list.m_head) return os;
  typename LinkedList<T>::Node* current{list.m_head};
  while (current) {
    os << current->m_data << " -> ";
    current = current->m_next;
  }
  os << "end!\n";
  return os;
}
