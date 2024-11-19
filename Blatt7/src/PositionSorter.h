//
// Created by nan on 19.11.24.
//
// Description: Helper class to sort array of positions by following rules:

#ifndef POSITIONSORTER_H
#define POSITIONSORTER_H

#include "Position.h"

namespace nan {
    class PositionSorter {
    public:
        static void sortPositions(Position* positions, int size) {
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (positions[i].getX() > positions[j].getX() ||
                        (positions[i].getX() == positions[j].getX() && positions[i].getY() > positions[j].getY())) {
                        Position temp = positions[i];
                        positions[i] = positions[j];
                        positions[j] = temp;
                    }
                }
            }
        }
    };
}
#endif //POSITIONSORTER_H
