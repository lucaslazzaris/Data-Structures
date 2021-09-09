#include<vector>

// O(1)
template<typename T>
void swap(T* a, T* b) {
    auto c = *a;
    *a = *b;
    *b = c;
}

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

// O(n)
template<typename T>
int randomizedPartition(std::vector<T>& vec, int left, int right){
    int pivotIndex = (rand() % (right - left + 1)) + left;
    swap(&vec[right], &vec[pivotIndex]);
    return partition(vec, left, right);
}

// O(n)
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