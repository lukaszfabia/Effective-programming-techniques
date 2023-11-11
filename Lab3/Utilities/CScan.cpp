//
// Created by ufabi on 29.10.2023.
//

#include <iostream>
#include "CScan.h"

CScan::CScan() {
    lane = new char[MAX_SIZE];
}

CScan::CScan(int size) {
    lane = new char[size];
}

CScan::~CScan() {
    delete lane;
}

void CScan::readLane() {
    std::cin.getline(lane, MAX_SIZE);
}

std::string CScan::getLane() const {
    return lane;
}

void CScan::setLane(char *newLane) {
    lane = newLane;
}

void CScan::printLane() const {
    std::cout << getLane();
}

void CScan::printPrompt(const char *prompt) {
    std::cout << prompt;
}

void CScan::printResult(const std::string &result) {
    std::cout << result << std::endl;
}

void CScan::printLane(const std::string &lane) {
    std::cout << lane;
}
