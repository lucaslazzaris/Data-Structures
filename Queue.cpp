#include<iostream>
#include "SafeArray.cpp"

template <class T>
class Queue : public SafeArray<T> {
public:
  using SafeArray<T>::SafeArray;

  void enqueue(const T& value){
    SafeArray<T>::insert(value);
  }

  T dequeue() {
    if (empty()){
        throw IndexOutOfBoundsException{};
    }
    return SafeArray<T>::remove(0);
  }

  bool empty() {
    return SafeArray<T>::isEmpty();
  }
};