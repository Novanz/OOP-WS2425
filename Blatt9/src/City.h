//
// Created by nan on 10/29/24.
//

#ifndef BLATT3_CITY_H
#define BLATT3_CITY_H

#include "Position.h"
#include <stdexcept>
#include <ostream>

namespace nan {

    class City {
    private:
        nan::Position m_position;
        int m_number_of_pois;
        std::string *m_pois;

        static std::string *make_copy(const std::string *source_array, int size) {
            if (source_array == nullptr && size != 0) { throw std::invalid_argument("Size of nullptr array is not 0"); }
            auto *result = new std::string[size];
            for (int i = 0; i < size; i++) { result[i] = source_array[i]; }
            return result;
        }

        // Method to find number of POI occurrences
        int findAndCountPOI(const std::string &poi) const;

        City(const Position &mPosition, std::string *mPOIs, int mNumberOfPOIs);

        const std::string &getPOI(int i) const;
        void setPOI(int i, const std::string &poi);

    public:
        City(const std::string &name, int x, int y, std::string *pois = nullptr, int length = 0);
        City(const nan::City &other);
        ~City();
        const std::string &getName() const;
        int getX() const;
        int getY() const;
        int getNumberOfPOIs() const;
        void isValidIndex(int i) const;
        void addPOI(const std::string &poi);
        bool removePOI(const std::string &poi);
        friend std::ostream &operator<<(std::ostream &os, const City &city);
        // Important to implement const and non-const version of operator[] to handle const and non-const objects
        const std::string &operator[](int index) const;
        std::string &operator[](int index);
        // As we already provide copyctor and dtor, we should also provide copy assignment operator
        City &operator=(const City &other);
    };

}// namespace nan

#endif//BLATT3_CITY_H
