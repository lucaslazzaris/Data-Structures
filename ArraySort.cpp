#include<iostream>
#include<vector>

template<typename T>
void swap(T* a, T* b) {
    auto c = *a;
    *a = *b;
    *b = c;
}


template<typename T>
void insertionSort(std::vector<T>& vec){
    int size = vec.size();

    for(int i = 1; i < size; i++){
        auto key = vec[i];
        auto index = i - 1;

        while (index >= 0 && vec[index] > key){
            vec[index + 1] = vec[index];
            index -= 1;
        }

        vec[index + 1] = key;
    }
}

template<typename T>
void selectionSort(std::vector<T>& vec){
    int size = vec.size();

    int index;
    for(int i = 0; i < size - 1; i++){
        index = i;
        for(int j = i + 1; j < size; j++){
            if(vec[j] < vec[index]) {
                index = j;
            }
        }
        if (index != i){
            swap(&vec[i], &vec[index]);
        }
    }
}

template<typename T>
void bubbleSort(std::vector<T>& vec){
    int size = vec.size();
    int j = size - 1;

    for(int k = 0; k < size - 1; k++){
        auto swaped = false;
        for(int i = 0; i < j; i++){
            if(vec[i] > vec[i + 1]){
                swap(&vec[i], &vec[i + 1]);
                swaped = true;
            }
        }
        if(!swaped){
            return;
        }
        j -= 1;
    }    
}

// default size = -1 aims to make testing easier
template<typename T>
void recursiveBubbleSort(std::vector<T>& vec, int size=-1){
    if(size == -1) {
        size = vec.size();
    }
    if(size < 1) {
        return;
    }

    for(int i = 0; i < size - 1; i++){
        if(vec[i] > vec[i + 1]){
            swap(&vec[i], &vec[i + 1]);
        }
    }
    recursiveBubbleSort(vec, size - 1);
}
