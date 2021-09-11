#include<iostream>
#include "SafeArray.cpp"

template <class T>
class Stack : public SafeArray<T> {
public:    
    using SafeArray<T>::SafeArray;

    void push(const T& value) {
        SafeArray<T>::insert(value);
    }

    T pop() {
      if (empty()) {
        throw IndexOutOfBoundsException{};
      }
      return SafeArray<T>::remove(this->size - 1);
    }

    bool empty() {
      return SafeArray<T>::isEmpty();
    }
};