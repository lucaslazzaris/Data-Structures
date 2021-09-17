#include<iostream>
#include<exception>
#include "Exceptions.cpp"

// Tail is the last element to be dequeued, NOT the one after it.
// Head is the first element to be dequeued
template <class T>
class Queue {
public:
  Queue() = default;
  ~Queue(){
    delete [] arrayPtr;
  }

  // Copy Constructor
  Queue(const Queue& source){
    size = source.size;
    head = source.head;
    tail = source.tail;
    elements = source.elements;
    memcpy(arrayPtr, source.getData(), size * sizeof(T));
  }

  explicit Queue(int size){
    if (size > 0){
      this->size = size;
      this->tail = size - 1;
      this->head = 0;
      this->arrayPtr = new T[size]{};
      this->elements = size;
    } else {
      throw IndexOutOfBoundsException{};
    }
  }

  bool isEmpty(void) const {
    return elements == 0;
  }

  T* getData() const {
    return arrayPtr;
  }

  T& operator[](int index) {
    if(isValidIndex(index)){
        return arrayPtr[index];
    } else {
        throw IndexOutOfBoundsException{};
    }
  }

  T& operator[](int index) const {
      if(isValidIndex(index)){
          return arrayPtr[index];
      } else {
          throw IndexOutOfBoundsException{};
      }
  }

  void enqueue(const T& value){
    int newTail = (tail + 1)  % size;
    // overflow
    if (newTail == head && elements != 0){  
      throw QueueIsFull{};
    } else {
      arrayPtr[newTail] = value;
      tail = newTail;
      elements++;
    }
  }

  T dequeue() {
    if (isEmpty()){
        throw IndexOutOfBoundsException{};
    } else {
      T dequeuedElement = arrayPtr[head];
      elements--;
      head = (head + 1) % size;
      return dequeuedElement;
    }
  }

  void setSize(int size){
    this->size = size;
    this->arrayPtr = new T[size]{};
  }

protected:
  unsigned int size{0};
  unsigned int elements{0};
  int head{0};
  int tail{-1};
  T* arrayPtr{nullptr};

  bool isValidIndex(int index) const {
    return index >= 0 && index < size;
  }
};