#include<vector>

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