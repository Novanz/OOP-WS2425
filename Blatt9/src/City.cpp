//
// Created by novan on 10/29/24.
//

#include "City.h"
#include "Position.h"
#include <stdexcept>
#include <string>

novan::City::City(const novan::Position &mPosition, std::string *mPOIs, int mNumberOfPOIs)
    : m_position(mPosition), m_number_of_pois(mNumberOfPOIs), m_pois(make_copy(mPOIs, mNumberOfPOIs)) {}

novan::City::City(const std::string &name, int x, int y, std::string *pois, int length)
    : City(Position(name, x, y), pois, length) {}

novan::City::City(const novan::City &other)
    : City(other.m_position, other.m_pois.get(), other.m_number_of_pois) {}

const std::string &novan::City::getName() const { return m_position.getName(); }
int novan::City::getX() const { return m_position.getX(); }
int novan::City::getY() const { return m_position.getY(); }
void novan::City::isValidIndex(int i) const { if (i < 0 || i >= m_number_of_pois) { throw std::out_of_range("Array index out of bounds"); } }


const std::string &novan::City::getPOI(int i) const {
    isValidIndex(i);
    return m_pois[i];
}

void novan::City::setPOI(int i, const std::string &poi) {
    isValidIndex(i);
    m_pois[i] = poi;
}

int novan::City::getNumberOfPOIs() const { return m_number_of_pois; }

void novan::City::addPOI(const std::string &poi) {
    auto new_pois = std::make_unique<std::string[]>(m_number_of_pois + 1);
    for (int i = 0; i < m_number_of_pois; i++) { new_pois[i] = m_pois[i]; }
    new_pois[m_number_of_pois] = poi;
    m_pois = std::move(new_pois);
    m_number_of_pois++;
}

int novan::City::findAndCountPOI(const std::string &poi) const {
    int count = 0;
    for (int i = 0; i < m_number_of_pois; i++) { if (m_pois[i] == poi) { count++; } }
    return count;
}


bool novan::City::removePOI(const std::string &poi) {
    int number_of_occurrences = findAndCountPOI(poi);
    if (number_of_occurrences == 0) { return false; }
    auto new_pois = std::make_unique<std::string[]>(m_number_of_pois - number_of_occurrences);
    int j = 0;
    for (int i = 0; i < m_number_of_pois; i++) {
        if (m_pois[i] != poi) {
            new_pois[j] = m_pois[i];
            j++;
        }
    }
    m_pois = std::move(new_pois);
    m_number_of_pois -= number_of_occurrences;
    return true;
}

std::ostream &novan::operator<<(std::ostream &os, const City &city) {
    os << city.m_position;
    for (int i = 0; i < city.getNumberOfPOIs(); i++) { os << (city.getPOI(i)) << std::endl; }
    os << std::endl;
    return os;
}

const std::string &novan::City::operator[](int index) const {
    isValidIndex(index);
    return m_pois[index];
}

std::string &novan::City::operator[](int index) {
    isValidIndex(index);
    return m_pois[index];
}
// See: Operators(p.50)
novan::City &novan::City::operator=(const City &other) {
    if (this == &other) { return *this; }
    m_position = other.m_position;
    m_number_of_pois = other.m_number_of_pois;
    // To avoid issue of working with same array -> deep copy
    auto new_pois = std::make_unique<std::string[]>(m_number_of_pois);
    for (int i = 0; i < m_number_of_pois; i++) {
        new_pois[i] = other.getPOI(i);
    }
    m_pois = std::move(new_pois);
    return *this;
}