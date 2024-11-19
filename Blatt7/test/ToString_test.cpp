//
// Created by nan on 19.11.24.
//
#include <iostream>
#include "../src/Position.h"
#include "../src/City.h"

nan::Position createPosition() {
    std::string mordor = "Mordor";
    nan::Position result(mordor, 47, 11);
    return result;
}

nan::City createCity() {
    auto position = createPosition();
    std::string pois[] = {"Sauron", "Minas Morgul", "Orodruin"};
    nan::City result("Mordor", 47, 11, pois, 3);
    return result;
}

void testPosition() {
    auto position = createPosition();
    std::cout << position << std::endl;
}

void testCity() {
    auto city = createCity();
    std::cout << city << std::endl;
}

int main() {
    std::cout << "starting tests..." << std::endl;
    std::cout << "print Position..." << std::endl;

    testPosition();
    std::cout << "print City..." << std::endl;
    testCity();
    std::cout << "...finished" << std::endl;
}