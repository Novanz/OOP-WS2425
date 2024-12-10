//
// Created by nan on 19.11.24.
// Refactored on 8.12.24. :
// - Rename to Sorter
// - Make it a template class
// Description: Helper class to sort array of elements by following rules:

#ifndef POSITIONSORTER_H
#define POSITIONSORTER_H


namespace nan {
    template<typename T>
    class Sorter {
    public:
        static void sort(T *elements, int size) {
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (elements[i] > elements[j]) {
                        T temp = elements[i];
                        elements[i] = elements[j];
                        elements[j] = temp;
                    }
                }
            }
        }
    };
}
#endif //POSITIONSORTER_H
