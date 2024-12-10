//
// Created by novan on 10.12.24.
//

#include "../src/Sorter.h"
#include "../src/Position.h"
#include <cassert>
#include <iostream>


void testSorter(novan::Position *position, int size) {
    novan::Sorter<novan::Position>::sort(position, size);
    for (int i = 1; i < size; i++) { assert((position[i - 1] <= position[i])); }
}

void testSortPositions() {
    novan::Position test_array[3] =
    {novan::Position("a", 1, 2),
     novan::Position("a", 6, 2),
     novan::Position("z", 1, 3)};
    testSorter(test_array, 3);
}

void testSortChars() {
    char chars[4]{'B','a','A','x'};
    char expected[4]{'a','A','B','x'};
    novan::Sorter<char>::sort(chars,4);
    for (int i = 0; i < 4; ++i) {
        assert(chars[i]==expected[i]);
    }
}
int main() {
    std::cout << "starting tests..." << std::endl;

    std::cout << "starting SortPositions..." << std::endl;
    testSortPositions();
    std::cout << "...OK" << std::endl;

    std::cout << "starting SortChars..." << std::endl;
    testSortChars();
    std::cout << "...OK" << std::endl;
    std::cout << "...finished" << std::endl;
}