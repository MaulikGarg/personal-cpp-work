/*

Doubly Linked List Implementation
By Maulik
Dated: 15 March 2025

*/

#include <iostream>
#include <memory>

template <typename T>
struct NodeElement {
  NodeElement<T>* m_previous{nullptr};
  T m_data;
  NodeElement<T>* m_next{nullptr};

  /*functions*/

  NodeElement(NodeElement<T>* prev, const T& data)
      : m_previous{prev}, m_data{data}, m_next{nullptr} {}

  // delete copy functions to prevent duplication
  NodeElement(const NodeElement<T>&) = delete;
  NodeElement& operator=(const NodeElement<T>&) = delete;
};

template <typename T>
class DoublyLinkedList {
  NodeElement<T>* m_head{nullptr};

 public:
  DoublyLinkedList() = default;
  ~DoublyLinkedList();
  void addElement(T data);
  void printList();
};

template <typename T>
void DoublyLinkedList<T>::addElement(T data) {
  // if first element does not exist
  if (!m_head) {
    m_head = new NodeElement<T>{nullptr, data};
    return;
  }
  // for adding element, traverse the list
  NodeElement<T>* current = m_head;
  while (current->m_next) {
    current = current->m_next;
  }
  // now add the element
  NodeElement<T>* temporary = new NodeElement<T>{current, data};
  current->m_next = temporary;
}

template <typename T>
void DoublyLinkedList<T>::printList() {
  NodeElement<T>* current = m_head;
  while (current) {
    std::cout << current->m_data << " -> ";
    current = current->m_next;
  }
  std::cout << "end.\n";
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  NodeElement<T>* current = m_head;
  while (current) {
    NodeElement<T>* temp{current->m_next};
    delete current;
    current = temp;
  }
}

int main() {
  DoublyLinkedList<int> list;
  list.addElement(1);
  list.addElement(2);
  list.addElement(3);
  list.addElement(4);
  list.printList();

  return 0;
}
