#include<iostream>
#include<exception>
#include "Exceptions.cpp"

template <class T>
class Stack {
public:
    Stack()=default;
    ~Stack(){
        delete [] arrayPtr;
    }

    // Copy Constructor
    Stack(const Stack& source) {
        size = source.size;
        top = source.top;
        memcpy(arrayPtr, source.getData(), size * sizeof(T));
    }

    explicit Stack(int size){
        if (size > 0){
            this->size = size;
            this->top = size - 1;
            this->arrayPtr = new T[size]{};
        } else {
            throw IndexOutOfBoundsException{};
        }
    }

    bool isEmpty(void) const {
        return top == -1;
    }

    T* getData() const {
        return arrayPtr;
    }

    int getSize() {
        return top;
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

    void push(const T& value) {
        if (top >= size - 1) {
            T* newArrayPtr = new T[size + 1]{};
            
            memcpy(newArrayPtr, arrayPtr, size * sizeof(T));
            
            delete [] arrayPtr;
            arrayPtr = newArrayPtr;
            size++;
        }

        arrayPtr[top + 1] = value;
        top++;
    }

    T pop() {
        if (isEmpty()) {
            throw IndexOutOfBoundsException{};
        }
        T popped = arrayPtr[top];
        top--;
        return popped;
    }

protected:
    unsigned int size{0};
    int top{-1};
    T* arrayPtr{nullptr};

    bool isValidIndex(int index) const {
        return index >= 0 && index < size;
    }
};