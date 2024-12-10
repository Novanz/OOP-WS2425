//
// Created by novan on 19.11.24.
// Refactored on 8.12.24.:
// - Rename to Sorter
// - Make it a template class
// Description: Helper class to sort array of elements by following rules:

#ifndef POSITIONSORTER_H
#define POSITIONSORTER_H

#include <cctype>


namespace novan {
    template<typename T>
    class Sorter {
    private:
        static bool compare(const T &a, const T &b) {
            return a > b;
        }
    public:
        static void sort(T *arrayToSort, int size) {
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (compare(arrayToSort[i], arrayToSort[j])) {
                        T elementToSwap = arrayToSort[i];
                        arrayToSort[i] = arrayToSort[j];
                        arrayToSort[j] = elementToSwap;
                    }
                }
            }
        }
    };
   // Specialization for char
    template<>
    bool Sorter<char>::compare(const char &a, const char &b) {
        return tolower(a) > tolower(b);
    }
}
#endif //POSITIONSORTER_H
