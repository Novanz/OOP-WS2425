#include <cassert>
#include <iostream>
#include "src/Position.h"
namespace nan {

    void print_int_arr(int *arr, int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << std::endl;
        }
    }

    void sort(int *numbers, int size) {
        for (int i = 1; i < size; ++i) {
            int key = numbers[i];
            int j = i - 1;
            while (j >= 0 && numbers[j] > key) {
                numbers[j + 1] = numbers[j];
                j = j - 1;
            }
            numbers[j + 1] = key;
        }
    }

    void test_sort(int *numbers, int size) {
        sort(numbers, size);
        for (int i = 1; i < size; i++) {
            assert(numbers[i - 1] <= numbers[i]);
        }
    }

    void test_sort() {
        for (int i = 5; i < 10; i++) {
            int *test_array = new int[i];
            for (int j = i; j > 0; j--) {
                test_array[i - j] = (std::rand() % 100) + 1;
            }
            test_sort(test_array, i);
            delete[] test_array;
        }
    }

    void sort_position(Position *position, int size) {
        for (int i = 1; i < size; ++i) {
            Position key = position[i];
            int j = i - 1;
            while (j >= 0 && position[j].compare(key) > 0) {
                position[j + 1] = position[j];
                j = j - 1;
            }
            position[j + 1] = key;
        }
    }

    void test_sort_position(Position *position, int size) {
        sort_position(position, size);
        for (int i = 1; i < size; i++) {
            assert(position[i - 1].compare(position[i])<= 0);
        }
    }
    void test_sort_position() {
        Position test_array[3] = {Position("a",1,2), Position("a",6,2), Position("z",1,3)};
        test_sort_position(test_array, 3);
    }
}// namespace nan

int main() {
    int size = 5;
    int *numbers = new int[size]{5, 4, 3, 2, 1};
    nan::test_sort(numbers, size);
    delete[] numbers;
    nan::test_sort();
    nan::test_sort_position();
    return 0;
}