#include<iostream>
#include<vector>
#include <stdlib.h>

template<typename T>
void swap(T* a, T* b) {
    auto c = *a;
    *a = *b;
    *b = c;
}

// O(n^2)
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

// O(n^2)
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

// O(n^2)
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
// O(n^2)
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

// fif size is odd, middle goes to the first vec 
template<typename T>
void merge(std::vector<T>& vec, int left, int middle, int right){
    std::vector<T> helper_vector(vec.size(), 0);
    helper_vector.reserve(vec.size());

    for (int i = left; i <= right; i++){
        helper_vector[i] = vec[i]; 
    }

    auto i = left;
    auto j = middle + 1;
    int k = left;

    while (i < middle + 1 && j < right + 1 ){
        if(helper_vector[i] < helper_vector[j]){
            vec[k] = helper_vector[i];
            i++;
        }
        else {
            vec[k] = helper_vector[j];
            j++;
        }
        k++;
    }

    while (i < middle + 1){
        vec[k] = helper_vector[i];
        i++;
        k++;
    } 
    while (j < right + 1){
        vec[k] = helper_vector[j];
        j++;
        k++;
    }

}

// O(n lgn)
template<typename T>
void mergeSort(std::vector<T>& vec, int left, int right){
    if(left >= right){
        return;
    }
    else{
        int middle = (left + right) / 2;
        mergeSort(vec, left, middle);
        mergeSort(vec, middle + 1, right);

        merge(vec, left, middle, right);
    }
}

// O(n)
template<typename T>
int partition(std::vector<T>& vec, int left, int right){
    auto pivot = vec[right];

    int i = left - 1;
    for(int j = left; j < right; j++){
        if(vec[j] <= pivot){
            i++;
            swap(&vec[i], &vec[j]);
        }
    }
    swap(&vec[i + 1], &vec[right]);
    return i + 1;
}

// O(n lgn)
template<typename T>
void quickSort(std::vector<T>& vec, int left, int right) {
    if(left >= right){
        return;
    }
    int pivotIndex = partition(vec, left, right);
    quickSort(vec, left, pivotIndex - 1);
    quickSort(vec, pivotIndex + 1, right);
}

template<typename T>
int randomizedPartition(std::vector<T>& vec, int left, int right){
    int pivotIndex = (rand() % (right - left + 1)) + left;
    swap(&vec[right], &vec[pivotIndex]);
    return partition(vec, left, right);
}

// O(n lgn)
template<typename T>
void randomizedQuickSort(std::vector<T>& vec, int left, int right){
    if(left >= right){
        return;
    }
    int pivotIndex = randomizedPartition(vec, left, right);
    randomizedQuickSort(vec, left, pivotIndex - 1);
    randomizedQuickSort(vec, pivotIndex + 1, right);
}

// O(n) must use integers between 0-k (k is inclusive)
std::vector<int> countingSort(std::vector<int> vec, int k) {
    int size = int(vec.size());
    std::vector<int> auxArray(k + 1, 0);
    std::vector<int> sortedArray(size, 0);

    for(int i = 0; i < size; i++){
        auxArray[vec[i]] += 1;
    }

    for(int i = 1; i < k + 1; i++){
        auxArray[i] += auxArray[i - 1];
    }
    
    for(int i = size - 1; i > - 1; i--){
        auxArray[vec[i]] -= 1;
        sortedArray[auxArray[vec[i]]] = vec[i];
    }

    return sortedArray;
}