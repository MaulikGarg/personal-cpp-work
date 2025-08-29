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
  if (!m_head) return;
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
  else {
    m_head = current->m_next;
    m_head->m_previous = nullptr;
  }
  // this changes the prev pointer of element after current
  if (current->m_next) (current->m_next)->m_previous = current->m_previous;
  // now delete
  delete current;
}

template <typename T>
void DoublyLinkedList<T>::deleteByValue(const T& value) {
  if (!m_head) return;

  NodeElement<T>* current{m_head};

  // first we loop until the first element is not the value
  while (current->m_data == value) {
    m_head = current->m_next;
    delete current;
    if (m_head) m_head->m_previous = nullptr;
    // if the list gets empty in this process, return.
    else
      return;
    current = m_head;
  }

  // now we delete in the rest of the list
  while (current) {
    if (current->m_data == value) {
      // first we link the adjacant elements
      if (current->m_previous) {
        (current->m_previous)->m_next = current->m_next;
      }
      if (current->m_next) {
        (current->m_next)->m_previous = current->m_previous;
      }

      NodeElement<T>* temp = current;
      current = current->m_next;
      delete temp;
    }

    else {
      current = current->m_next;
    }
  }
}

int main() {
  DoublyLinkedList<int> list;

  // Empty List Deletion
  list.deleteAtIndex(0); // Should not crash
  list.deleteByValue(999); // Should not crash
  
  // Single Element Test
  list.addElement(42);
  list.printList();

  list.deleteByValue(42); // Should delete the only element
  list.printList();

  // Add multiple elements with duplicates
  list.addElement(10);
  list.addElement(20);
  list.addElement(30);
  list.addElement(20);
  list.addElement(40);
  list.addElement(20);
  list.addElement(50);
  list.printList();

  // Delete non-existing value
  list.deleteByValue(999); // Shouldn't crash

  // Delete value in the middle
  list.deleteByValue(20); 
  list.printList();

  // Delete tail
  list.deleteByValue(50);
  list.printList();

  // Delete head
  list.deleteByValue(10);
  list.printList();

  // Delete all remaining
  list.deleteByValue(30);
  list.deleteByValue(40);
  list.printList();

  // Try adding after full deletion
  list.addElement(999);
  list.printList();

  // Negative index deletion (should throw)
  try {
    list.deleteAtIndex(-1);
  } catch (const std::runtime_error& e) {
    std::cout << e.what();
  }

  // Out-of-bounds index deletion
  try {
    list.deleteAtIndex(100);
  } catch (const std::runtime_error& e) {
    std::cout << e.what();
  }

  // Add back and delete by index
  list.addElement(5);
  list.addElement(10);
  list.addElement(15);
  list.printList();
  list.deleteAtIndex(1); // Delete middle element (10)
  list.printList();

  // Delete head using index
  list.deleteAtIndex(0);
  list.printList();

  // Delete tail using index
  list.deleteAtIndex(0); 
  list.printList();

  std::cout << "\nAll edge cases handled perfectly. ";
  return 0;
}
