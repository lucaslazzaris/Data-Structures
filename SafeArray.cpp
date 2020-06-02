#include<iostream>
#include<exception>
#include "Exceptions.cpp"

template <typename T>
class SafeArray{
private:
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
        for(int i = 0; i < size; i++){
            arrayPtr[i] = source.arrayPtr[i];
        }
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

    SafeArray& operator=(const SafeArray& source){
        
        if(&source == this){
            return *this;
        }

        delete [] arrayPtr;

        size = source.size;
        arrayPtr = new T[size]{};
        
        for(int i = 0; i < size; i++){
            arrayPtr[i] = source.arrayPtr[i];
        }

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


