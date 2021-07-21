#include<iostream>
#include "SafeArray.cpp"

template <class T>
class Heap{
private:
    SafeArray<T> safeArray{};

public:
    Heap()=default;
    ~Heap() {}

    // Copy Constructor
    Heap(const Heap& source){
        safeArray = source.getSafeArray();
    }

    explicit Heap(int size){
        safeArray = SafeArray<T>{size};
    }
    
    T& operator[](int index){
        return safeArray[index];
    }

    T& operator[](int index) const {
        return safeArray[index];
    }

    Heap& operator=(const Heap& source){
        safeArray = source.getSafeArray();
        return *this;
    }
    
    SafeArray<T>& getSafeArray() {
        return safeArray;
    }

    SafeArray<T> getSafeArray() const {
        return safeArray;
    }

    bool operator==(const Heap& source) const{
        return safeArray == source.getSafeArray();
    }

    bool operator!=(const Heap& source) const{
        return safeArray != source.getSafeArray();
    }
};