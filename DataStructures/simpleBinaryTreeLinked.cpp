#include <iostream>

template <typename T>
class BinaryTree {
  // simple element struct with pointers to left right nodes
  struct Node {
    T mm_val{};
    Node* mm_left{nullptr};
    Node* mm_right{nullptr};
    // node constructors
    Node(T val) : mm_val{val} {}
    Node(T val, Node* l, Node* r = nullptr)
        : mm_val{val}, mm_left{l}, mm_right{r} {}
  };

 public:
  BinaryTree(); // constructor, inserts into root node
  ~BinaryTree();
  void insert(Node* node); // adds to a node 

 private:
  Node* m_root{nullptr};
  int m_size{};
  T insertPrompt();
};

template <typename T>
BinaryTree<T>::BinaryTree() {
  m_root = new Node{insertPrompt()};
  insert(m_root);
  ++m_size;
}

template <typename T>
BinaryTree<T>::~BinaryTree(){
  
}

template <typename T>
T BinaryTree<T>::insertPrompt() {
  std::cout << "Enter the node value: ";
  T value;
  std::cin >> value;
  return value;
}

template <typename T>
void BinaryTree<T>::insert(Node* node) {
  char reply;

  std::cout << "Do you want to insert to the left of " << node->mm_val
            << " ?(y/n)\n>";
  std::cin >> reply;
  if (reply == 'y' || reply == 'Y') {
    node->mm_left = new Node{insertPrompt()};
    insert(node->mm_left);
    ++m_size;
  }

  std::cout << "Do you want to insert to the right of " << node->mm_val
            << " ?(y/n)\n>";
  std::cin >> reply;
  if (reply == 'y' || reply == 'Y') {
    node->mm_right = new Node{insertPrompt()};
    insert(node->mm_right);
    ++m_size;
  }
}
