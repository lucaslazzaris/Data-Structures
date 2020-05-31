#include<iostream>
#include<exception>

class IndexOutOfBoundsException : public std::exception{
    virtual const char* what() const throw(){
        return "Trying to initialize array with size < 0 or invalid bounds";
    }

};