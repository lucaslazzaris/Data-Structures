#include<iostream>
#include<exception>
#include "Exceptions.cpp"

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
    ~List(){clear();}

    void clear(){
        while(!isEmpty()){
            popHead();
        }
    }

    bool exists(const T& value) const{
        if(isEmpty()){
            return false;
        }
        auto current = head;
        while(current->getNext()){
            if(current->getValue() == value){
                return true;
            }
            current = current->getNext();
        }
        if(current->getValue() == value){
            return true;
        }
        return false;

    }

    Node<T>* findNode(const T& value) const{
        if(isEmpty()){
            return nullptr;
        }
        auto current = head;
        while(current->getNext()){
            if(current->getValue() == value){
                return current;
            }
            current = current->getNext();
        }
        if(current->getValue() == value){
            return current;
        }
        return nullptr;
    }

    int findIndex(const T& value) const{
        if(isEmpty()){
            return -1;
        }
        int i = 0;
        auto current = head;
        while(current->getNext()){
            if(current->getValue() == value){
                return i;
            }
            current = current->getNext();
            i++;
        }
        if(current->getValue() == value){
            return i;
        }
        // Not found
        return -1;

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

    T popHead(void){
        if(isEmpty()){
            throw ZeroSizedOperation{};
        }
        
        T data = head->getValue();
        auto secondNode = head->getNext();
        delete head;

        head = secondNode;
        size--;
        return data;
    }

    T popTail(void){
        if(isEmpty()){
            throw ZeroSizedOperation{};
        }
        else if(getSize() == 1){
            return popHead();
        }
        
        auto current = head;
        Node<T>* previous;
        while(current->getNext()){
            previous = current;
            current = current->getNext();
        }

        T data = current->getValue();
        previous->setNext(nullptr);

        delete current;

        size--;

        return data;
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

    bool isValidIndex(int index) const{
        return index >= 0 && index < size; 
    }

    bool isEmpty(void) const{
        return size == 0;
    }

    Node<T>* getHead(void) const{
        return head;
    }

    int getSize(void) const{
        return size;
    }

private:
    
    Node<T>* head{nullptr};
    unsigned int size{0};



};


// TODO: Insert and remove after K element!
// TODO: Refatorate to have a Node* tail(){...}