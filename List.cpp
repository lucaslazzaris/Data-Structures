#include<iostream>
#include<exception>
#include "IndexOutOfBoundsException.cpp"

template <class T>
class Node{

private:
    Node<T>* next{nullptr};
    T value{};

public:

    Node() = default;
    ~Node(){};
    Node(const T& data): value{data}{}
    Node(const T& data, Node* nextNode): value{data}, next{nextNode}{}

    T& getValue(void){
        return value;
    }

    T getValue(void) const{
        return value;
    }

    Node<T>* getNext(void) const{
        return next;
    }

    
};

template <class T>
class List{
public:

    Node<T>* getHead(void){
        return head;
    }

    int getSize(void){
        return size;
    }

    List()=default;

    List(T headValue){
        Node<T>* node = new Node<T>(headValue);
        head = node;
        size = 1;
    }
    List(Node<T>* newHead){
        head = newHead;
        size = 1;
    }

    T& operator[](int index){
        
        if(!isValidIndex(index)){
            throw IndexOutOfBoundsException{};
        }
        
        Node<T>* current;
        current = head;
        for(int i = 0; i < index; i++){
            current = current->getNext();
        }
        return current->getValue();

    }

    bool isValidIndex(int index){
        return index >= 0 && index < size; 
    }

private:
    
    Node<T>* head{nullptr};
    unsigned int size{0};



};