#include<iostream>
#include<vector>

template<typename T>
T insertionSort(const std::vector<T>& vec){
    int size = vec.size();

    for(int i = 1; i < size; i++){
        auto key = vec[i];

        i -= 1;

        while (i >= 0 && vec[i] > key){
            vec[i + 1] = vec[i];
            i -= 1;
        }
        vec[i + 1] = key;

    }

}