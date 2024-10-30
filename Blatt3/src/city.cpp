//
// Created by nan on 10/29/24.
//

#include "city.h"
#include "Position.h"
#include <stdexcept>
#include <string>


nan::City::City(const nan::Position &mPosition, std::string *mPOIs, int mNumberOfPOIs)
    : m_position(mPosition), m_number_of_pois(mNumberOfPOIs), m_pois(make_copy(mPOIs, mNumberOfPOIs)) {}

const std::string &nan::City::getName() const {
    return m_position.getName();
}
int nan::City::getX() const {
    return m_position.getX();
}
int nan::City::getY() const {
    return m_position.getY();
}
std::string nan::City::getPOI(int i) const {
    if (i < 0 || i >= m_number_of_pois) {
        throw std::out_of_range("Array index out of bounds");
    }
    return m_pois[i];
}
void nan::City::setPOI(int i, const std::string &poi) {
    if (i < 0 || i >= m_number_of_pois) {
        throw std::out_of_range("Array index out of bounds");
    }
    m_pois[i] = poi;
}
int nan::City::getNumberOfPOIs() const {
    return m_number_of_pois;
}
