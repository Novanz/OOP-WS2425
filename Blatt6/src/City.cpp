//
// Created by nan on 10/29/24.
//

#include "City.h"
#include "Position.h"
#include <stdexcept>
#include <string>


nan::City::City(const nan::Position &mPosition, std::string *mPOIs, int mNumberOfPOIs)
    : m_position(mPosition), m_number_of_pois(mNumberOfPOIs), m_pois(make_copy(mPOIs, mNumberOfPOIs)) {}

nan::City::City(const std::string &name, int x, int y, std::string *pois, int length)
    : City(Position(name, x, y),pois, length){}

nan::City::City(const nan::City &other)
    : City(other.m_position, other.m_pois, other.m_number_of_pois){}

nan::City::~City() {
    delete[] m_pois;
    m_pois = nullptr;
}

const std::string &nan::City::getName() const {
    return m_position.getName();
}
int nan::City::getX() const {
    return m_position.getX();
}
int nan::City::getY() const {
    return m_position.getY();
}
void nan::City::isValidIndex(int i) const {
    if (i < 0 || i >= m_number_of_pois) {
        throw std::out_of_range("Array index out of bounds");
    }
}

void nan::City::addPOI(const std::string &poi) {
    auto *new_pois = new std::string[m_number_of_pois + 1];
    for (int i = 0; i < m_number_of_pois; i++) {
        new_pois[i] = m_pois[i];
    }
    new_pois[m_number_of_pois] = poi;
    delete[] m_pois;
    m_pois = new_pois;
    m_number_of_pois++;
}

const std::string &nan::City::getPOI(int i) const {
    isValidIndex(i);
    return m_pois[i];
}
void nan::City::setPOI(int i, const std::string &poi) {
    isValidIndex(i);
    m_pois[i] = poi;
}
int nan::City::getNumberOfPOIs() const {
    return m_number_of_pois;
}

