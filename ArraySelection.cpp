#include<vector>
#include "ArraySort.cpp"

// O(n)
template<typename T>
void minMax(std::vector<T> vec, T& currentMin, T&currentMax){
    int size = vec.size();
    int start;

    if(size % 2 == 0){
        start = 2;
        if(vec[0] > vec[1]){
            currentMax = vec[0];
            currentMin = vec[1];
        }
        else {
            currentMax = vec[1];
            currentMin = vec[0];
        }
    }
    else {
        start = 1;
        currentMax = vec[0];
        currentMin = vec[0];
    }

    for(int i = start; i < size - 1; i+= 2){
        if(vec[i] > vec[i + 1]){
            if(vec[i] > currentMax){
                currentMax = vec[i];
            }
            if(vec[i + 1] < currentMin){
                currentMin = vec[i + 1];
            }
        }
        else {
            if(vec[i + 1] > currentMax){
                currentMax = vec[i + 1];
            }
            if(vec[i] < currentMin){
                currentMin = vec[i];
            }
        }
    }
}

// O(n)
template<typename T>
T min(std::vector<T> vec){
    T currentMin = vec[0];
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] < currentMin){
            currentMin = vec[i];
        }
    }
    return currentMin;
}

// O(n)
template<typename T>
T max(std::vector<T> vec){
    T currentMax = vec[0];
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] > currentMax){
            currentMax = vec[i];
        }
    }
    return currentMax;
}

// expected O(n), worst O(n^2)
template<typename T>
T randomizedSelect(std::vector<T>& vec, int left, int right, int n) {
    if(left == right) {
        return vec[left];
    }

    int pivotIndex = randomizedPartition(vec, left, right);
    int relativePositionPivot = pivotIndex - left + 1;

    if(n == relativePositionPivot) {
        return vec[pivotIndex];
    } else if (n < relativePositionPivot){
        return randomizedSelect(vec, left, pivotIndex - 1, n);
    }
    else {
        return randomizedSelect(vec, pivotIndex + 1, right, n - relativePositionPivot);
    }
}


template<typename T>
int partition5(std::vector<T>& vec, int left, int right){
    insertionSort(vec, left, right);
    return floor((left + right) / 2 );
}

template<typename T>
int pivot(std::vector<T>& vec, int left, int right) {
    if (right - left < 5) {
        return partition5(vec, left, right);
    }
    for (int i = left; i < right; i+= 5){
        int subRight = i + 4;
        if(subRight > right){
            subRight = right;
        }
        int median5 = partition5(vec, i, subRight);
        swap(&vec[median5], &vec[left + floor((i - left) / 5)]);
    }

    int mid = (right - left) / 10 + left + 1;
    return mid;
}

template<typename T>
int medianPartition(std::vector<T>& vec, int left, int right) {
    int pivotIndex = pivot(vec, left, right);
    swap(&vec[right], &vec[pivotIndex]);
    return partition(vec, left, right);
}

// O(n)
template<typename T>
T quickSelect(std::vector<T>& vec, int left, int right, int n) {
    if(left == right) {
        return vec[left];
    }
    
    int pivotIndex = medianPartition(vec, left, right);
    int relativePositionPivot = pivotIndex - left + 1;

    if(n == relativePositionPivot){
        return vec[pivotIndex];
    } else if (n < relativePositionPivot){
        return quickSelect(vec, left, pivotIndex - 1, n);
    } else {
        return quickSelect(vec, pivotIndex + 1, right, n - relativePositionPivot);
    }
}

