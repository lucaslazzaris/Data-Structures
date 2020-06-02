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

    void setNext(Node<T>* const nextNode){
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
    List(Node<T>* const newHead){
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
        insert(value, 0);
    }

    void insertTail(const T& value){
        insert(value, size);
    }

    void insert(const T& value, int index){
        if(!isValidInsertableIndex(index)){
            throw IndexOutOfBoundsException{};
        }
        if(isEmpty()){
            head = new Node<T>(value);
            size += 1;
            return;
        }
        if(index == size){
            auto currentTail = getTail();
            auto newTail = new Node<T>(value);
            currentTail->setNext(newTail);
            size += 1;
            return;
        }
        if(index == 0){
            auto newHead = new Node<T>(value);
            newHead->setNext(head);
            head = newHead;
            size +=1;
            return;
        }
        auto current = head;
        for(int i = 0; i < index - 1; i++){
            current = current->getNext();
        }
        auto newNode = new Node<T>(value);
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        size++;
        
    }

    T popHead(void){
        return remove(0);
    }

    T popTail(void){
        return remove(size - 1);
    }

    T remove(int index){
        if(isEmpty() || !isValidIndex(index)){
            throw ZeroSizedOperation{};
        }
        if(index == 0){
            T headValue = head->getValue();
            auto right = head->getNext();
            delete head;
            head = right;
            size--;
            return headValue;
        }

        auto current = head;
        Node<T>* previous;
        for(int i = 0; i < index; i++){
            previous = current;
            current = current->getNext();
        }

        T oldIndexData = current->getValue();
        
        previous->setNext(current->getNext());
        delete current;
        size--;
        
        return oldIndexData;

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

    bool isValidInsertableIndex(int index) const{
        return index >= 0 && index <= size;
    }

    bool isEmpty(void) const{
        return size == 0;
    }

    Node<T>* getHead(void) const{
        return head;
    }

    Node<T>* getTail(void) const{
        auto current = head;
        if(!current){
            return nullptr;
        }
        while(current->getNext()){
            current = current->getNext();
        }
        return current;
    }

    int getSize(void) const{
        return size;
    }

private:
    
    Node<T>* head{nullptr};
    unsigned int size{0};

};
