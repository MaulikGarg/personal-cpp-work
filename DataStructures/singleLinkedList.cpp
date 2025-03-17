#include <iostream>

template <typename T>
struct Node{
  T m_data{};
  Node<T>* m_next {nullptr};
  Node(const T& data) : m_data{data}, m_next{nullptr} {}
};

template <typename T>
class LinkedList{
  Node<T>* m_head {nullptr};
  Node<T>* m_tail {nullptr};
  int m_size{};

  public:
    LinkedList(){}
    void addFirst(const T& data);
};

template <typename T>
void LinkedList<T>::addFirst(const T& data){

  Node<T>* newNode = new Node{data};

  m_size++;

  if(!m_head){
    m_head = newNode;
    m_tail = newNode;
    return;
  }

  newNode->m_next = m_head;
  m_head = newNode;
}
