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

    void setNext(Node<T>* nextNode){
        next = nextNode;
    }

    
};

template <class T>
class List{
public:



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

   
    Node* find(const T& value) const{
        if(isEmpty()){
            return nullptr;
        }
        

    }

    void insertHead(const T& value){
        if(size == 0){
            auto node = new Node<T>(value);
            head = node;
            size += 1;
        }

        else{
            auto node = new Node<T>(value);
            node->setNext(head);
            head = node;
            size += 1;
        }

    }

    void insertTail(const T& value){
        if(size == 0){
            auto node = new Node<T>(value);
            head = node;
            size += 1;
        }

        else{
            auto current = head;
            
            while(current->getNext()){
                current = current->getNext();
            }
            // current is now the tail
            auto newTail = new Node<T>(value);
            current->setNext(newTail);
            size += 1;
        }
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

    bool isEmpty(void){
        return size == 0;
    }

    Node<T>* getHead(void){
        return head;
    }

    int getSize(void){
        return size;
    }

private:
    
    Node<T>* head{nullptr};
    unsigned int size{0};



};