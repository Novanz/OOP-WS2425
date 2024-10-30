//
// Created by nan on 10/29/24.
//

#ifndef BLATT3_CITY_H
#define BLATT3_CITY_H

#include "Position.h"
namespace nan {

    class City {
        private:
            nan::Position m_position;
            int m_number_of_pois;
            std::string *m_pois;
            static std::string *make_copy(const std::string *source_array, int size){
                auto *result = new std::string [size];
                for (int i = 0; i < size; i++) {
                    result[i] = source_array[i];
                }
                return result;
            }
        public:
            City(const Position &mPosition, std::string* mPOIs, int mNumberOfPOIs);
            const std::string &getName() const;
            int getX() const;
            int getY() const;
            // jede Stadt hat Sehenswürdigkeiten (Points of Interest), auf die man zugreifen kann
            std::string getPOI(int i) const;
            // jede Stadt hat Sehenswürdigkeiten (Points of Interest), die man ändern kann
            void setPOI(int i, const std::string &poi);
            // es gibt je Stadt eine bestimmte Zahl an Sehenswürdigkeiten.
            int getNumberOfPOIs() const;
    };

}// namespace nan

#endif//BLATT3_CITY_H
