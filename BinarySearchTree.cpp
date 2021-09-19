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

  void setLeft(Node<T>* const leftNode){
    left = leftNode;
  }

  void setRight(Node<T>* const rightNode){
    right = rightNode;
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
      std::cout << node->getValue();
      inorder_tree_walk(node->getRight());
    }
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