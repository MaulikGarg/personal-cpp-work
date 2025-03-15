/*

Doubly Linked List Implementation
By Maulik
Dated: 15 March 2025

*/

#include <iostream>
#include <memory>
#include <vector>

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
  void deleteAtIndex(int index);
  void deleteByValue(const T& value);
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

template <typename T>
void DoublyLinkedList<T>::deleteAtIndex(int index) {
  if(!m_head) return;
  if (index < 0)
    throw std::runtime_error("Negative index deletion is not allowed.\n");
  NodeElement<T>* current{m_head};
  while (index--) {
    current = current->m_next;
    if (!current)
      throw std::runtime_error("Attempt to delete element out of bounds.\n");
  }
  // now current is the element to be deleted
  // this changes the next pointer of element before current
  if (current->m_previous) (current->m_previous)->m_next = current->m_next;
  // this else can only work if index is head.
  else
    m_head = current->m_next;
  // this changes the prev pointer of element after current
  if (current->m_next) (current->m_next)->m_previous = current->m_previous;
  // now delete
  delete current;
}


int main() {
  DoublyLinkedList<int> list;
list.addElement(10);
list.addElement(20);
list.addElement(30);
list.addElement(40);
list.printList();

list.deleteByValue(30); // Deletes 30
list.printList();

list.deleteByValue(10); // Deletes head (10)
list.printList();

  return 0;
}
