#include <iostream>
#include <unordered_map>
#include <unordered_set>

// THIS IMPLEMENTATION USES AN ADJACENCY LIST
// THIS IS AN UNDIRECTED & UNWEIGHTED GRAPH

/*--- Primary Graph Class Start ---*/
template <typename T>
class Graph {
  // primary graph functions
 public:
  Graph() {};                         // constructor
  ~Graph();                           // destructor
  bool insertNode(T);                 // inserts a node into the graph
  bool edgeExists(const T, const T);  // returns true if edge exists
  bool makeEdge(const T, const T);    // makes an edge between two given nodes
  bool deleteEdge(const T, const T);  // deletes an existing edge between two given nodes
  bool deleteNode(T);  // deletes a specific node

  // disable shallow pointer copying
  Graph(const Graph&) = delete;
  Graph& operator=(const Graph&) = delete;

  // private graph functions
 private:
  

  // private graph data
  std::unordered_map<T, std::unordered_set<T>> m_nodes;  // hashmap for pairing/storing values to nodes
};

/*--- Primary Graph Class End ---*/

//
//
//

/*--- Public Function Implementations Start ---*/

template <typename T>
Graph<T>::~Graph() {
  m_nodes.clear();
}

template <typename T>
bool Graph<T>::insertNode(T value) {
  if (m_nodes.contains(value)) return false;
  m_nodes.insert({value, {}});
  return true;
}

template <typename T>
bool Graph<T>::edgeExists(const T node1, const T node2) {
  // Check if nodes exist
  if (!m_nodes.contains(node1) || !m_nodes.contains(node2)) return false;

  // Check if edge exists
  return m_nodes[node1].contains(node2);
}

template <typename T>
bool Graph<T>::makeEdge(const T node1, const T node2) {
  if (edgeExists(node1, node2)) return false;

  // Add the edge to both nodes
  m_nodes[node1].insert(node2);
  m_nodes[node2].insert(node1);
  return true;
}

template <typename T>
bool Graph<T>::deleteEdge(const T node1, const T node2){
  if(!edgeExists(node1, node2)) return false;

  // Remove the edge from both nodes
  m_nodes[node1].erase(node2);
  m_nodes[node2].erase(node1);
  return true;
}

template <typename T>
bool Graph<T>::deleteNode(T node){
  if(!m_nodes.contains(node)) return false;
  m_nodes.erase(node);
  return true;
}

/*--- Public Function Implementations End ---*/

//
//
//

/*--- Private Function Implementations Start ---*/

/*--- Private Function Implementations Start ---*/
