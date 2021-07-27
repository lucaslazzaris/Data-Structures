#include<iostream>
#include "SafeArray.cpp"

template <class T>
class Heap : public SafeArray<T> {
public:    
    using SafeArray<T>::SafeArray;

    int parent(int i) {
        return (i + 1) / 2 - 1;
    } 

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * (i + 1);
    }

    // O(lg n)
    void maxHeapify(int i){
        T largest;
        T l = left(i);
        T r = right(i);
        if (l < this->size && this->arrayPtr[l] > this->arrayPtr[i]) {
            largest = l;
        } else {
            largest = i;
        }
        if (r < this->size && this->arrayPtr[r] > this->arrayPtr[largest]) {
            largest = r;
        }
        if (largest != i){
            heapSwap(i, largest);
            maxHeapify(largest);
        }
    }

    void heapSwap(int node1, int node2){
        T aux = this->arrayPtr[node1];
        this->arrayPtr[node1] = this->arrayPtr[node2];
        this->arrayPtr[node2] = aux;
    }

    // O(n)
    void buildMaxHeap(){
        for(int i = this->size / 2 - 1; i >= 0 ; i--){
            maxHeapify(i);
        }
    }
};