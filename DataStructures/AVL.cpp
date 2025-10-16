// IMPORTANT NOTE
// THIS IMPLEMENTATION USES LEFT - RIGHT FOR BALANCE FACTOR
// HENCE:
// -1 : RIGHT HEAVY, 1 : LEFT HEAVY

#include <iostream>

/*--- primary tree class ---*/
template <typename T>
class AVL_Tree {
  /*--- node with a value and two child pointers ---*/
  struct Node {
    T mm_data{};
    Node* mm_left{nullptr};
    Node* mm_right{nullptr};
    int mm_height{};
    // node constructors
    Node(T val) : mm_data{val} {}
  };
  /*--- node struct end ---*/

  // primary BST functions
 public:
  AVL_Tree() {};         // no value constructor
  AVL_Tree(T value);     // constructor -> inserts into root
  ~AVL_Tree();           // destructor -> deletes all nodes
  void insert(T value);  // adds into the BST after finding the appropriate location, ignores if repeat

  // disable shallow pointer copying
  AVL_Tree(const AVL_Tree&) = delete;
  AVL_Tree operator=(const AVL_Tree&) = delete;

 private:
  Node* m_root{};
  int m_size{};
  void deleteNode(Node* node);                         // delete a specific node
  Node* insert(Node* node, T value);                   // insert into a specific node
  Node* getNodeByValue(T value, Node* node = m_root);  // get a Node's pointer by its value
  int height(Node* node);  // returns the height of a node, i.e, number of edges until a leaf
  // balancing functions
  Node* rotate(Node* node);       // determines which rotation is needed and performs it
  Node* leftRotate(Node* node);   // performs a left rotation on a node
  Node* rightRotate(Node* node);  // performs a right rotation on a node
};
/*--- primary class end ---*/

/*--- public functions ---*/

template <typename T>
AVL_Tree<T>::AVL_Tree(T value) {
  m_root = new Node(value);
  m_size++;
}

template <typename T>
AVL_Tree<T>::~AVL_Tree() {
  deleteNode(m_root);
}

template <typename T>
void AVL_Tree<T>::insert(T value) {
  m_root = insert(m_root, value);
}

/*--- public functions end ---*/

/*--- private functions start ---*/

template <typename T>
void AVL_Tree<T>::deleteNode(Node* node) {
  if (!node) return;
  // first delete the node's children then the node
  deleteNode(node->mm_left);
  deleteNode(node->mm_right);
  delete node;
  m_size--;
}

template <typename T>
typename AVL_Tree<T>::Node* AVL_Tree<T>::insert(Node* node, T value) {
  if (!node) {
    m_size++;
    return new Node(value);
  }
  // check the position then insert recursively
  if (value < node->mm_data) {
    node->mm_left = insert(node->mm_left, value);
  } else if (value > node->mm_data) {
    node->mm_right = insert(node->mm_right, value);
  }  // if control reaches here, that means its equal, we ignore.

  node->mm_height = std::max(height(node->mm_left), height(node->mm_right)) + 1;
  return rotate(node);  // return the original node
}

template <typename T>
// default value for node is root.
typename AVL_Tree<T>::Node* AVL_Tree<T>::getNodeByValue(T value, Node* node) {
  if (!node) node = m_root;   // return root if node doesn't exist
  if (!node) return nullptr;  // empty tree
  if (node->mm_data == value) return node;
  if (node->mm_data > value) return getNodeByValue(value, node->mm_left);
  return getNodeByValue(value, node->mm_right);
}

template <typename T>
int AVL_Tree<T>::height(Node* node) {
  if (!node) return -1;
  return node->mm_height;
}

template <typename T>
typename AVL_Tree<T>::Node* AVL_Tree<T>::rotate(Node* node) {
  int balance = height(node->mm_left) - height(node->mm_right);
  // first check if it is left or right heavy
  if (balance > 1) {
    int leftBalance = height(node->mm_left->mm_left) - height(node->mm_left->mm_right);
    // check if left left or left right

    if (leftBalance >= 0) {
      // left left case
      return rightRotate(node);
    } else {
      // left right case
      node->mm_left = leftRotate(node->mm_left);
      return rightRotate(node);
    }

  } else if (balance < -1) {
    int rightBalance = height(node->mm_right->mm_left) - height(node->mm_right->mm_right);
    // check if right right or right left

    if (rightBalance <= 0) {
      // right right case
      return leftRotate(node);
    } else {
      // right left case
      node->mm_right = rightRotate(node->mm_right);
      return leftRotate(node);
    }
  }

  return node; // no rotation needed, balance was maintained
}

template <typename T>
typename AVL_Tree<T>::Node* AVL_Tree<T>::leftRotate(Node* node) {
  Node* rightChild = node->mm_right;  // will be the new root

  // the left side rotation
  node->mm_right = rightChild->mm_left;
  rightChild->mm_left = node;

  // adjust height
  node->mm_height = std::max(height(node->mm_left), height(node->mm_right)) + 1;
  rightChild->mm_height = std::max(height(rightChild->mm_left), height(rightChild->mm_right)) + 1;

  return rightChild;
}

template <typename T>
typename AVL_Tree<T>::Node* AVL_Tree<T>::rightRotate(Node* node) {
  Node* leftChild = node->mm_left;  // will be the new root

  // the right side rotation
  node->mm_left = leftChild->mm_right;
  leftChild->mm_right = node;

  // adjust height
  node->mm_height = std::max(height(node->mm_left), height(node->mm_right)) + 1;
  leftChild->mm_height = std::max(height(leftChild->mm_left), height(leftChild->mm_right)) + 1;

  return leftChild;
}

/*--- private functions end ---*/
