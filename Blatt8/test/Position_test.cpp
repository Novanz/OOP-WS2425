#include "../src/PositionSorter.h"
#include <cassert>
#include <iostream>


//
// Created by nan on 19.11.24.
//


void testCtor() {
    std::string mordor = "Mordor";
    nan::Position position(mordor, 47, 11);
    assert(position.getName() == "Mordor");
    assert(position.getX() == 47);
    assert(position.getY() == 11);
}

void testCtorIntegrity() {
    std::string mordor = "Mordor";
    nan::Position position(mordor, 47, 11);
    mordor[0] = 'X';
    assert(position.getName() == "Mordor");
}

void testCompare() {
    std::string mordor = "Mordor";
    nan::Position position(mordor, 47, 11);
    assert(position == position);
    nan::Position position_name("zordor", 47, 11);
    nan::Position position_x(mordor, 48, 11);
    nan::Position position_y(mordor, 47, 12);
    assert(position < position_name);
    assert(position < position_x);
    assert(position < position_y);
    assert(position_name > position);
    assert(position_x > position);
    assert(position_y > position);
}

void testPositionSorter(nan::Position *position, int size) {
    nan::PositionSorter::sortPositions(position, size);
    for (int i = 1; i < size; i++) { assert((position[i - 1] <= position[i])); }
}

void testSortPositions() {
    nan::Position test_array[3] =
    {nan::Position("a", 1, 2),
     nan::Position("a", 6, 2),
     nan::Position("z", 1, 3)};
    testPositionSorter(test_array, 3);
}

int main() {
    std::cout << "starting tests..." << std::endl;

    testCtor();
    testCtorIntegrity();
    testCompare();
    testSortPositions();

    std::cout << "...finished" << std::endl;
}