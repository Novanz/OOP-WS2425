//
// Created by nan on 19.11.24.
// Refactored on 8.12.24. :
// - Rename to Sorter
// - Make it a template class
// Description: Helper class to sort array of elements by following rules:

#ifndef POSITIONSORTER_H
#define POSITIONSORTER_H

#include <cctype>


namespace nan {
    template<typename T>
    class Sorter {
    public:
        static void sort(T *arrayToSort, int size) {
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (arrayToSort[i] > arrayToSort[j]) {
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
    class Sorter<char> {
    public:
        static void sort(char *arrayToSort, int size) {
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (tolower(arrayToSort[i]) > tolower(arrayToSort[j])) {
                        char elementToSwap = arrayToSort[i];
                        arrayToSort[i] = arrayToSort[j];
                        arrayToSort[j] = elementToSwap;
                    }
                }
            }
        }
    };
}
#endif //POSITIONSORTER_H
