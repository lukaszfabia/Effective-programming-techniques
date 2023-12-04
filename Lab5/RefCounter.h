//
// Created by ufabi on 04.12.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_REFCOUNTER_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_REFCOUNTER_H


class RefCounter {
private:
    int refs;

public:
    RefCounter() {
        refs = 0;
    }

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


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_REFCOUNTER_H
