//
// Created by ufabi on 04.12.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_MYSMARTPOINTER_H
#define PRINT std::cout << "Amount of refs: "; std::cout << ref_counter->get_refs() << std::endl
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_MYSMARTPOINTER_H

#include "RefCounter.h"
#include <iostream>

template<class T>
class MySmartPointer {
private:
    T *element;
    RefCounter *ref_counter;
public:
    MySmartPointer() {
        this->element = new T();
        this->ref_counter = new RefCounter();
    }

    explicit MySmartPointer(const T &new_element) {
        this->element = new T(new_element);
        this->ref_counter = new RefCounter();
        ref_counter->add_ref();
        PRINT;
    }

    MySmartPointer(const MySmartPointer<T> &other) {
        this->element = new T(other.get_element());
        this->ref_counter = other.ref_counter;
        ref_counter->add_ref();
        PRINT;
    }

    ~MySmartPointer() {
        if (ref_counter->release() == 0) {
            delete element;
            delete ref_counter;
            std::cout<<"Deleted ";
            std::cout<<&element<<std::endl;
            PRINT;
        }
    }

    T get_element() const {
        return *element;
    }

    T *get_address() const {
        return element;
    }

    T &operator*() const {
        return *element;
    }

    void set_element(T new_element) {
        if (ref_counter->release() == 0) {
            delete element;
            delete ref_counter;
        }
        this->element = new T(new_element);
        this->ref_counter = new RefCounter();
        ref_counter->add_ref();
        PRINT;
    }

    MySmartPointer &operator=(const T &other) {
        set_element(other);
        return *this;
    }

    MySmartPointer &operator=(const MySmartPointer<T> &other) {
        if (this != &other) {
            if (ref_counter->release() == 0) {
                delete element;
                delete ref_counter;
            }
            this->element = other.element;
            this->ref_counter = other.ref_counter;
            ref_counter->add_ref();
        }
        PRINT;
        return *this;
    }
};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_MYSMARTPOINTER_H
