//
// Created by ufabi on 04.12.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_MYSMARTPOINTER_H
#define PRINT std::cout << "Amount of refs: "; std::cout << ref_counter.get_refs() << std::endl
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_MYSMARTPOINTER_H

#include <iostream>

template<class T>
class MySmartPointer {
private:
    class RefCounter {
    private:
        int refs;

    public:
        RefCounter() : refs(0) {}

        void add_ref() {
            refs++;
        }

        int release() {
            return --refs;
        }

        int get_refs() const {
            return refs;
        }
    };

    T *element;
    RefCounter ref_counter;

public:
    MySmartPointer() : element(new T()), ref_counter(RefCounter()) {
        ref_counter.add_ref();
        PRINT;
    }

    explicit MySmartPointer(const T &new_element) : element(new T(new_element)), ref_counter(RefCounter()) {
        ref_counter.add_ref();
        PRINT;
    }

    MySmartPointer(const MySmartPointer<T> &other) : element(new T(*other)),
                                                     ref_counter(other.ref_counter) {
        ref_counter.add_ref();
        PRINT;
    }

    MySmartPointer(const MySmartPointer<T> &&other) noexcept: element(new T(*other)),
                                                              ref_counter(other.ref_counter) {
        ref_counter.add_ref();
        PRINT;
    }

    ~MySmartPointer() {
        if (ref_counter.release() == 0) {
            delete element;
        }
    }

    T &operator*() const {
        return *element;
    }

    void set_element(const T &new_element) {
        if (ref_counter.release() == 0) {
            delete element;
        }
        element = new T(new_element);
        ref_counter.add_ref();
    }

    MySmartPointer &operator=(const T &other) {
        set_element(other);
        return *this;
    }

    MySmartPointer &operator=(MySmartPointer<T> &&other) noexcept {
        if (this != &other) {
            delete element;
            this->element = other.element;
            this->ref_counter = other.ref_counter;
            other.element = nullptr;
            PRINT;
        }
        return *this;
    }
};

#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_MYSMARTPOINTER_H
