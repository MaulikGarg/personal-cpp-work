#include <iostream>

/*----- MAIN CLASS ----*/
template <typename T>
class BinaryTree {
  /*-
  -- NODE STRUCT
  -*/
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

  /*-
  -- STRUCT END
  -*/

 public:
  BinaryTree();  // constructor, inserts into root node
  ~BinaryTree();
  void insert(Node* node);  // adds to a node
  void display() const;
  void display(Node* node, int depth = 0) const;

  // delete the copy functions
  BinaryTree(const BinaryTree&) = delete;
  BinaryTree operator=(const BinaryTree&) = delete;

 private:
  Node* m_root{nullptr};
  int m_size{};
  T insertPrompt();        // basic prompt asking node value and returning it
  void clear(Node* node);  // deletes a specific node and all its children
};

/*--- class end---*/

/* public functions */
template <typename T>
BinaryTree<T>::BinaryTree() {
  m_root = new Node{insertPrompt()};
  insert(m_root);
  ++m_size;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
  clear(m_root);
}

template <typename T>
void BinaryTree<T>::insert(Node* node) {
  char reply;

  // asks if insert to left then ask if return to right
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

template <typename T>
void BinaryTree<T>::display() const {
  display(m_root);
}

template <typename T>
void BinaryTree<T>::display(Node* node, int depth) const {
  if (!node) return;
  display(node->mm_right, depth + 1);
  if(depth){ // false if its root node
    for (int i = 1; i < depth; i++) std::cout << "|------";
    std::cout << "|---->";
  } 
  std::cout << node->mm_val << '\n' ;
  display(node->mm_left, depth + 1);
}

/* private helper functions */

template <typename T>
T BinaryTree<T>::insertPrompt() {
  std::cout << "Enter the node value: ";
  T value;
  std::cin >> value;
  return value;
}

template <typename T>
void BinaryTree<T>::clear(Node* node) {
  if (!node) return;
  clear(node->mm_left);
  clear(node->mm_right);
  delete node;
}

int main(){
  BinaryTree<int> tree;
  tree.display();
}
