/*

Singly Linked List Implementation
By Maulik
Dated: 15 March 2025

*/

#include <iostream>
#include <memory>
#define USING_UNIQUE_POINTER

#ifdef USING_UNIQUE_POINTER

template <typename T>
struct NodeElement {
  T m_data;
  std::unique_ptr<NodeElement> m_next;

  /*-----------funcs below-------------*/

  explicit NodeElement(const T& data) : m_data{data}, m_next{nullptr} {}

  // delete these as we are using unique ptr
  NodeElement(const NodeElement&) = delete;
  NodeElement& operator=(const NodeElement&) = delete;
};

template <typename T>
class LinkedList {
  std::unique_ptr<NodeElement<T>> head;

 public:
  LinkedList() = default;
  void addElement(const T& element);
  void printList() const;
  void reverse();
};

template <typename T>
void LinkedList<T>::addElement(const T& element) {
  // check if the list is empty
  if (!head) {
    head = std::make_unique<NodeElement<T>>(element);
    return;
  }
  // traverse the list otherwise
  NodeElement<T>* current{head.get()};  // pointer for traversal
  while (current->m_next) {
    current = current->m_next.get();
  }
  current->m_next = std::make_unique<NodeElement<T>>(element);
}

template <typename T>
void LinkedList<T>::printList() const {
  NodeElement<T>* current{head.get()};
  while (current) {
    std::cout << current->m_data << " -> ";
    current = current->m_next.get();
  }
  std::cout << "null\n";
}

template <typename T>
void LinkedList<T>::reverse() {
  std::unique_ptr<NodeElement<T>> prev{nullptr};
  std::unique_ptr<NodeElement<T>> current = std::move(head);
  std::unique_ptr<NodeElement<T>> next{nullptr};

  while (current) {
    next = std::move(current->m_next);
    current->m_next = std::move(prev);
    prev = std::move(current);
    current = std::move(next);
  }
  head = std::move(prev);
}



#else

template <typename T>
struct NodeElement {
  T m_data;
  NodeElement* m_next{nullptr};

  /*-----funcs below--------*/

  explicit NodeElement(const T& element) : m_data{element}, m_next{nullptr} {}

  // delete these as we want unique ptr like behaviour
  NodeElement(const NodeElement&) = delete;
  NodeElement& operator=(const NodeElement&) = delete;
};

template <typename T>
class LinkedList {
  NodeElement<T>* m_head{nullptr};

 public:
  LinkedList() = default;
  ~LinkedList();
  void addElement(const T& element);
  void printList() const;
  void reverse();
};

template <typename T>
LinkedList<T>::~LinkedList() {
  NodeElement<T>* current{m_head};
  while (current) {
    NodeElement<T>* temporary = current;
    current = current->m_next;
    delete temporary;
  }
}

template <typename T>
void LinkedList<T>::addElement(const T& element) {
  // if we have an empty list
  if (!m_head) {
    m_head = new NodeElement<T>{element};
    return;
  }
  // otherwise we traverse
  NodeElement<T>* current{m_head};
  while (current->m_next) {
    current = current->m_next;
  }
  current->m_next = new NodeElement<T>{element};
}

template <typename T>
void LinkedList<T>::printList() const {
  NodeElement<T>* current{m_head};
  while (current) {
    std::cout << current->m_data << " -> ";
    current = current->m_next;
  }
  std::cout << "null\n";
}

template <typename T>
void LinkedList<T>::reverse() {
  if (!m_head) return;
  NodeElement<T>* prev{nullptr};
  NodeElement<T>* current{m_head};
  NodeElement<T>* next{nullptr};
  while (current) {
    next = current->m_next;
    current->m_next = prev;
    prev = current;
    current = next;
  }
  m_head = prev;
}

#endif

int main() {
  LinkedList<int> list;
  list.addElement(2);
  list.addElement(5);
  list.addElement(7);
  list.addElement(9);
  list.printList();
  list.reverse();
  list.printList();
  return 0;
}
