// C++ Design Patterns and Derivatives Pricing---Listing 5.6, page 92

#ifndef WRAPPER_H
#define WRAPPER_H

#include <vector>

template<class T>
class Wrapper
{
public:
    Wrapper() {DataPtr = 0;}
    Wrapper(const T& inner) { DataPtr = inner.clone(); }
    ~Wrapper() { if (DataPtr != 0) delete DataPtr; }

    Wrapper(const Wrapper<T>& original) {
        if (original.DataPtr != 0)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr = 0;
    }

    Wrapper& operator=(const Wrapper<T>& original) {
        if (this != &original) {
            if (DataPtr != 0)
                delete DataPtr;
            DataPtr = (original.DataPtr != 0) ? original.DataPtr->clone() : 0;
        }

        return *this;
    }

    T& operator*() { return *DataPtr; }
    const T& operator*() const { return *DataPtr; }
    const T* operator->() const { return DataPtr; }
    T* operator->() { return DataPtr; }
private:
    T* DataPtr;
};

#endif