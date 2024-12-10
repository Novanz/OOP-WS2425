//
// Created by nan on 10.12.24.
//

#include "../src/Sorter.h"
#include "../src/Position.h"
#include <cassert>
#include <iostream>

void testSorter(nan::Position *position, int size) {
    nan::Sorter<nan::Position>::sort(position, size);
    for (int i = 1; i < size; i++) { assert((position[i - 1] <= position[i])); }
}

void testSortPositions() {
    nan::Position test_array[3] =
    {nan::Position("a", 1, 2),
     nan::Position("a", 6, 2),
     nan::Position("z", 1, 3)};
    testSorter(test_array, 3);
}

int main() {
    std::cout << "starting tests..." << std::endl;

    testSortPositions();

    std::cout << "...finished" << std::endl;
}