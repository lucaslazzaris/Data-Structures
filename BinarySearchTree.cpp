#include<iostream>

template <class T>
class Node {
private:
  T value{};
  Node<T>* left{nullptr};
  Node<T>* right{nullptr};
  Node<T>* parent{nullptr};

public:
  Node() = default;
  ~Node(){};
  Node(const T& data): value{data}{}
  Node(const T& data, Node* left, Node* right, Node* parent): value{data}, left{left}, right{right}, parent{parent}{} 

  T& getValue(void){
    return value;
  }

  T getValue(void) const {
    return value;
  }

  Node<T>* getLeft(void) const {
    return left;
  }

  Node<T>* getRight(void) const {
    return right;
  }
  Node<T>* getParent(void) const {
    return parent;
  }

  void setLeft(Node<T>* leftNode){
    left = leftNode;
    if (leftNode){
      leftNode->setParent(this);
    }
  }

  void setRight(Node<T>* rightNode){
    right = rightNode;
    if (rightNode) {
      rightNode->setParent(this);
    }
  }

  void setParent(Node<T>* const parentNode){
    parent = parentNode;
  }

  void setValue(T const& newValue){
    value = newValue;
  }
};

template <class T>
class BinarySearchTree {
public:

  BinarySearchTree()=default;
  BinarySearchTree(Node<T>* const newRoot){
    root = newRoot;
    size = 1;
  }

  ~BinarySearchTree(){clear();}

  void clear(){
    makeEmpty(root);
  }

  void makeEmpty(Node<T>* t){
    if (t == nullptr){
      return;
    }
    makeEmpty(t->getLeft());
    makeEmpty(t->getRight());
    delete t;
  }

  bool isEmpty() {
    return size == 0;
  }

  // O(n)
  void inorder_tree_walk(Node<T>* const node) const {
    if(node != nullptr){
      inorder_tree_walk(node->getLeft());
      std::cout << node->getValue() << std::endl;
      inorder_tree_walk(node->getRight());
    }
  }

  // O(h)
  Node<T>* searchNode(Node<T>* const node, const T& value) {
    if (node == nullptr ){
      return node;
    } 

    auto nodeValue = node->getValue();

    if(value == nodeValue) {
      return node;
    } else if (value < nodeValue) {
      return searchNode(node->getLeft(), value);
    } else {
      return searchNode(node->getRight(), value);
    }
  }

  // O(h)
  Node<T>* iterativeSearchNode(Node<T>* const startNode, const T& value){
    Node<T>* node = startNode;
    while (node != nullptr && node->getValue() != value) {
      if (value < node->getValue()) {
        node = node->getLeft();
      } else {
        node = node->getRight();
      }
    }
    return node;
  }

  // O(h)
  Node<T>* minimum(Node<T>* const startNode){
    Node<T>* current = startNode;
    while(current->getLeft() != nullptr){
      current = current->getLeft();
    }
    return current;
  }

  // O(h)
  Node<T>* maximum(Node<T>* const startNode){
    Node<T>* current = startNode;
    while(current->getRight() != nullptr){
      current = current->getRight();
    }
    return current;
  }

  // O(h)
  Node<T>* successor(Node<T>* const startNode) {
    if(startNode->getRight() != nullptr) {
      return minimum(startNode->getRight());
    }
    auto previous = startNode;
    auto current = startNode->getParent();
    while(current != nullptr && previous == current->getRight()) {
      previous = current;
      current = current->getParent();
    }
    return current;
  }

  // O(h)
  void insert(Node<T>* const newNode){
    Node<T>* current = nullptr;
    Node<T>* next = root;
    while(next != nullptr){
      current = next;
      if(newNode->getValue() < next->getValue()) {
        next = next->getLeft();
      } else {
        next = next->getRight();
      }
    }
    newNode->setParent(current);
    if(current == nullptr){
      root = newNode;
    } else if (newNode->getValue() < current->getValue()){
      current->setLeft(newNode);
    } else {
      current->setRight(newNode);
    }
    size++;
  }

  // O(1)
  void transplant(Node<T>* oldNode, Node<T>* newNode){
    if (!oldNode->getParent()){
      root = newNode;
    } else if(oldNode == oldNode->getParent()->getLeft()) {
      oldNode->getParent()->setLeft(newNode);
    } else {
      oldNode->getParent()->setRight(newNode);
    }
  }

  // O(h)
  void remove(Node<T>* node){
    if (!node) {
      return;
    }
    else if (!node->getLeft()) {
      transplant(node, node->getRight());
    } else if (!node->getRight()) {
      transplant(node, node->getLeft());
    } else {
      auto successorNode = minimum(node->getRight());
      if (successorNode->getParent() != node){
        transplant(successorNode, successorNode->getRight());
        successorNode->setRight(node->getRight());
      }
      transplant(node, successorNode);
      successorNode->setLeft(node->getLeft());
      successorNode->getLeft()->setParent(successorNode);
    }
    delete node;
    size--;
  }

  Node<T>* getRoot() {
    return root;
  }

  unsigned int getSize() {
    return size;
  }
private:

  Node<T>* root{nullptr};
  unsigned int size{0};
};

// int main(void) {
//   Node<int>* node1 = new(Node<int>);
//   Node<int>* node2 = new(Node<int>);
//   Node<int>* node3 = new(Node<int>);
//   Node<int>* node4 = new(Node<int>);
//   node1->setValue(10);
//   node2->setValue(9);
//   node3->setValue(11);
//   node4->setValue(7);
//   BinarySearchTree<int> tree{node1}; 
//   node1->setLeft(node2);
//   node1->setRight(node3);
//   node2->setLeft(node4);

//   tree.inorder_tree_walk(tree.getRoot());
//   return 0;
// }