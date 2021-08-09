#include<iostream>
#include "SafeArray.cpp"

template <class T>
class Heap : public SafeArray<T> {
private:
    unsigned int heapSize{0};
public:    
    using SafeArray<T>::SafeArray;
    
    // Copy Constructor
    Heap(const Heap& source) : SafeArray<T>(source) {
        this->heapSize = source.getSize();        
    }

    explicit Heap(int size) : SafeArray<T>(size){
        this->heapSize = size;
    }

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
        if (l < this->heapSize && this->arrayPtr[l] > this->arrayPtr[i]) {
            largest = l;
        } else {
            largest = i;
        }
        if (r < this->heapSize && this->arrayPtr[r] > this->arrayPtr[largest]) {
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
        for(int i = this->heapSize / 2 - 1; i >= 0 ; i--){
            maxHeapify(i);
        }
    }

    // O(nlgn)
    void heapSort(){
        buildMaxHeap();
        int length = this->heapSize;
        for(int i = length - 1; i > 0 ; i--){
            heapSwap(0, i);
            this->heapSize -= 1;
            maxHeapify(0);
        }
    }
};