//
// Created by ufabi on 29.10.2023.
//

#ifndef EFFECTIVE_PROGRAMMING_TECHNIQUES_CSCAN_H
#define EFFECTIVE_PROGRAMMING_TECHNIQUES_CSCAN_H


#include <string>

class CScan {
private:
    char *lane;

public:
    CScan();

    explicit CScan(int size);

    ~CScan();

    void readLane();

    std::string getLane() const;

    void setLane(char *lane);

    void printLane() const;

    static void printPrompt(const char *prompt);

    static void printResult(const std::string &result);

};

static const int MAX_SIZE = 100;


#endif //EFFECTIVE_PROGRAMMING_TECHNIQUES_CSCAN_H
