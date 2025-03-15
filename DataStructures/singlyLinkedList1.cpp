/*

Singly Linked List Implementation
By Maulik
Dated: 15 March 2025

*/


#include <iostream>
#include <memory>

template <typename T>
struct NodeElement {
  T m_data;
  std::unique_ptr<NodeElement> m_next;

  /*-----------funcs below-------------*/

  explicit NodeElement(const T& data) : m_data{data}, m_next{nullptr} {}
  NodeElement(const T& data, std::unique_ptr<NodeElement<T>>&& ptr)
      : m_data{data}, m_next{std::move(ptr)} {}

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
    std::cout << current->m_data;
    if (current->m_next) std::cout << " -> ";
    current = current->m_next.get();
  }
  std::cout << '\n';
}

int main() {
  LinkedList<int> list;
  list.addElement(2);
  list.addElement(5);
  list.addElement(7);
  list.addElement(9);
  list.printList();
  return 0;
}
