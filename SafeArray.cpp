#include<iostream>
#include<exception>
#include "Exceptions.cpp"

template <typename T>
class SafeArray{
protected:
    T* arrayPtr{nullptr};
    unsigned int size{0};

    bool isValidIndex(int index) const{
        return index >= 0 && index < size;
    }

public:
    SafeArray()=default;
    ~SafeArray(){
        delete [] arrayPtr;
        }

    // Copy Constructor
    SafeArray(const SafeArray& source){
        size = source.size;
        arrayPtr = new T[size]{};
        memcpy(arrayPtr, source.getData(), size * sizeof(T));
        
    }

    explicit SafeArray(int size){
        if(size > 0){
            this->size = size;
            this->arrayPtr = new T[size]{};
        }
        else{
            throw IndexOutOfBoundsException{};
        }
    }

    bool isEmpty(void) const{
        return size == 0;
    }

    T* getData() const{
        return arrayPtr;
    }

    int getSize(void) const{
        return size;
    }

    T& operator[](int index){
        if(isValidIndex(index)){
            return arrayPtr[index];
        }
        else{
            throw IndexOutOfBoundsException{};
        }
    }

    T& operator[](int index) const{
        if(isValidIndex(index)){
            return arrayPtr[index];
        }
        else{
            throw IndexOutOfBoundsException{};
        }
    }

    void insert(const T &element, int index = -1) {
        if (index == -1){
            index = size;
        }
        T* newArrayPtr = new T[size + 1]{};
        
        if (index != 0) {
            memcpy(newArrayPtr, arrayPtr, index * sizeof(T));
        }
        if (index != size){
            memcpy(
                newArrayPtr + index + 1,
                arrayPtr + index,
                (size - index) * sizeof(T)
            );
        }

        size += 1;
        newArrayPtr[index] = element;
        delete [] arrayPtr;

        arrayPtr = newArrayPtr;
    }

    T remove(const int index) {
        if(!isValidIndex(index)){
            throw IndexOutOfBoundsException{};
        }
        T returnValue = arrayPtr[index];

        T* newArrayPtr = new T[size - 1]{};

        if(index != 0){
            memcpy(newArrayPtr, arrayPtr, index * sizeof(T));
        } 
        if (index != size - 1){
            memcpy(
                newArrayPtr + index,
                arrayPtr + index + 1,
                (size - index - 1) * sizeof(T)
            );
        }
        
        size -= 1;
        delete [] arrayPtr;

        arrayPtr = newArrayPtr;

        return returnValue;
    }

    SafeArray& operator=(const SafeArray& source){
        
        if(&source == this){
            return *this;
        }

        delete [] arrayPtr;

        size = source.size;
        arrayPtr = new T[size]{};
        
        memcpy(arrayPtr, source.getData(), size * sizeof(T));
        

        return *this;
    }

    bool operator==(const SafeArray& source) const{
        if(size != source.getSize()){
            return false;
        }
        for(int i=0; i < size; i++){
            if(arrayPtr[i] != source[i]){
                return false;
            }
        }

        return true;

    }

    bool operator!=(const SafeArray& source) const{
        if(size != source.getSize()){
            return true;
        }
        for(int i=0; i < size; i++){
            if(arrayPtr[i] != source[i]){
                return true;
            }
        }

        return false;

    }

    // Helps debug!
    friend std::ostream& operator<<(std::ostream& os, const SafeArray& ar){
        
        os << "[ ";
        for(int i = 0; i < ar.getSize(); i++){
            os << ar.arrayPtr[i] << " ";
        }
        
        os << "]\n";
        return os;
    }



};

/*
int main(void){
    int N = 5;
    SafeArray<double> a(N);
    
    int c1 = 2;
    int c2 = 3;
    for(int i =0; i< N; i++){
        a[i] = c1 + c2 * i;
    }

    std::cout << a << '\n';

}
*/


