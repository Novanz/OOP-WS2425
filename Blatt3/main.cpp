#include <cassert>
#include <iostream>
#include "src/Position.h"
namespace nan {

    void print_int_arr(int *arr, int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << std::endl;
        }
    }

    void print_position_arr(Position* arr, int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i].to_string() << std::endl;
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
        std::cout << "not sorted" << std::endl;
        print_int_arr(numbers, size);
        sort(numbers, size);
        std::cout << "sorted" << std::endl;
        print_int_arr(numbers, size);
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
        std::cout << "not sorted" << std::endl;
        print_position_arr(position,size);
        sort_position(position, size);
        std::cout << "sorted" << std::endl;
        print_position_arr(position,size);
        for (int i = 1; i < size; i++) {
            assert(position[i - 1].compare(position[i])<= 0);
        }
    }
    void test_sort_position() {
        auto *test_array = new Position[5];
        std::string name[5] = {"a", "b", "c", "d", "e"};
        for (int i = 0; i < 5; i++) {
                test_array[i] = Position(name[1], ((std::rand() % 100) + 1), ((std::rand() % 100) + 1));
        }
        test_sort_position(test_array, 5);
        delete[] test_array;
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