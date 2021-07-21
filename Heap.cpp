#include<iostream>
#include "SafeArray.cpp"

template <class T>
class Heap : public SafeArray<T> {
public:    
    using SafeArray<T>::SafeArray;
};