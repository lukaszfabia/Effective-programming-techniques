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
    MySmartPointer() : element(new T()), ref_counter(new RefCounter()) {
        ref_counter->add_ref();
        PRINT;
    }

    explicit MySmartPointer(const T &new_element) : element(new T(new_element)), ref_counter(new RefCounter()) {
        ref_counter->add_ref();
        PRINT;
    }

    MySmartPointer(const MySmartPointer<T> &other) : element(new T(other.get_element())),
                                                     ref_counter(other.ref_counter) {
        ref_counter->add_ref();
        PRINT;
    }

    MySmartPointer(const MySmartPointer<T> &&other) noexcept: element(new T(other.get_element())), ref_counter(other.ref_counter) {
        ref_counter->add_ref();
        PRINT;
    }

    ~MySmartPointer() {
        if (ref_counter->release() == 0) {
            delete element;
            delete ref_counter;
            std::cout << &element << std::endl;
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

    T &operator->() const {
        return element;
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

    MySmartPointer &operator=(MySmartPointer<T> &&other) noexcept {
        if (this != &other) {
            delete element;
            delete ref_counter;
            this->element = new T(other.get_element());
            this->ref_counter = other.ref_counter;
            ref_counter->add_ref();
            other.element = nullptr;
            other.ref_counter = nullptr;
            PRINT;
        }
        return *this;
    }
};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_MYSMARTPOINTER_H
