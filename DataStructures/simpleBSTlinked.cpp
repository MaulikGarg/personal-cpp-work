/*

TODO:

Add a constraint so that only comparable types can be selected for the template.

*/

#include <iostream>

/*--- primary tree class ---*/
template <typename T>
class BinarySearchTree {
  /*--- node with a value and two child pointers ---*/
  struct Node {
    T mm_data{};
    Node* mm_left{nullptr};
    Node* mm_right{nullptr};
    // node constructors
    Node(T val) : mm_data{val} {}
  };
  /*--- node struct end ---*/

  // primary BST functions
 public:
  BinarySearchTree();         // no value constructor
  BinarySearchTree(T value);  // constructor -> inserts into root
  ~BinarySearchTree();        // destructor -> deletes all nodes
  void insert(T value);       // adds into the BST after finding the appropriate location, ignores if repeat

  // disable shallow pointer copying
  BinarySearchTree(const BinarySearchTree&) = delete;
  BinarySearchTree operator=(const BinarySearchTree&) = delete;

 private:
  Node* m_root{};
  int m_size{};
  void deleteNode(Node* node);                         // delete a specific node
  void insert(Node* node, T value);                    // insert into a specific node
  Node* getNodeByValue(T value, Node* node = m_root);  // get a Node's pointer by its value
};
/*--- primary class end ---*/

/*--- public functions ---*/

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
  m_root = new Node(value);
  m_size++;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  deleteNode(m_root);
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
  // if no root then this is root
  if (!m_root) {
    m_root = new Node(value);
    m_size++;
  } else
    insert(m_root, value);
}

/*--- public functions end ---*/

/*--- private functions start ---*/

template <typename T>
void BinarySearchTree<T>::deleteNode(Node* node) {
  if (!node) return;
  // first delete the node's children then the node
  deleteNode(node->mm_left);
  deleteNode(node->mm_right);
  delete node;
  m_size--;
}

template <typename T>
void BinarySearchTree<T>::insert(Node* node, T value) {
  // first check the position then check if node exists.
  if (node->mm_data > value) {
    if (node->mm_left)
      insert(node->mm_left, value);
    else {
      node->mm_left = new Node(value);
      m_size++;
    }
  }

  else if (node->mm_data < value) {
    if (node->mm_right)
      insert(node->mm_right, value);
    else {
      node->mm_right = new Node(value);
      m_size++;
    }
  }

  // if control reaches here, that means its equal, we ignore.
}

template <typename T>
// default value for node is root.
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::getNodeByValue(T value, Node* node) {
  if (!node) return nullptr; // node doesn't exist.
  if(node->mm_data == value) return node;
  if(node->mm_data > value) return getNodeByValue(value, node->mm_left);
  return getNodeByValue(value, node->mm_right);
}

/*--- private functions end ---*/
