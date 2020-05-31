#include<iostream>
#include<exception>

class IndexOutOfBoundsException : public std::exception{
    virtual const char* what() const throw(){
        return "Trying to initialize array with size < 0 or invalid bounds";
    }

};

template <typename T>
class SafeArray{
private:
    T* arrayPtr{nullptr};
    int size{0};

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

    // Helps debug!
    friend std::ostream& operator<<(std::ostream& os, const SafeArray& ar){
        
        os << "[ ";
        for(int i = 0; i < ar.getSize(); i++){
            os << ar.arrayPtr[i] << " ";
        }
        
        os << "]\n";

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


