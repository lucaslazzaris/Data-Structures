#include<iostream>
#include<exception>

class IndexOutOfBoundsException : public std::exception{
    virtual const char* what() const throw(){
        return "Trying to initialize array with size < 0 or invalid bounds";
    }

};

class ZeroSizedOperation : public std::exception{
    virtual const char* what() const throw(){
        return "Cannot perform this operation on an empty list";
    }

};

class InvalidKeyError : public std::exception {
    virtual const char* what() const throw(){
        return "Heap key is invalid";
    }
};

class QueueIsFull : public std::exception{
    virtual const char* what() const throw(){
        return "Queue is full";
    }

};